#include "../incs/minirt.h"

t_light light_create(t_light_type light_type ,t_vec3 position, int color, float intensity)
{
	t_light light;

    light.type = light_type;
	light.position.x = position.x;
	light.position.y = position.y;
	light.position.z = position.z;
	light.color = color;
	light.intensity = intensity;

	return(light);
}

t_rgb compute_lighting(t_vec3 P, t_vec3 N, t_sphere *sphere, t_scene scene) 
{
    t_vec3  L;
    float   diffuse_intensity = 0.0; // Initialize diffuse_intensity
    t_rgb   color;
    t_rgb   ambient_color = {0, 0, 0}; // Initialize ambient_color to zero
    int i;
    
    for (i = 0; i < scene.num_lights; i++) 
    {
        if (scene.lights[i].type == AMBIENT)
        {
            // Add the ambient light to the ambient_color
            ambient_color.r += (sphere->color.r) * scene.lights[i].intensity;
            ambient_color.g += (sphere->color.g) * scene.lights[i].intensity;
            ambient_color.b += (sphere->color.b) * scene.lights[i].intensity;
        }
        else if (scene.lights[i].type == DIFFUSE)
        {
            // Calculate diffuse lighting
            L = vec3_subtract(scene.lights[i].position, P);
            vec3_normalize(&L);
            // Accumulate diffuse intensity from all diffuse lights
            diffuse_intensity += scene.lights[i].intensity * fmax(0.0, vec3_dot(N, L));
        }
    }

    // Apply the diffuse lighting to the sphere's color and add the ambient component
    color = create_rgb(
        fmin(255, (sphere->color.r) * diffuse_intensity + ambient_color.r),
        fmin(255, (sphere->color.g) * diffuse_intensity + ambient_color.g),
        fmin(255, (sphere->color.b) * diffuse_intensity + ambient_color.b)
    );

    return (color);
}


// t_rgb compute_lighting(t_vec3 P, t_vec3 N, t_sphere *sphere, t_scene scene)
// {
//     t_vec3  L;
//     float   diffuse_intensity;
//     t_rgb   color;
//     //t_rgb   ambient_color;
//     int i;

//     i = 0;
//     while (i < scene.num_lights) 
//     {
//         if (scene.lights[i].type == AMBIENT)
//         {
//             scene.lights[i].color.r += sphere->color.r * scene.lights[i].intensity;
//             scene.lights[i].color.g += sphere->color.g * scene.lights[i].intensity;
//             scene.lights[i].color.b += sphere->color.b * scene.lights[i].intensity;
//         }
//         else if (scene.lights[i].type == DIFFUSE)
//         {
//             L = vec3_subtract(scene.lights[i].position, P);
//             vec3_normalize(&L);
//             diffuse_intensity = scene.lights[i].intensity * fmax(0.0, vec3_dot(N, L));
//         }
//         i++;
//     }

//  color = create_rgb(
//         fmin(255, scene.lights[i].color.r + sphere->color.r * diffuse_intensity),
//         fmin(255, scene.lights[i].color.g + sphere->color.g * diffuse_intensity),
//         fmin(255, scene.lights[i].color.b + sphere->color.b * diffuse_intensity)
//     );

//     return (color);
// }