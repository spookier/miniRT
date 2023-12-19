/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 21:48:34 by acostin           #+#    #+#             */
/*   Updated: 2023/12/19 12:31:01 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minirt.h"

int	key_hook(int keycode, t_all *all)
{
	if (keycode == KEY_ESC)
		exit_prog(all, NULL);
	// if (keycode == KEY_1)
	// 	all->cam.direction.x -= 0.2;
	// if (keycode == KEY_2)
	// 	all->cam.direction.x += 0.2;
	// if (keycode == KEY_3)
	// 	all->cam.direction.y -= 0.2;
	// if (keycode == KEY_4)
	// 	all->cam.direction.y += 0.2;
	// if (keycode == KEY_5)
	// 	all->cam.direction.z -= 0.2;
	// if (keycode == KEY_6)
	// 	all->cam.direction.z += 0.2;
	// if (keycode == KEY_Q)
	// 	all->cam.origin.x -= 1;
	// if (keycode == KEY_W)
	// 	all->cam.origin.x += 1;
	// if (keycode == KEY_E)
	// 	all->cam.origin.y -= 1;
	// if (keycode == KEY_R)
	// 	all->cam.origin.y += 1;
	// if (keycode == KEY_T)
	// 	all->cam.origin.z -= 1;
	// if (keycode == KEY_Y)
	// 	all->cam.origin.z += 1;
	// if (keycode != KEY_ESC)
	// {
	// 	start_draw(all);
	// 	mlx_put_image_to_window(all->g_eng.mlx,
	// 		all->g_eng.mlx_win, all->img.img, 0, 0);
	// }
	return (0);
}
