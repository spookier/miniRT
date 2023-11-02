#include "../incs/minirt.h"

t_ray init_ray(t_vec3 origin, t_vec3 direction) 
{
    t_ray r;

    r.origin = origin;
    r.direction = direction;
    return (r);
}

// Function to compute a point on the ray given parameter t
t_vec3 point_on_ray(t_ray r, float t) 
{
    t_vec3 point;

    point.x = r.origin.x + t * r.direction.x;
    point.y = r.origin.y + t * r.direction.y;
    point.z = r.origin.z + t * r.direction.z;

    return (point);
}