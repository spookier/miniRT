/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cam_vec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 08:54:39 by yhwang            #+#    #+#             */
/*   Updated: 2023/12/19 12:28:25 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minirt.h"

void	rotate_scene(t_scene *scene, t_camera *cam, t_matrix3 m)
{
	int	i;
	
	i = -1;
	while (++i < scene->num_spheres + scene->num_planes + scene->num_cylinder)
	{
		scene->obj[i].center = matrix_mul(m, scene->obj[i].center);
		scene->obj[i].xyz_vec = matrix_mul(m, scene->obj[i].xyz_vec);
		scene->obj[i].center = vec3_add(scene->obj[i].center,
				vec3_mult_scalar(scene->obj[i].xyz_vec, DELTA));
	}
	scene->light.position = matrix_mul(m, scene->light.position);
	cam->origin = matrix_mul(m, cam->origin);
}

void	rotate_y_axis(t_scene *scene, t_camera *cam)
{
	t_matrix3	m;

	if (cam->direction.x == 0
		&& cam->direction.y == 0 && cam->direction.z == 1)
		m = matrix3(vec3(cos(PI), 0, -1 * sin(PI)),
			vec3(0, 1, 0), vec3(sin(PI), 0, cos(PI)));
	else if (cam->direction.x == -1
		&& cam->direction.y == 0 && cam->direction.z == 0)
		m = matrix3(vec3(cos(PI / 2), 0, -1 * sin(PI / 2)),
			vec3(0, 1, 0), vec3(sin(PI / 2), 0, cos(PI / 2)));
	else if (cam->direction.x == 1
		&& cam->direction.y == 0 && cam->direction.z == 0)
		m = matrix3(vec3(cos(3 * PI / 2), 0, -1 * sin(3 * PI / 2)),
			vec3(0, 1, 0), vec3(sin(3 * PI / 2), 0, cos(3 * PI / 2)));
	rotate_scene(scene, cam, m);
}

void	rotate_x_axis(t_scene *scene, t_camera *cam)
{
	t_matrix3	m;

	if (cam->direction.x == 0
		&& cam->direction.y == -1 && cam->direction.z == 0)
		m = matrix3(vec3(1, 0, 0), vec3(0, cos(3 * PI / 2), sin(3 * PI / 2)),
			vec3(0, -1 * sin(3 * PI / 2), cos(3 * PI / 2)));
	else if (cam->direction.x == 0
		&& cam->direction.y == 1 && cam->direction.z == 0)
		m = matrix3(vec3(1, 0, 0), vec3(0, cos(PI / 2), sin(PI / 2)),
			vec3(0, -1 * sin(PI / 2), cos(PI / 2)));
	rotate_scene(scene, cam, m);
}

// void	rotate_x_y_axis(t_scene *scene, t_camera *cam)
// {
// 	t_matrix3	m;
// 	float		val_cos;
// 	float		val_sin;

// 	val_cos = 
// }

void	set_cam_vec(t_all *all)
{
	if (all->cam.direction.x == 0
		&& all->cam.direction.y == 0 && all->cam.direction.z == 1)
		rotate_y_axis(&all->scene, &all->cam);
	else if (all->cam.direction.x == -1
		&& all->cam.direction.y == 0 && all->cam.direction.z == 0)
		rotate_y_axis(&all->scene, &all->cam);
	else if (all->cam.direction.x == 1
		&& all->cam.direction.y == 0 && all->cam.direction.z == 0)
		rotate_y_axis(&all->scene, &all->cam);
	else if (all->cam.direction.x == 0
		&& all->cam.direction.y == -1 && all->cam.direction.z == 0)
		rotate_x_axis(&all->scene, &all->cam);
	else if (all->cam.direction.x == 0
		&& all->cam.direction.y == 1 && all->cam.direction.z == 0)
		rotate_x_axis(&all->scene, &all->cam);
// 	else
// 		rotate_x_y_axis(&all->scene, &all->cam);
}
