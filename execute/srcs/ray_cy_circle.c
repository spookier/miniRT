/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cy_circle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 00:45:21 by yhwang            #+#    #+#             */
/*   Updated: 2023/12/20 14:44:28 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minirt.h"

int	check_cylinder_circle_radius(t_obj cylinder, t_vec3 hit_p, t_vec3 cy_center)
{
	float	res;
	float	radius;

	res = sqrt(vec3_dot(vec3_subtract(hit_p, cy_center),
				vec3_subtract(hit_p, cy_center)));
	radius = cylinder.radius;
	if (res >= radius)
		return (-1);
	return (0);
}

float	intersect_ray_cylinder_circle_norm(t_obj cylinder,
			t_vec3 *cy_center, t_vec3 *hit_p, float *t_circle)
{
	if (check_cylinder_circle_radius(cylinder,
			hit_p[TOP], cy_center[TOP]) == -1)
		t_circle[TOP] = INFINITY;
	if (check_cylinder_circle_radius(cylinder,
			hit_p[BOTTOM], cy_center[BOTTOM]) == -1)
		t_circle[BOTTOM] = INFINITY;
	if (t_circle[TOP] < t_circle[BOTTOM])
		return (t_circle[TOP]);
	return (t_circle[BOTTOM]);
}

float	intersect_ray_cylinder_circle(t_ray r,
			t_obj cylinder, t_vec3 *cy_center)
{
	t_vec3	tc[2];
	float	dot[3];
	t_vec3	hit_p[2];
	float	t_circle[2];

	tc[TOP] = vec3_subtract(cy_center[TOP], r.origin);
	tc[BOTTOM] = vec3_subtract(cy_center[BOTTOM], r.origin);
	dot[0] = vec3_dot(cylinder.xyz_vec, r.direction);
	if (dot[0] == 0)
		return (INFINITY);
	dot[1] = vec3_dot(cylinder.xyz_vec, tc[TOP]);
	dot[2] = vec3_dot(cylinder.xyz_vec, tc[BOTTOM]);
	t_circle[TOP] = dot[1] / dot[0];
	t_circle[BOTTOM] = dot[2] / dot[0];
	if (t_circle[TOP] < 0.0001)
		t_circle[TOP] = INFINITY;
	if (t_circle[BOTTOM] < 0.0001)
		t_circle[BOTTOM] = INFINITY;
	hit_p[TOP] = vec3_add(r.origin,
			vec3_mult_scalar(r.direction, t_circle[TOP]));
	hit_p[BOTTOM] = vec3_add(r.origin,
			vec3_mult_scalar(r.direction, t_circle[BOTTOM]));
	return (intersect_ray_cylinder_circle_norm(cylinder,
			cy_center, hit_p, t_circle));
}
