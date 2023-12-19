/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 09:18:40 by yhwang            #+#    #+#             */
/*   Updated: 2023/12/19 09:30:47 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minirt.h"

t_matrix3	matrix3(t_vec3 c1, t_vec3 c2, t_vec3 c3)
{
	t_matrix3	res;

	res.c1 = c1;
	res.c2 = c2;
	res.c3 = c3;
	return (res);
}

t_vec3	matrix_mul(t_matrix3 m, t_vec3 v)
{
	t_vec3	res;

	res.x = m.c1.x * v.x + m.c2.x * v.y + m.c3.x * v.z;
	res.y = m.c1.y * v.x + m.c2.y * v.y + m.c3.y * v.z;
	res.z = m.c1.z * v.x + m.c2.z * v.y + m.c3.z * v.z;
	return (res);
}
