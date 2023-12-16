/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostin <acostin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:28:10 by acostin           #+#    #+#             */
/*   Updated: 2023/12/15 23:24:04 by acostin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minirt.h"

t_ambient	ambient_create(int color, float intensity)
{
	t_ambient	ambient;

	ambient.color = color;
	ambient.intensity = intensity;
	return (ambient);
}

t_light	light_create(t_vec3 position, int color, float intensity)
{
	t_light	light;

	light.position.x = position.x;
	light.position.y = position.y;
	light.position.z = position.z;
	light.color = color;
	light.intensity = intensity;
	return (light);
}

int is_in_shadow(t_vec3 P, t_vec3 light_direction, float light_distance, t_scene scene)
{
	int i;
    t_ray shadow_ray;
    float t1;
	float t2;
	
    // Create a shadow ray
    shadow_ray.origin = P;
    shadow_ray.direction = light_direction;

	i = 0;
	while (i < scene.num_spheres)
	{
		intersect_ray_sphere(shadow_ray, scene.spheres[i], &t1, &t2);
		if ((t1 < light_distance && t1 > 0.001) || (t2 < light_distance && t2 > 0.001))
			return (1);
		i++;
	}
    return (0);
}

t_rgb	compute_lighting(t_vec3 P, t_vec3 N, t_sphere *sphere, t_scene scene)
{
	t_vec3	light_direction;
	float	diffuse_intensity;			// Initialize diffuse_intensity
	t_rgb	color;
	t_rgb	ambient_color; 				// Initialize ambient_color to zero

	diffuse_intensity = 0.0;
	ambient_color = create_rgb(0, 0, 0);

	ambient_color.r += (sphere->color.r) * scene.light.intensity;
	ambient_color.g += (sphere->color.g) * scene.light.intensity;
	ambient_color.b += (sphere->color.b) * scene.light.intensity;

	light_direction = vec3_subtract(scene.light.position, P);
	vec3_normalize(&light_direction);
	
	// SHADOW!
	// ---------
	t_vec3 to_light = vec3_subtract(scene.light.position, P);
    float light_distance = vec3_length(to_light);
    vec3_normalize(&to_light);

    // Check if the point is in shadow
    if (!is_in_shadow(P, to_light, light_distance, scene))
	{
        diffuse_intensity += scene.light.intensity * fmax(0.0, vec3_dot(N , to_light));
    }

	// Apply the diffuse lighting to the sphere's color and add the ambient component
	color = create_rgb(
		fmin(255, (sphere->color.r * diffuse_intensity) + ambient_color.r),
		fmin(255, (sphere->color.g * diffuse_intensity) + ambient_color.g),
		fmin(255, (sphere->color.b * diffuse_intensity) + ambient_color.b)
	);

	return (color);
}
