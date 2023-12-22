/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_sp_pl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 00:45:16 by yhwang            #+#    #+#             */
/*   Updated: 2023/12/22 17:24:12 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minirt.h"

void	intersect_ray_sphere(t_ray r, t_obj sphere, float *t1, float *t2)
{
	t_vec3	co;
	float	var[3];
	float	discriminant;

	co = vec3_subtract(r.origin, sphere.center);
	var[0] = vec3_dot(r.direction, r.direction);
	var[1] = 2 * vec3_dot(co, r.direction);
	var[2] = vec3_dot(co, co) - sphere.radius * sphere.radius;
	discriminant = (var[1] * var[1]) - (4 * var[0] * var[2]);
	if (discriminant < 0)
	{
		*t1 = INFINITY;
		*t2 = INFINITY;
		return ;
	}
	*t1 = (-var[1] + sqrt(discriminant)) / (2 * var[0]);
	*t2 = (-var[1] - sqrt(discriminant)) / (2 * var[0]);
}

void	intersect_ray_plane(t_ray r, t_obj plane, float *t1, float *t2)
{
	t_vec3	rc;
	float	dot_n_d;
	float	dot_n_rc;

	rc = vec3_subtract(plane.center, r.origin);
	dot_n_d = vec3_dot(plane.xyz_vec, r.direction);
	if (dot_n_d == 0)
	{
		*t1 = INFINITY;
		*t2 = INFINITY;
		return ;
	}
	dot_n_rc = vec3_dot(plane.xyz_vec, rc);
	*t1 = dot_n_rc / dot_n_d;
	*t2 = dot_n_rc / dot_n_d;
	if (*t1 < 0.0001 || *t2 < 0.0001)
	{
		*t1 = INFINITY;
		*t2 = INFINITY;
		return ;
	}
}
