/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:12:51 by acostin           #+#    #+#             */
/*   Updated: 2023/12/19 00:47:52 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minirt.h"

t_ray	init_ray(t_vec3 origin, t_vec3 direction)
{
	t_ray	r;

	r.origin = origin;
	r.direction = direction;
	return (r);
}

// Find point on a ray given t
t_vec3	point_on_ray(t_ray r, float t)
{
	t_vec3	point;

	point.x = r.origin.x + t * r.direction.x;
	point.y = r.origin.y + t * r.direction.y;
	point.z = r.origin.z + t * r.direction.z;
	return (point);
}

static void	intersect_ray_objs(t_ray r, t_obj obj, float *t)
{
	if (obj.type == SPHERE)
		intersect_ray_sphere(r, obj, &t[0], &t[1]);
	else if (obj.type == PLANE)
		intersect_ray_plane(r, obj, &t[0], &t[1]);
	else if (obj.type == CYLINDER)
		intersect_ray_cylinder(r, obj, t, NULL);
}

t_obj	*find_closest_obj_for_ray(t_ray r, t_scene *scene, float *closest_t)
{
	t_obj	*closest_obj;
	float	t[2];
	float	clips[2];
	int		i;

	clips[0] = 1.0;
	clips[1] = INFINITY;
	i = 0;
	closest_obj = NULL;
	while (i < scene->num_spheres + scene->num_planes + scene->num_cylinder)
	{
		intersect_ray_objs(r, scene->obj[i], t);
		if (t[0] >= clips[0] && t[0] <= clips[1] && t[0] < *closest_t)
		{
			*closest_t = t[0];
			closest_obj = &scene->obj[i];
		}
		if (t[1] >= clips[0] && t[1] <= clips[1] && t[1] < *closest_t)
		{
			*closest_t = t[1];
			closest_obj = &scene->obj[i];
		}
		i++;
	}
	return (closest_obj);
}

t_rgb	trace_ray(t_ray r, t_scene scene)
{
	t_rgb	diffuse_reflection_color;
	t_vec3	point_intersec;
	t_vec3	normal_surface_intersec;
	float	closest_t;
	t_obj	*closest_obj;

	closest_t = INFINITY;
	closest_obj = find_closest_obj_for_ray(r, &scene, &closest_t);
	if (closest_obj == NULL)
		return ((t_rgb){0, 0, 0});
	point_intersec = vec3_add(r.origin,
			vec3_mult_scalar(r.direction, closest_t));
	if (closest_obj->type == SPHERE)
		normal_surface_intersec = vec3_subtract(point_intersec,
				closest_obj->center);
	else if (closest_obj->type == PLANE)
		normal_surface_intersec = closest_obj->xyz_vec;
	else if (closest_obj->type == CYLINDER)
		intersect_ray_cylinder(r, *closest_obj, NULL, &normal_surface_intersec);
	vec3_normalize(&normal_surface_intersec);
	diffuse_reflection_color = compute_lighting(point_intersec,
			normal_surface_intersec, closest_obj, scene);
	return (diffuse_reflection_color);
}
