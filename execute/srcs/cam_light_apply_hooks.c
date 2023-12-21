/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_light_apply_hooks.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:05:38 by yhwang            #+#    #+#             */
/*   Updated: 2023/12/21 16:11:51 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minirt.h"

void	camera_move(t_all *all)
{
	if (all->key_flag_xyz == X)
	{
		if (all->key_flag_p_m == MINUS)
			all->cam.origin.x += -0.5;
		else if (all->key_flag_p_m == PLUS)
			all->cam.origin.x += 0.5;
	}
	else if (all->key_flag_xyz == Y)
	{
		if (all->key_flag_p_m == MINUS)
			all->cam.origin.y += -0.5;
		else if (all->key_flag_p_m == PLUS)
			all->cam.origin.y += 0.5;
	}
	else if (all->key_flag_xyz == Z)
	{
		if (all->key_flag_p_m == MINUS)
			all->cam.origin.z += -0.5;
		else if (all->key_flag_p_m == PLUS)
			all->cam.origin.z += 0.5;
	}
}

void	camera_rotate(t_all *all)
{
	if (all->key_flag_xyz == X)
	{
		if (all->key_flag_p_m == MINUS)
			rotate_scene(&all->scene, &all->cam, -1 * THETA, 'x');
		else if (all->key_flag_p_m == PLUS)
			rotate_scene(&all->scene, &all->cam, THETA, 'x');
	}
	else if (all->key_flag_xyz == Y)
	{
		if (all->key_flag_p_m == MINUS)
			rotate_scene(&all->scene, &all->cam, -1 * THETA, 'y');
		else if (all->key_flag_p_m == PLUS)
			rotate_scene(&all->scene, &all->cam, THETA, 'y');
	}
	else if (all->key_flag_xyz == Z)
	{
		if (all->key_flag_p_m == MINUS)
			rotate_scene(&all->scene, &all->cam, -1 * THETA, 'z');
		else if (all->key_flag_p_m == PLUS)
			rotate_scene(&all->scene, &all->cam, THETA, 'z');
	}
}

void	light_move(t_all *all)
{
	if (all->key_flag_xyz == X)
	{
		if (all->key_flag_p_m == MINUS)
			all->scene.light.position.x -= 0.5;
		else if (all->key_flag_p_m == PLUS)
			all->scene.light.position.x += 0.5;
	}
	else if (all->key_flag_xyz == Y)
	{
		if (all->key_flag_p_m == MINUS)
			all->scene.light.position.y -= 0.5;
		else if (all->key_flag_p_m == PLUS)
			all->scene.light.position.y += 0.5;
	}
	else if (all->key_flag_xyz == Z)
	{
		if (all->key_flag_p_m == MINUS)
			all->scene.light.position.z -= 0.5;
		else if (all->key_flag_p_m == PLUS)
			all->scene.light.position.z += 0.5;
	}
}

void	apply_move_rotate(t_all *all)
{
	if (all->key_flag_id == CAM)
	{
		if (all->key_flag_op == MOVE)
			camera_move(all);
		else if (all->key_flag_op == ROTATE)
			camera_rotate(all);
	}
	else if (all->key_flag_id == LIGHT)
	{
		if (all->key_flag_op == MOVE)
			light_move(all);
	}
	else if (all->key_flag_id == SP
		|| all->key_flag_id == PL || all->key_flag_id == CY)
	{
		if (all->key_flag_op == MOVE)
			obj_move(all);
		else if (all->key_flag_op == ROTATE)
			obj_rotate(all);
	}
}
