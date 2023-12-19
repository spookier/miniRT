/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cy_body.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 00:45:19 by yhwang            #+#    #+#             */
/*   Updated: 2023/12/19 00:45:20 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minirt.h"

void	get_cylinder_centers(t_obj cylinder, t_vec3 *cy_center)
{
	float	delta;

	delta = cylinder.height / 2
		* sqrt(1 / (cylinder.xyz_vec.x * cylinder.xyz_vec.x
				+ cylinder.xyz_vec.y * cylinder.xyz_vec.y
				+ cylinder.xyz_vec.z * cylinder.xyz_vec.z));
	cy_center[TOP]
		= vec3(cylinder.center.x + delta * cylinder.xyz_vec.x,
			cylinder.center.y + delta * cylinder.xyz_vec.y,
			cylinder.center.z + delta * cylinder.xyz_vec.z);
	cy_center[BOTTOM]
		= vec3(cylinder.center.x - delta * cylinder.xyz_vec.x,
			cylinder.center.y - delta * cylinder.xyz_vec.y,
			cylinder.center.z - delta * cylinder.xyz_vec.z);
}

void	intersect_ray_cylinder_body_norm(t_ray r, t_obj cylinder, float *t_body)
{
	t_vec3	rc;
	float	dot_n_d;
	float	dot_n_rc;
	float	d[3];

	rc = vec3_subtract(cylinder.center, r.origin);
	dot_n_d = vec3_dot(r.direction, cylinder.xyz_vec);
	dot_n_rc = vec3_dot(rc, cylinder.xyz_vec);
	d[0] = vec3_dot(r.direction, r.direction) - dot_n_d * dot_n_d;
	d[1] = -1 * (vec3_dot(rc, r.direction) - dot_n_d * dot_n_rc);
	d[2] = vec3_dot(rc, rc) - dot_n_rc * dot_n_rc
		- cylinder.radius * cylinder.radius;
	if (d[1] * d[1] - d[0] * d[2] < 0)
	{
		*t_body = INFINITY;
		return ;
	}
	*t_body = (-1 * d[1] - sqrt(d[1] * d[1] - d[0] * d[2])) / d[0];
	if (*t_body < 0.0001)
	{
		*t_body = (-1 * d[1] + sqrt(d[1] * d[1] - d[0] * d[2])) / d[0];
		if (*t_body < 0.0001)
			*t_body = INFINITY;
	}
}

float	intersect_ray_cylinder_body(t_ray r, t_obj cylinder, t_vec3 *cy_center)
{
	float	t_body;

	intersect_ray_cylinder_body_norm(r, cylinder, &t_body);
	if (t_body == INFINITY)
		return (INFINITY);
	if (vec3_dot(vec3_subtract(vec3_add(r.origin,
					vec3_mult_scalar(r.direction, t_body)), cy_center[TOP]),
			cylinder.xyz_vec) > 0
		|| vec3_dot(vec3_subtract(vec3_add(r.origin,
					vec3_mult_scalar(r.direction, t_body)), cy_center[BOTTOM]),
			cylinder.xyz_vec) < 0)
		return (INFINITY);
	return (t_body);
}

t_vec3	get_surface_normal_cylider_body(t_ray r, t_obj cylinder, float t_body)
{
	t_vec3	hit_p;
	t_vec3	c_p;
	t_vec3	proj_c_p;
	t_vec3	res;

	hit_p = vec3_add(r.origin, vec3_mult_scalar(r.direction, t_body));
	c_p = vec3_subtract(hit_p, cylinder.center);
	proj_c_p = vec3_mult_scalar(cylinder.xyz_vec,
			(vec3_dot(cylinder.xyz_vec, c_p)
				/ vec3_dot(cylinder.xyz_vec, cylinder.xyz_vec)));
	res = vec3_subtract(hit_p, vec3_add(cylinder.center, proj_c_p));
	return (res);
}

void	intersect_ray_cylinder(t_ray r,
			t_obj cylinder, float *t, t_vec3 *surface_normal)
{
	t_vec3	cy_center[2];
	float	temp[2];

	get_cylinder_centers(cylinder, cy_center);
	temp[0] = intersect_ray_cylinder_body(r, cylinder, cy_center);
	temp[1] = intersect_ray_cylinder_circle(r, cylinder, cy_center);
	if (t)
	{
		t[0] = temp[0];
		t[1] = temp[1];
	}
	if (surface_normal == NULL)
		return ;
	if (temp[0] < temp[1])
		*surface_normal = get_surface_normal_cylider_body(r, cylinder, temp[0]);
	else
		*surface_normal = cylinder.xyz_vec;
}
