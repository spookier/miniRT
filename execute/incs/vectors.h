/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:43:51 by acostin           #+#    #+#             */
/*   Updated: 2023/12/19 00:47:21 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_H
# define VECTORS_H

# include "minirt.h"

typedef struct s_vec3
{
	double		x;
	double		y;
	double		z;

}	t_vec3;

t_vec3	vec3(double x, double y, double z);
float	vec3_dot(t_vec3 v1, t_vec3 v2);
t_vec3	vec3_subtract(t_vec3 v1, t_vec3 v2);
t_vec3	vec3_add(t_vec3 v1, t_vec3 v2);
void	vec3_normalize(t_vec3 *v);
t_vec3	vec3_mult_scalar(t_vec3 v, float scalar);
float	vec3_length(t_vec3 v);

#endif
