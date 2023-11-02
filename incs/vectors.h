#ifndef VECTORS_H
# define VECTORS_H

# include "minirt.h"

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

// /* utils_vec3_1 */
t_vec3	vec3(double x, double y, double z);
// t_vec3	vec3_add_vec3(t_vec3 v1, t_vec3 v2);
// t_vec3	vec3_sub_vec3(t_vec3 v1, t_vec3 v2);
// t_vec3	vec3_mul_rn(t_vec3 v, double rn);
// double	vec3_dot_vec3(t_vec3 v1, t_vec3 v2);

// /* utils_vec3_2 */
// double	vec3_length(t_vec3 v);
// t_vec3	vec3_unit(t_vec3 v);


#endif