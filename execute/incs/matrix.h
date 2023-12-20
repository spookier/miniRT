/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 09:14:40 by yhwang            #+#    #+#             */
/*   Updated: 2023/12/20 02:55:05 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include "minirt.h"

typedef struct s_matrix3
{
	t_vec3	c1;
	t_vec3	c2;
	t_vec3	c3;
}	t_matrix3;

t_matrix3	matrix3(t_vec3 c1, t_vec3 c2, t_vec3 c3);
t_vec3		matrix_mul(t_matrix3 m, t_vec3 v);

#endif
