/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cam_vec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 08:54:39 by yhwang            #+#    #+#             */
/*   Updated: 2023/12/19 10:07:08 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minirt.h"

void	cam_vec_0_0_1(t_scene *scene, t_camera *cam)
{
	double		val_cos;
	double		val_sin;
	t_matrix3	m;
	int			i;

	val_cos = cos(PI);
	val_sin = sin(PI);
	m = matrix3(vec3(val_cos, 0, -1 * val_sin),
			vec3(0, 1, 0), vec3(val_sin, 0, val_cos));
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

void	set_cam_vec(t_all *all)
{
	if (all->cam.direction.x == 0
		&& all->cam.direction.y == 0 && all->cam.direction.z == 1)
		cam_vec_0_0_1(&all->scene, &all->cam);
}
