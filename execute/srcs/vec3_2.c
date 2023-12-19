/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:40:41 by acostin           #+#    #+#             */
/*   Updated: 2023/12/19 00:46:47 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minirt.h"

float	vec3_length(t_vec3 v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

void	vec3_normalize(t_vec3 *v)
{
	float	length;

	length = vec3_length(*v);
	if (length != 0) 
	{
		v->x /= length;
		v->y /= length;
		v->z /= length;
	}
}

t_vec3	vec3_mult_scalar(t_vec3 v, float scalar)
{
	t_vec3	result;

	result.x = v.x * scalar;
	result.y = v.y * scalar;
	result.z = v.z * scalar;
	return (result);
}
