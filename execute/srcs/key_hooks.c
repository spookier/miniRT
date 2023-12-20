/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 21:48:34 by acostin           #+#    #+#             */
/*   Updated: 2023/12/20 17:01:33 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minirt.h"

# define MOVE	1
# define ROTATE	2

# define CAM	1
# define LIGHT	2

# define X	1
# define Y  	2
# define Z	3

# define PLUS	1
# define MINUS	2

void	camera_move(t_all *all)
{
	if (all->key_flag_3 == X)
	{
		if (all->key_flag_4 == MINUS)
			all->cam.origin.x -= 0.5;
		else
			all->cam.origin.x += 0.5;
	}
	else if (all->key_flag_3 == Y)
	{
		if (all->key_flag_4 == MINUS)
			all->cam.origin.y -= 0.5;
		else
			all->cam.origin.y += 0.5;
	}
	else
	{
		if (all->key_flag_4 == MINUS)
			all->cam.origin.z -= 0.5;
		else
			all->cam.origin.z += 0.5;
	}
}

// void	camera_rotate(t_all *all)
// {
// }

void	light_move(t_all *all)
{
	if (all->key_flag_3 == X)
	{
		if (all->key_flag_4 == MINUS)
			all->scene.light.position.x -= 0.5;
		else
			all->scene.light.position.x += 0.5;
	}
	else if (all->key_flag_3 == Y)
	{
		if (all->key_flag_4 == MINUS)
			all->scene.light.position.y -= 0.5;
		else
			all->scene.light.position.y += 0.5;
	}
	else
	{
		if (all->key_flag_4 == MINUS)
			all->scene.light.position.z -= 0.5;
		else
			all->scene.light.position.z += 0.5;
	}
}

void	move_rotate(t_all *all)
{
	if (all->key_flag_1 == CAM)
	{
		if (all->key_flag_2 == MOVE)
			camera_move(all);
		// else if (all->key_flag_2 == ROTATE)
		// 	camera_rotate(all);
	}
	else if (all->key_flag_1 == LIGHT)
	{
		if (all->key_flag_2 == MOVE)
			light_move(all);
	}
}

int	move_hook(int keycode, t_all *all)
{
	printf("space: back\n");
	printf("left: minus\n");
	printf("right: plus\n");
	if (keycode == KEY_ESC)
		exit_prog(all, NULL);
	if (keycode == KEY_SPACE)
		mlx_key_hook(all->g_eng.mlx_win, pos_move_hook, all);
	if (keycode == KEY_LEFT || keycode == KEY_DOWN)
	{
		all->key_flag_4 = MINUS;
		move_rotate(all);
	}
	if (keycode == KEY_RIGHT || keycode == KEY_UP)
	{
		all->key_flag_4 = PLUS;
		move_rotate(all);
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

int	pos_move_hook(int keycode, t_all *all)
{
	all->key_flag_2 = MOVE;
	all->key_flag_3 = 0;
	all->key_flag_4 = 0;
	printf("* MOVE *\n");
	printf("space: back\n");
	printf("press x, y or z \n");
	if (keycode == KEY_ESC)
		exit_prog(all, NULL);
	if (keycode == KEY_SPACE)
	{
		if (all->key_flag_1 == CAM)
		{
			printf("%s[ camera ]%s\n", CYAN, BLACK);
			mlx_key_hook(all->g_eng.mlx_win, camera_hook, all);
		}
		else if (all->key_flag_1 == LIGHT)
		{
			printf("%s[ light ]%s\n", CYAN, BLACK);
			mlx_key_hook(all->g_eng.mlx_win, light_hook, all);
		}
	}
	if (keycode == KEY_X)
		all->key_flag_3 = X;
	if (keycode == KEY_Y)
		all->key_flag_3 = Y;
	if (keycode == KEY_Z)
		all->key_flag_3 = Z;
	if (keycode == KEY_X || keycode == KEY_Y || keycode == KEY_Z)
		mlx_key_hook(all->g_eng.mlx_win, move_hook, all);
	return (0);
}

int	vec_rotate_hook(int keycode, t_all *all)
{
	all->key_flag_2 = ROTATE;
	all->key_flag_3 = 0;
	all->key_flag_4 = 0;
	printf("* ROTATE *\n");
	printf("space: back\n");
	printf("press x, y or z \n");
	if (keycode == KEY_ESC)
		exit_prog(all, NULL);
	if (keycode == KEY_SPACE)
	{
		if (all->key_flag_1 == CAM)
		{
			printf("%s[ camera ]%s\n", CYAN, BLACK);
			mlx_key_hook(all->g_eng.mlx_win, camera_hook, all);
		}
	}
	if (keycode == KEY_X)
		all->key_flag_3 = X;
	if (keycode == KEY_Y)
		all->key_flag_3 = Y;
	if (keycode == KEY_Z)
		all->key_flag_3 = Z;
	if (keycode == KEY_X || keycode == KEY_Y || keycode == KEY_Z)
		mlx_key_hook(all->g_eng.mlx_win, move_hook, all);
	return (0);
}

int	camera_hook(int keycode, t_all *all)
{
	all->key_flag_1 = CAM;
	printf("* CAMERA *\n");
	printf("space: back\n");
	printf("m: pos move\n");
	printf("r: vec rotate\n");
	if (keycode == KEY_ESC)
		exit_prog(all, NULL);
	if (keycode == KEY_SPACE)
	{
		printf("%s[ home ]%s\n", CYAN, BLACK);
		mlx_key_hook(all->g_eng.mlx_win, key_hook, all);
	}
	if (keycode == KEY_M)
	{
		printf("%s[ move ]%s\n", CYAN, BLACK);
		mlx_key_hook(all->g_eng.mlx_win, pos_move_hook, all);
	}
	if (keycode == KEY_R)
	{
		printf("%s[ rotate ]%s\n", CYAN, BLACK);
		mlx_key_hook(all->g_eng.mlx_win, vec_rotate_hook, all);
	
	}return (0);
}

int	light_hook(int keycode, t_all *all)
{
	all->key_flag_1 = LIGHT;
	printf("* LIGHT *\n");
	printf("space: back\n");
	printf("m: pos move\n");
	if (keycode == KEY_ESC)
		exit_prog(all, NULL);
	if (keycode == KEY_SPACE)
	{
		printf("%s[ home ]%s\n", CYAN, BLACK);
		mlx_key_hook(all->g_eng.mlx_win, key_hook, all);
	}
	if (keycode == KEY_M)
	{
		printf("%s[ move ]%s\n", CYAN, BLACK);
		mlx_key_hook(all->g_eng.mlx_win, pos_move_hook, all);
	}
	return (0);
}

int	key_hook(int keycode, t_all *all)
{
	all->key_flag_1 = 0;
	all->key_flag_2 = 0;
	all->key_flag_3 = 0;
	all->key_flag_4 = 0;
	printf("c: camera\n");
	printf("l: light\n");
	printf("1: sphere\n");
	printf("2: to select plane\n");
	printf("3: to select cylinder\n");
	if (keycode == KEY_ESC)
		exit_prog(all, NULL);
	if (keycode == KEY_C)
	{
		printf("%s[ camera ]%s\n", CYAN, BLACK);
		mlx_key_hook(all->g_eng.mlx_win, camera_hook, all);
	}
	if (keycode == KEY_L)
	{
		printf("%s[ light ]%s\n", CYAN, BLACK);
		mlx_key_hook(all->g_eng.mlx_win, light_hook, all);
	}
	return (0);
}
