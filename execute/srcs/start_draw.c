/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:31:13 by acostin           #+#    #+#             */
/*   Updated: 2023/12/19 22:29:30 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minirt.h"

void	put_pixel_original(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	put_pixel_coord(t_all *all, int x, int y, int color)
{
	char	*dst;
	int		screen_x;
	int		screen_y;

	screen_x = (all->viewp.img_width / 2) + x;
	screen_y = (all->viewp.img_height / 2) - y;
	dst = all->img.addr + (screen_y * \
	all->img.line_length + screen_x * (all->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

// Main drawing function
void	render_scene(t_scene scene, t_all *all)
{
	t_vec3	cam;
	t_vec3	direction;
	t_ray	r;
	t_rgb	color;
	int		xy[2];

	cam = all->cam.origin;
	xy[0] = -all->viewp.img_width / 2;
	while (xy[0] < all->viewp.img_width / 2)
	{
		xy[1] = -all->viewp.img_height / 2;
		while (xy[1] < all->viewp.img_height / 2)
		{
			direction = canvas_to_viewport(xy[0], xy[1], &all->viewp);
			r = init_ray(cam, direction);
			color = trace_ray(r, scene);
			put_pixel_coord(all, xy[0], xy[1], convert_rgb_to_int(color));
			xy[1]++;
		}
		xy[0]++;
	}
}

int	start_draw(t_all *all)
{
	printf("Rendering... \n");
	render_scene(all->scene, all);
	printf("Done.\n");
	return (0);
}
