/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:53:38 by yhwang            #+#    #+#             */
/*   Updated: 2023/12/22 17:19:08 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minirt.h"

static void	move(t_all *all)
{
	all->key_flag_op = MOVE;
	printf("%s[ MOVE ]%s\n", CYAN, BLACK);
	mlx_key_hook(all->g_eng.mlx_win, pos_move_hook, all);
}

static void	rotate(t_all *all)
{
	all->key_flag_op = ROTATE;
	printf("%s[ ROTATE ]%s\n", CYAN, BLACK);
	mlx_key_hook(all->g_eng.mlx_win, vec_rotate_hook, all);
}

static void	next_obj(t_all *all)
{
	if (all->key_flag_id == SP)
	{
		all->sp++;
		if (all->sp == all->scene.num_spheres)
			all->sp = 0;
		printf("%s[ SPHERE: %d ]%s\n", CYAN, all->sp + 1, BLACK);
	}
	else if (all->key_flag_id == PL)
	{
		all->pl++;
		if (all->pl == all->scene.num_planes / 2)
			all->pl = 0;
		printf("%s[ PLANE: %d ]%s\n", CYAN, all->pl + 1, BLACK);
	}
	else if (all->key_flag_id == CY)
	{
		all->cy++;
		if (all->cy == all->scene.num_cylinder)
			all->cy = 0;
		printf("%s[ CYLINDER: %d ]%s\n", CYAN, all->cy + 1, BLACK);
	}
	mlx_key_hook(all->g_eng.mlx_win, obj_hook, all);
}

int	obj_hook(int keycode, t_all *all)
{
	printf("%s[ HOME ]%s\n", CYAN, BLACK);
	printf("KEY_SPACE: back\n");
	printf("KEY_M:\tmove\n");
	if (all->key_flag_id != SP)
		printf("KEY_R:\trotate\n");
	printf("KEY_RIGHT: next object\n");
	if (keycode == KEY_ESC)
		exit_prog(all, NULL);
	else if (keycode == KEY_SPACE)
		mlx_key_hook(all->g_eng.mlx_win, key_hook, all);
	if (keycode == KEY_M)
		move(all);
	else if (keycode == KEY_R && all->key_flag_id != SP)
		rotate(all);
	else if (keycode == KEY_RIGHT)
		next_obj(all);
	return (0);
}
