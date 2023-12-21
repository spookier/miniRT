/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rotate_hooks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:36:27 by yhwang            #+#    #+#             */
/*   Updated: 2023/12/21 16:37:20 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minirt.h"

static void	find_key_flag_op(t_all *all)
{
	if (all->key_flag_op == MOVE)
		mlx_key_hook(all->g_eng.mlx_win, pos_move_hook, all);
	else if (all->key_flag_op == ROTATE)
		mlx_key_hook(all->g_eng.mlx_win, vec_rotate_hook, all);
}

int	x_y_z_hook(int keycode, t_all *all)
{
	printf("%s* X, Y, Z *%s\n", YELLOW, BLACK);
	printf("KEY_SPACE: back\n");
	printf("KEY_LEFT / KEY_DOWN: -\nKEY_RIGHT / key_UP:  +\n");
	if (keycode == KEY_ESC)
		exit_prog(all, NULL);
	else if (keycode == KEY_SPACE)
		find_key_flag_op(all);
	else if (keycode == KEY_LEFT || keycode == KEY_DOWN)
	{
		all->key_flag_p_m = MINUS;
		apply_move_rotate(all);
	}
	else if (keycode == KEY_RIGHT || keycode == KEY_UP)
	{
		all->key_flag_p_m = PLUS;
		apply_move_rotate(all);
	}
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT
		|| keycode == KEY_UP || keycode == KEY_DOWN)
	{
		start_draw(all);
		mlx_put_image_to_window(all->g_eng.mlx,
			all->g_eng.mlx_win, all->img.img, 0, 0);
	}
	return (0);
}

static void	find_key_flag_id(t_all *all, char flag)
{
	if (all->key_flag_id == CAM)
	{
		printf("%s[ CAMERA ]%s\n", CYAN, BLACK);
		mlx_key_hook(all->g_eng.mlx_win, camera_hook, all);
	}
	else if (all->key_flag_id == LIGHT && flag == 'l')
	{
		printf("%s[ LIGHT ]%s\n", CYAN, BLACK);
		mlx_key_hook(all->g_eng.mlx_win, light_hook, all);
	}
	else if (all->key_flag_id == SP)
	{
		printf("%s[ SPHERE: %d ]%s\n", CYAN, all->sp + 1, BLACK);
		mlx_key_hook(all->g_eng.mlx_win, obj_hook, all);
	}
	else if (all->key_flag_id == PL)
	{
		printf("%s[ PLANE: %d ]%s\n", CYAN, all->pl + 1, BLACK);
		mlx_key_hook(all->g_eng.mlx_win, obj_hook, all);
	}
	else if (all->key_flag_id == CY)
	{
		printf("%s[ CYLINDER: %d ]%s\n", CYAN, all->cy + 1, BLACK);
		mlx_key_hook(all->g_eng.mlx_win, obj_hook, all);
	}
}

int	pos_move_hook(int keycode, t_all *all)
{
	all->key_flag_xyz = 0;
	all->key_flag_p_m = 0;
	printf("%s* MOVE *%s\n", YELLOW, BLACK);
	printf("KEY_SPACE: back\n");
	printf("KEY_X: x\n");
	printf("KEY_Y: y\n");
	printf("KEY_Z: z\n");
	if (keycode == KEY_ESC)
		exit_prog(all, NULL);
	else if (keycode == KEY_SPACE)
		find_key_flag_id(all, 'l');
	else if (keycode == KEY_X)
		all->key_flag_xyz = X;
	else if (keycode == KEY_Y)
		all->key_flag_xyz = Y;
	else if (keycode == KEY_Z)
		all->key_flag_xyz = Z;
	if (keycode == KEY_X || keycode == KEY_Y || keycode == KEY_Z)
		mlx_key_hook(all->g_eng.mlx_win, x_y_z_hook, all);
	return (0);
}

int	vec_rotate_hook(int keycode, t_all *all)
{
	all->key_flag_xyz = 0;
	all->key_flag_p_m = 0;
	printf("%s* ROTATE *%s\n", YELLOW, BLACK);
	printf("KEY_SPACE: back\n");
	printf("KEY_X: x\n");
	printf("KEY_Y: y\n");
	printf("KEY_Z: z\n");
	if (keycode == KEY_ESC)
		exit_prog(all, NULL);
	else if (keycode == KEY_SPACE)
		find_key_flag_id(all, 'm');
	else if (keycode == KEY_X)
		all->key_flag_xyz = X;
	else if (keycode == KEY_Y)
		all->key_flag_xyz = Y;
	else if (keycode == KEY_Z)
		all->key_flag_xyz = Z;
	if (keycode == KEY_X || keycode == KEY_Y || keycode == KEY_Z)
		mlx_key_hook(all->g_eng.mlx_win, x_y_z_hook, all);
	return (0);
}
