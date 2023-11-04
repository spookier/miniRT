#include "../incs/minirt.h"

t_light light_create(t_light_type type, t_vec3 position, int color, float intensity)
{
	t_light light;

	light.type = type;

	light.position.x = position.x;
	light.position.y = position.y;
	light.position.z = position.z;

	light.color = color;

	light.intensity = intensity;

	return(light);
}