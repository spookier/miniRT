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
void intersect_ray_sphere(t_ray r, t_sphere sphere, float *t1, float *t2)
{
    t_vec3 CO;
    float var[3];
    float discriminant;

    CO = vec3_subtract(r.origin, sphere.center);

    var[0] = vec3_dot(r.direction, r.direction);
    var[1] = 2 * vec3_dot(CO, r.direction);
    var[2] = vec3_dot(CO, CO) - sphere.radius * sphere.radius;

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

int compute_lighting(t_vec3 P, t_vec3 N, t_scene scene, t_light light) 
{
    (void)scene;
    t_vec3 L;
    float diffuse_intensity;
    int rgb[3];
    int color;
    

    
    // P is the intersection point, N is the normal at that point.
    L = vec3_subtract(light.position, P); // Vector from point P to the light
    vec3_normalize(&L);
    
    // Calculate the diffuse intensity
    diffuse_intensity = light.intensity * fmax(0.0, vec3_dot(N, L));
    
    // Adjust color by diffuse intensity (assuming the sphere's color is red for now)
    rgb[0] = fmin(255, 255 * diffuse_intensity);
    rgb[1] = 0;
    rgb[2] = 0;

    // Combine the color channels and return the color
    color = (rgb[0] << 16) | (rgb[1] << 8) | rgb[2];
    return (color);
}

int trace_ray(t_ray r, float t_min, float t_max, t_scene scene, t_light light) 
{
    float       closest_t;
    t_sphere    *closest_sphere;
    float       t[2];
    int         i;
    int         color;

    closest_t = INFINITY;
    closest_sphere = NULL;

    i = 0;
    while (i < 4)
    {
        intersect_ray_sphere(r, scene.spheres[i], &t[0], &t[1]);
        if (t[0] >= t_min && t[0] <= t_max && t[0] < closest_t)
        {
            closest_t = t[0];
            closest_sphere = &scene.spheres[i];
        }
        if (t[1] >= t_min && t[1] <= t_max && t[1] < closest_t)
        {
            closest_t = t[1];
            closest_sphere = &scene.spheres[i];
        }
        i++;
    }

    if (closest_sphere == NULL) 
        return (0x000000); // Background color (black for now)

    // Calculate the point of intersection
    t_vec3 P = vec3_add(r.origin, vec3_mult_scalar(r.direction, closest_t));

    // Calculate the normal to the surface at the intersection point
    t_vec3 N = vec3_subtract(P, closest_sphere->center);
    vec3_normalize(&N);

    // Compute the color at the intersection point with lighting
    color = compute_lighting(P, N, scene, light);

    return (color);
}
