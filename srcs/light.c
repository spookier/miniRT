#include "../incs/minirt.h"

t_light light_create(t_vec3 position, int color, float intensity)
{
	t_light light;

	light.position.x = position.x;
	light.position.y = position.y;
	light.position.z = position.z;

	light.color = color;
	light.intensity = intensity;

	return(light);
}

t_rgb compute_lighting(t_vec3 P, t_vec3 N, t_sphere *sphere, t_light light)
{
    t_vec3 L;
    float diffuse_intensity;
    t_rgb color;

    // P is the intersection point, N is the normal at that point.
    L = vec3_subtract(light.position, P); // Vector from point P to the light
    vec3_normalize(&L);

    // Calculate the diffuse intensity
    diffuse_intensity = light.intensity * fmax(0.0, vec3_dot(N, L));

    color = create_rgb(
        fmin(255, sphere->color.r * diffuse_intensity),
        fmin(255, sphere->color.g * diffuse_intensity),
        fmin(255, sphere->color.b * diffuse_intensity)
		);

    return (color);
}