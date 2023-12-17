/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostin <acostin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:12:51 by acostin           #+#    #+#             */
/*   Updated: 2023/12/16 04:19:26 by acostin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minirt.h"

t_ray init_ray(t_vec3 origin, t_vec3 direction) 
{
	t_ray r;

	r.origin = origin;
	r.direction = direction;
	return (r);
}

// Find point on a ray given t
t_vec3 point_on_ray(t_ray r, float t) 
{
	t_vec3 point;

	point.x = r.origin.x + t * r.direction.x;
	point.y = r.origin.y + t * r.direction.y;
	point.z = r.origin.z + t * r.direction.z;

	return (point);
}

// Intersect ray with a sphere
void intersect_ray_sphere(t_ray r, t_obj sphere, float *t1, float *t2)
{
	t_vec3 co;
	float var[3];
	float discriminant;

	co = vec3_subtract(r.origin, sphere.center);

	var[0] = vec3_dot(r.direction, r.direction);
	var[1] = 2 * vec3_dot(co, r.direction);
	var[2] = vec3_dot(co, co) - sphere.radius * sphere.radius;

	discriminant = (var[1] * var[1]) - (4 * var[0] * var[2]);
	if (discriminant < 0) 
	{
		*t1 = INFINITY;
		*t2 = INFINITY;
		return;
	}
	*t1 = (-var[1] + sqrt(discriminant)) / (2 * var[0]);
	*t2 = (-var[1] - sqrt(discriminant)) / (2 * var[0]);
}

t_obj	*find_closest_obj_for_ray(t_ray r, t_scene *scene, float *closest_t)
{
    t_obj *closest_obj;
    float t[2];				// t values for intersection
	float clips[2];      	// min and max t values (clipping viewing)
    int i;

	clips[0] = 1.0;
	clips[1] = INFINITY;
	i = 0;
	closest_obj = NULL;
	// while (i < scene->num_spheres + scene->num_planes + scene->num_cylinder)
    while (i < scene->num_spheres)
	{
		if (scene->obj[i].type == SPHERE)
       		intersect_ray_sphere(r, scene->obj[i], &t[0], &t[1]);
		// else if (scene->obj[i].type == PLANE)
		// 	//
		// else if (scene->obj[i].type == CYLINDER)
		// 	//
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

t_rgb trace_ray(t_ray r, t_scene scene) 
{
	t_rgb       diffuse_reflection_color;
	t_vec3      point_intersec;
	t_vec3      normal_surface_intersec;
	float       closest_t;
	t_obj    	*closest_obj;

	closest_t = INFINITY;

	closest_obj = find_closest_obj_for_ray(r, &scene, &closest_t);

	if (closest_obj == NULL)
		return ((t_rgb){0, 0, 0}); // Background color (black for now)

	// Calculate the point of intersection
	point_intersec = vec3_add(r.origin, vec3_mult_scalar(r.direction, closest_t));

	// Calculate the normal to the surface at the intersection point
	normal_surface_intersec = vec3_subtract(point_intersec, closest_obj->center);
	vec3_normalize(&normal_surface_intersec);

	// Compute the color at the intersection point with lighting
	diffuse_reflection_color = compute_lighting(point_intersec, normal_surface_intersec, closest_obj, scene);

	return (diffuse_reflection_color);
}
