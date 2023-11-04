#include "../incs/minirt.h"

void	put_pixel_original(t_data *data, int x, int y, int color)
{
	char	*dst;
	
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	put_pixel_coord(t_all *all, int x, int y, int color)
{
	char	*dst;
	int     screen_x;
	int     screen_y;

	screen_x = (all->viewp.img_width / 2) + x;
	screen_y = (all->viewp.img_height / 2) - y;
	dst = all->img.addr + (screen_y * all->img.line_length + screen_x * (all->img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// Main drawing function
void render_scene(t_scene scene, t_all *all) 
{
    t_light light_1;
    //t_light light_2;
    //t_light light_3;
    t_vec3  cam;
    t_vec3  D;
    t_ray   r;
    t_rgb   color;
    int     x;
    int     y;

    cam = vec3(0, 0, 0);
    light_1 = light_create((t_vec3){0, 0, 0}, 0xFFFFFF, 0.2);
    //light_2 = light_create(POINT, (t_vec3){2, 1, 0}, 0xFFFFFF, 0.6);
    //light_3 = light_create(DIRECTIONAL, (t_vec3){1, 4, 4}, 0xFFFFFF, 0.2);

    x = -all->viewp.img_width / 2;

    while (x < all->viewp.img_width / 2)
    {
        y = -all->viewp.img_height / 2;
        while (y < all->viewp.img_height / 2)
        {
            D = canvas_to_viewport(x, y, &all->viewp);
            r = init_ray(cam, D);
            color = trace_ray(r, 1.0, INFINITY, scene, light_1);
            put_pixel_coord(all, x, y, convert_rgb_to_int(color));
            y++;
        }
        x++;
    }
}

int start_draw(t_all *all)
{
	printf("Rendering... \n");

	render_scene(all->scene, all);
	
	printf("Done.\n");
	
	return(0);
}