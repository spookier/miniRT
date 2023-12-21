/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 21:48:34 by acostin           #+#    #+#             */
/*   Updated: 2023/12/21 01:27:16 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minirt.h"

# define MOVE	1
# define ROTATE	2

# define CAM	1
# define LIGHT	2
# define SP	3
# define PL	4
# define CY	5

# define X	1
# define Y  	2
# define Z	3

# define PLUS	1
# define MINUS	2

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

void	move(t_all *all, t_obj *obj, int i, int n)
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

void	rotate(t_all *all, t_obj *obj, t_matrix3 m)
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
	if (all->key_flag_xyz == X)
	{
		if (all->key_flag_p_m == MINUS)
			rotate(all, all->scene.obj, get_metrix(-1 * THETA, 'x'));
		else if (all->key_flag_p_m == PLUS)
			rotate(all, all->scene.obj, get_metrix(THETA, 'x'));
	}
	else if (all->key_flag_xyz == Y)
	{
		if (all->key_flag_p_m == MINUS)
			rotate(all, all->scene.obj, get_metrix(-1 * THETA, 'y'));
		else if (all->key_flag_p_m == PLUS)
			rotate(all, all->scene.obj, get_metrix(THETA, 'y'));
	}
	else if (all->key_flag_xyz == Z)
	{
		if (all->key_flag_p_m == MINUS)
			rotate(all, all->scene.obj, get_metrix(-1 * THETA, 'z'));
		else if (all->key_flag_p_m == PLUS)
			rotate(all, all->scene.obj, get_metrix(THETA, 'z'));
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

int	x_y_z_hook(int keycode, t_all *all)
{
	printf("space: back\n");
	printf("left / down: -\n");
	printf("right / up: +\n");
	if (keycode == KEY_ESC)
		exit_prog(all, NULL);
	else if (keycode == KEY_SPACE)
	{
		if (all->key_flag_op == MOVE)
			mlx_key_hook(all->g_eng.mlx_win, pos_move_hook, all);
		else if (all->key_flag_op == ROTATE)
			mlx_key_hook(all->g_eng.mlx_win, vec_rotate_hook, all);
	}
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

int	pos_move_hook(int keycode, t_all *all)
{
	all->key_flag_xyz = 0;
	all->key_flag_p_m = 0;
	printf("* MOVE *\n");
	printf("space: back\n");
	printf("press x, y or z \n");
	if (keycode == KEY_ESC)
		exit_prog(all, NULL);
	else if (keycode == KEY_SPACE)
	{
		if (all->key_flag_id == CAM)
		{
			printf("%s[ camera ]%s\n", CYAN, BLACK);
			mlx_key_hook(all->g_eng.mlx_win, camera_hook, all);
		}
		else if (all->key_flag_id == LIGHT)
		{
			printf("%s[ light ]%s\n", CYAN, BLACK);
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
	printf("* ROTATE *\n");
	printf("space: back\n");
	printf("press x, y or z \n");
	if (keycode == KEY_ESC)
		exit_prog(all, NULL);
	else if (keycode == KEY_SPACE)
	{
		if (all->key_flag_id == CAM)
		{
			printf("%s[ camera ]%s\n", CYAN, BLACK);
			mlx_key_hook(all->g_eng.mlx_win, camera_hook, all);
		}
		else if (all->key_flag_id == SP)
		{
			printf("%s[ SPHERE: %d ]%s\n", CYAN, all->sp + 1, BLACK);
			mlx_key_hook(all->g_eng.mlx_win, light_hook, all);
		}
		else if (all->key_flag_id == PL)
		{
			printf("%s[ PLANE: %d ]%s\n", CYAN, all->pl + 1, BLACK);
			mlx_key_hook(all->g_eng.mlx_win, light_hook, all);
		}
		else if (all->key_flag_id == CY)
		{
			printf("%s[ CYLINDER: %d ]%s\n", CYAN, all->cy + 1, BLACK);
			mlx_key_hook(all->g_eng.mlx_win, light_hook, all);
		}
	}
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

int	camera_hook(int keycode, t_all *all)
{	
	printf("space: back\n");
	printf("m: pos move\n");
	printf("r: vec rotate\n");
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
	printf("* LIGHT *\n");
	printf("space: back\n");
	printf("m: pos move\n");
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

int	obj_hook(int keycode, t_all *all)
{
	printf("space: back\n");
	printf("m: pos move\n");
	if (all->key_flag_id != SPHERE)
		printf("r: vec rotate\n");
	printf("right: next object\n");
	if (keycode == KEY_ESC)
		exit_prog(all, NULL);
	else if (keycode == KEY_SPACE)
	{
		printf("%s[ home ]%s\n", CYAN, BLACK);
		mlx_key_hook(all->g_eng.mlx_win, key_hook, all);
	}
	if (keycode == KEY_M)
	{
		all->key_flag_op = MOVE;
		printf("%s[ move ]%s\n", CYAN, BLACK);
		mlx_key_hook(all->g_eng.mlx_win, pos_move_hook, all);
	}
	else if (keycode == KEY_R && all->key_flag_id != SP)
	{
		all->key_flag_op = ROTATE;
		printf("%s[ rotate ]%s\n", CYAN, BLACK);
		mlx_key_hook(all->g_eng.mlx_win, vec_rotate_hook, all);
	}
	else if (keycode == KEY_RIGHT)
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
	return (0);
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
	printf("c: camera\n");
	printf("l: light\n");
	printf("1: sphere\n");
	printf("2: plane\n");
	printf("3: cylinder\n");
	if (keycode == KEY_ESC)
		exit_prog(all, NULL);
	else if (keycode == KEY_C)
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
	else if (keycode == KEY_1)
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
	return (0);
}
