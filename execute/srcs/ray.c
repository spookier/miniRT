/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:12:51 by acostin           #+#    #+#             */
/*   Updated: 2023/12/18 02:43:43 by yhwang           ###   ########.fr       */
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

void intersect_ray_plane(t_ray r, t_obj plane, float *t1, float *t2)
{
	t_vec3 rc;
	float dot_n_d;
	float dot_n_rc;

	rc = vec3_subtract(plane.center, r.origin);
	dot_n_d = vec3_dot(plane.xyz_vec, r.direction);
	if (dot_n_d == 0)
	{
		*t1 = INFINITY;
		*t2 = INFINITY;
		return;
	}
	dot_n_rc = vec3_dot(plane.xyz_vec, rc);
	*t1 = dot_n_rc / dot_n_d;
	*t2 = dot_n_rc / dot_n_d + 0.0001;
	if (*t1 < 0.0001 || *t2 < 0.0001)
	{
		*t1 = INFINITY;
		*t2 = INFINITY;
		return;
	}
}

void get_cylinder_centers(t_obj cylinder, t_vec3 *cy_center)
{
	float delta;

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
	t_vec3 rc;
	float dot_n_d;
	float dot_n_rc;
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
	float t_body;

	intersect_ray_cylinder_body_norm(r, cylinder, &t_body);
	if (t_body == INFINITY)
		return (INFINITY);
	if (vec3_dot(vec3_subtract(vec3_add(r.origin, vec3_mult_scalar(r.direction, t_body)), cy_center[TOP]), cylinder.xyz_vec) > 0
		|| vec3_dot(vec3_subtract(vec3_add(r.origin, vec3_mult_scalar(r.direction, t_body)), cy_center[BOTTOM]), cylinder.xyz_vec) < 0)
		return (INFINITY);
	return (t_body);
}

int check_cylinder_circle_radius(t_obj cylinder, t_vec3 hit_p, t_vec3 cy_center)
{
	float res;
	float radius;

	res = sqrt(vec3_dot(vec3_subtract(hit_p, cy_center), vec3_subtract(hit_p, cy_center)));
	radius = cylinder.radius;
	if (res > radius)
		return (-1);
	return (0);
}

float intersect_ray_cylinder_circle_norm(float *t_circle)
{
	if (t_circle[TOP] < t_circle[BOTTOM])
		return (t_circle[TOP]);
	return (t_circle[BOTTOM]);
}

float	intersect_ray_cylinder_circle(t_ray r, t_obj cylinder, t_vec3 *cy_center)
{
	t_vec3 tc[2];
	float dot[3];
	t_vec3 hit_p[2];
	float t_circle[2];

	tc[TOP] = vec3_subtract(cy_center[TOP], r.origin);
	tc[BOTTOM] = vec3_subtract(cy_center[BOTTOM], r.origin);
	dot[0] = vec3_dot(cylinder.xyz_vec, r.direction);
	if (dot == 0)
		return (INFINITY);
	dot[1] = vec3_dot(cylinder.xyz_vec, tc[TOP]);
	dot[2] = vec3_dot(cylinder.xyz_vec, tc[BOTTOM]);
	t_circle[TOP] = dot[1] / dot[0];
	t_circle[BOTTOM] = dot[2] / dot[0];
	if (t_circle[TOP] < 0.0001)
		t_circle[TOP] = INFINITY;
	if (t_circle[BOTTOM] < 0.0001)
		t_circle[BOTTOM] = INFINITY;
	hit_p[TOP] = vec3_add(r.origin, vec3_mult_scalar(r.direction, t_circle[TOP]));
	hit_p[BOTTOM] = vec3_add(r.origin, vec3_mult_scalar(r.direction, t_circle[BOTTOM]));
	if (check_cylinder_circle_radius(cylinder, hit_p[TOP], cy_center[TOP]) == -1)
		t_circle[TOP] = INFINITY;
	if (check_cylinder_circle_radius(cylinder, hit_p[BOTTOM], cy_center[BOTTOM]) == -1)
		t_circle[BOTTOM] = INFINITY;
	return (intersect_ray_cylinder_circle_norm(t_circle));
}

t_vec3	get_surface_normal_cylider_body(t_ray r, t_obj cylinder, float t_body)
{
	t_vec3	hit_p;
	t_vec3	c_p;
	t_vec3	proj_c_p;
	t_vec3	res;

	hit_p = vec3_add(r.origin, vec3_mult_scalar(r.direction, t_body));
	c_p = vec3_subtract(hit_p, cylinder.center);
	proj_c_p = vec3_mult_scalar(cylinder.xyz_vec, (vec3_dot(cylinder.xyz_vec, c_p)
			/ vec3_dot(cylinder.xyz_vec, cylinder.xyz_vec)));
	res = vec3_subtract(hit_p, vec3_add(cylinder.center, proj_c_p));
	return (res);
}

void	intersect_ray_cylinder(t_ray r, t_obj cylinder, float *t, t_vec3 *surface_normal)
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
	if (surface_normal== NULL)
		return ;
	if (temp[0] < temp[1])
		*surface_normal = get_surface_normal_cylider_body(r, cylinder, temp[0]);
	else
		*surface_normal = cylinder.xyz_vec;
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
    while (i < scene->num_spheres + scene->num_planes + scene->num_cylinder)
	{
		if (scene->obj[i].type == SPHERE)
       		intersect_ray_sphere(r, scene->obj[i], &t[0], &t[1]);
		else if (scene->obj[i].type == PLANE)
			intersect_ray_plane(r, scene->obj[i], &t[0], &t[1]);
		else if (scene->obj[i].type == CYLINDER)
			intersect_ray_cylinder(r, scene->obj[i], t, NULL);

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
	if (closest_obj->type == SPHERE)
		normal_surface_intersec = vec3_subtract(point_intersec, closest_obj->center);	
	else if (closest_obj->type == PLANE)
		normal_surface_intersec = closest_obj->xyz_vec;
	else if (closest_obj->type == CYLINDER)
		intersect_ray_cylinder(r, *closest_obj, NULL, &normal_surface_intersec);

	vec3_normalize(&normal_surface_intersec);
	// Compute the color at the intersection point with lighting
	diffuse_reflection_color = compute_lighting(point_intersec, normal_surface_intersec, closest_obj, scene);

	return (diffuse_reflection_color);
}
