/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_light_hooks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:53:30 by yhwang            #+#    #+#             */
/*   Updated: 2023/12/21 16:36:31 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minirt.h"

int	camera_hook(int keycode, t_all *all)
{
	printf("space: back\n");
	printf("KEY_M: pos move\n");
	printf("KEY_R: vec rotate\n");
	if (keycode == KEY_ESC)
		exit_prog(all, NULL);
	else if (keycode == KEY_SPACE)
	{
		printf("%s[ home ]%s\n", CYAN, BLACK);
		mlx_key_hook(all->g_eng.mlx_win, key_hook, all);
	}
	else if (keycode == KEY_M)
	{
		all->key_flag_op = MOVE;
		printf("%s[ move ]%s\n", CYAN, BLACK);
		mlx_key_hook(all->g_eng.mlx_win, pos_move_hook, all);
	}
	else if (keycode == KEY_R)
	{
		all->key_flag_op = ROTATE;
		printf("%s[ rotate ]%s\n", CYAN, BLACK);
		mlx_key_hook(all->g_eng.mlx_win, vec_rotate_hook, all);
	}
	return (0);
}

int	light_hook(int keycode, t_all *all)
{
	printf("space: back\n");
	printf("KEY_M: pos move\n");
	if (keycode == KEY_ESC)
		exit_prog(all, NULL);
	else if (keycode == KEY_SPACE)
	{
		printf("%s[ home ]%s\n", CYAN, BLACK);
		mlx_key_hook(all->g_eng.mlx_win, key_hook, all);
	}
	else if (keycode == KEY_M)
	{
		all->key_flag_op = MOVE;
		printf("%s[ move ]%s\n", CYAN, BLACK);
		mlx_key_hook(all->g_eng.mlx_win, pos_move_hook, all);
	}
	return (0);
}
