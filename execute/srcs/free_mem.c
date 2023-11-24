#include "../incs/minirt.h"

static void free_img(t_all *all)
{
	mlx_destroy_image(all->g_eng.mlx, all->img.img);
	mlx_clear_window(all->g_eng.mlx, all->g_eng.mlx_win);
	mlx_destroy_window(all->g_eng.mlx, all->g_eng.mlx_win);
	mlx_destroy_display(all->g_eng.mlx);
}

void free_mem(t_all *all) 
{
	if(!all)
		return ;
	free_img(all);
	if(all->g_eng.mlx)
		free(all->g_eng.mlx);
	free(all);
}
