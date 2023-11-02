#include "../incs/minirt.h"

static void init_res_and_mlx(t_all *all)	
{
	all->g_eng.mlx = mlx_init();
	all->g_eng.mlx_win = mlx_new_window(all->g_eng.mlx, all->viewp.img_width, all->viewp.img_height, "miniRT");
	all->img.img = mlx_new_image(all->g_eng.mlx, all->viewp.img_width, all->viewp.img_height);
	all->img.addr = mlx_get_data_addr(all->img.img, &all->img.bits_per_pixel, &all->img.line_length, &all->img.endian);
}

static void end_mlx_and_redraw(t_all *all)
{
	mlx_key_hook(all->g_eng.mlx_win, key_hook, all);
	mlx_put_image_to_window(all->g_eng.mlx, all->g_eng.mlx_win, all->img.img, 0, 0);
	mlx_loop(all->g_eng.mlx);
}

int start_mlx(t_all *all)
{

	init_res_and_mlx(all);		// boilerplate stuff

	start_draw(all);

	end_mlx_and_redraw(all);	// boilerplate stuff

	return (0);
}

