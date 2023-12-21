/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cam_vec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 08:54:39 by yhwang            #+#    #+#             */
/*   Updated: 2023/12/21 00:55:41 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minirt.h"

t_matrix3	get_metrix(float angle, char flag)
{
	t_matrix3	res;

	res = matrix3(vec3(0, 0, 0), vec3(0, 0, 0), vec3(0, 0, 0));
	if (flag == 'x')
		res = matrix3(vec3(1, 0, 0), vec3(0, cos(angle), sin(angle)),
				vec3(0, -1 * sin(angle), cos(angle)));
	else if (flag == 'y')
		res = matrix3(vec3(cos(angle), 0, -1 * sin(angle)),
				vec3(0, 1, 0), vec3(sin(angle), 0, cos(angle)));
	else if (flag == 'z')
		res = matrix3(vec3(cos(angle), sin(angle), 0),
				vec3(-1 * sin(angle), cos(angle), 0), vec3(0, 0, 1));
	return (res);
}

void	rotate_obj(t_obj *obj, t_matrix3 m)
{
	obj->center = matrix_mul(m, obj->center);
		obj->xyz_vec = matrix_mul(m, obj->xyz_vec);
		obj->center = vec3_add(obj->center,
				vec3_mult_scalar(obj->xyz_vec, DELTA));
}

void	rotate_scene(t_scene *scene, t_camera *cam, float angle, char flag)
{
	t_matrix3	m;
	int			i;

	if (flag == 'x')
		m = get_metrix(angle, 'x');
	else if (flag == 'y')
		m = get_metrix(angle, 'y');
	else if (flag == 'z')
		m = get_metrix(angle, 'z');
	i = -1;
	while (++i < scene->num_spheres + scene->num_planes + scene->num_cylinder)
		rotate_obj(&scene->obj[i], m);
	scene->light.position = matrix_mul(m, scene->light.position);
	if (flag == 'x')
		m = get_metrix(angle, 'x');
	else if (flag == 'y')
		m = get_metrix(-1 * angle, 'y');
	else
		m = get_metrix(angle, 'z');
	cam->origin = matrix_mul(m, cam->origin);
	cam->origin = vec3_add(cam->origin,
			vec3_mult_scalar(cam->direction, DELTA));
}

void	set_cam_vec(t_all *all)
{
	if (all->cam.direction.x == 0
		&& all->cam.direction.y == 0 && all->cam.direction.z == -1)
		rotate_scene(&all->scene, &all->cam, PI, 'y');
	else if (all->cam.direction.x == -1
		&& all->cam.direction.y == 0 && all->cam.direction.z == 0)
		rotate_scene(&all->scene, &all->cam, 3 * PI / 2, 'y');
	else if (all->cam.direction.x == 1
		&& all->cam.direction.y == 0 && all->cam.direction.z == 0)
		rotate_scene(&all->scene, &all->cam, PI / 2, 'y');
	else if (all->cam.direction.x == 0
		&& all->cam.direction.y == -1 && all->cam.direction.z == 0)
		rotate_scene(&all->scene, &all->cam, 3 * PI / 2, 'x');
	else if (all->cam.direction.x == 0
		&& all->cam.direction.y == 1 && all->cam.direction.z == 0)
		rotate_scene(&all->scene, &all->cam, PI / 2, 'x');
}
