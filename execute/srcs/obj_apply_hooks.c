/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_apply_hooks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:09:10 by yhwang            #+#    #+#             */
/*   Updated: 2023/12/21 16:36:52 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minirt.h"

static void	move(t_all *all, t_obj *obj, int i, int n)
{
	int	j;

	j = 0;
	if (all->key_flag_xyz == X)
		obj[i].center.x += n;
	else if (all->key_flag_xyz == Y)
		obj[i].center.y += n;
	else if (all->key_flag_xyz == Z)
		obj[i].center.z += n;
	if (all->key_flag_id == PL)
	{
		j = i + all->scene.num_planes / 2 + all->scene.num_cylinder;
		if (all->key_flag_xyz == X)
			obj[j].center.x += n;
		else if (all->key_flag_xyz == Y)
			obj[j].center.y += n;
		else if (all->key_flag_xyz == Z)
			obj[j].center.z += n;
	}
}

void	obj_move(t_all *all)
{
	int	i;

	i = 0;
	if (all->key_flag_id == SP)
		i = all->sp;
	else if (all->key_flag_id == PL)
		i = all->scene.num_spheres + all->pl;
	else if (all->key_flag_id == CY)
		i = all->scene.num_spheres + all->scene.num_planes / 2 + all->cy;
	if (all->key_flag_p_m == MINUS)
		move(all, all->scene.obj, i, -1);
	else if (all->key_flag_p_m == PLUS)
		move(all, all->scene.obj, i, 1);
}

static void	calc_rotation(t_all *all, t_obj *obj, t_matrix3 m)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (all->key_flag_id == SP)
		i = all->sp;
	else if (all->key_flag_id == PL)
		i = all->scene.num_spheres + all->pl;
	else if (all->key_flag_id == CY)
		i = all->scene.num_spheres + all->scene.num_planes / 2 + all->cy;
	obj[i].xyz_vec = matrix_mul(m, obj[i].xyz_vec);
	obj[i].center = vec3_add(obj[i].center,
			vec3_mult_scalar(obj[i].xyz_vec, DELTA));
	if (all->key_flag_id == PL)
	{
		j = i + all->scene.num_planes / 2 + all->scene.num_cylinder;
		obj[j].xyz_vec = matrix_mul(m, obj[j].xyz_vec);
		obj[j].center = vec3_add(obj[j].center,
				vec3_mult_scalar(obj[j].xyz_vec, DELTA));
	}
}

void	obj_rotate(t_all *all)
{
	double	theta;

	theta = THETA * PI / 180;
	if (all->key_flag_xyz == X)
	{
		if (all->key_flag_p_m == MINUS)
			calc_rotation(all, all->scene.obj, get_metrix(-1 * theta, 'x'));
		else if (all->key_flag_p_m == PLUS)
			calc_rotation(all, all->scene.obj, get_metrix(theta, 'x'));
	}
	else if (all->key_flag_xyz == Y)
	{
		if (all->key_flag_p_m == MINUS)
			calc_rotation(all, all->scene.obj, get_metrix(-1 * theta, 'y'));
		else if (all->key_flag_p_m == PLUS)
			calc_rotation(all, all->scene.obj, get_metrix(theta, 'y'));
	}
	else if (all->key_flag_xyz == Z)
	{
		if (all->key_flag_p_m == MINUS)
			calc_rotation(all, all->scene.obj, get_metrix(-1 * theta, 'z'));
		else if (all->key_flag_p_m == PLUS)
			calc_rotation(all, all->scene.obj, get_metrix(theta, 'z'));
	}
}
