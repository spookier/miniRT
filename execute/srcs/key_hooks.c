/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 21:48:34 by acostin           #+#    #+#             */
/*   Updated: 2023/12/21 16:20:55 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minirt.h"

static void	cam_light_key_hook(int keycode, t_all *all)
{
	if (keycode == KEY_C)
	{
		all->key_flag_id = CAM;
		printf("%s[ camera ]%s\n", CYAN, BLACK);
		mlx_key_hook(all->g_eng.mlx_win, camera_hook, all);
	}
	else if (keycode == KEY_L)
	{
		all->key_flag_id = LIGHT;
		printf("%s[ light ]%s\n", CYAN, BLACK);
		mlx_key_hook(all->g_eng.mlx_win, light_hook, all);
	}
}

static void	sp_pl_cy_key_hook(int keycode, t_all *all)
{
	if (keycode == KEY_1)
	{
		all->key_flag_id = SP;
		printf("%s[ SPHERE: %d ]%s\n", CYAN, all->sp + 1, BLACK);
		mlx_key_hook(all->g_eng.mlx_win, obj_hook, all);
	}
	else if (keycode == KEY_2)
	{
		all->key_flag_id = PL;
		printf("%s[ PLANE: %d ]%s\n", CYAN, all->pl + 1, BLACK);
		mlx_key_hook(all->g_eng.mlx_win, obj_hook, all);
	}
	else if (keycode == KEY_3)
	{
		all->key_flag_id = CY;
		printf("%s[ CYLINDER: %d ]%s\n", CYAN, all->cy + 1, BLACK);
		mlx_key_hook(all->g_eng.mlx_win, obj_hook, all);
	}
}

int	key_hook(int keycode, t_all *all)
{
	all->key_flag_id = 0;
	all->key_flag_op = 0;
	all->key_flag_xyz = 0;
	all->key_flag_p_m = 0;
	all->sp = 0;
	all->pl = 0;
	all->cy = 0;
	printf("%s[ HOME ]%s\n", CYAN, BLACK);
	printf("KEY_C:\tcamera\n");
	printf("KEY_L:\tlight\n");
	printf("KEY_1:\tsphere\n");
	printf("KEY_2:\tplane\n");
	printf("KEY_3:\tcylinder\n");
	if (keycode == KEY_ESC)
		exit_prog(all, NULL);
	else if (keycode == KEY_C || keycode == KEY_L)
		cam_light_key_hook(keycode, all);
	else if (keycode == KEY_1 || keycode == KEY_2 || keycode == KEY_3)
		sp_pl_cy_key_hook(keycode, all);
	return (0);
}
