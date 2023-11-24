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

t_vec3 vec3_add(t_vec3 v1, t_vec3 v2) 
{
    t_vec3 result;
    result.x = v1.x + v2.x;
    result.y = v1.y + v2.y;
    result.z = v1.z + v2.z;
    return result;
}

static float vec3_length(t_vec3 v) 
{
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

void vec3_normalize(t_vec3 *v) 
{
    float length;
	
	length = vec3_length(*v);
    
    // To avoid division by zero, check if the length is not zero
    if (length != 0) 
	{
        v->x /= length;
        v->y /= length;
        v->z /= length;
    }
}

t_vec3 vec3_mult_scalar(t_vec3 v, float scalar) 
{
    t_vec3 result;

    result.x = v.x * scalar;
    result.y = v.y * scalar;
    result.z = v.z * scalar;
    return (result);
}

