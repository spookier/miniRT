#include "../incs/minirt.h"

t_vec3	vec3(double x, double y, double z)
{
	t_vec3	res;

	res.x = x;
	res.y = y;
	res.z = z;
	return (res);
}

// Dot product
float vec3_dot(t_vec3 v1, t_vec3 v2)
{
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

// Subtract two vectors
t_vec3 vec3_subtract(t_vec3 v1, t_vec3 v2) 
{
    t_vec3 result;
    result.x = v1.x - v2.x;
    result.y = v1.y - v2.y;
    result.z = v1.z - v2.z;
    return (result);
}