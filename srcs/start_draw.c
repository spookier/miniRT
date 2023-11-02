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
	 int screen_x;
	int screen_y;

	screen_x = (all->viewp.img_width / 2) + x;
	screen_y = (all->viewp.img_height / 2) - y;
	dst = all->img.addr + (screen_y * all->img.line_length + screen_x * (all->img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

//-------------------------------------------------------------



// Dot product
float dot(t_vec3 v1, t_vec3 v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

// Subtract two vectors
t_vec3 subtract(t_vec3 v1, t_vec3 v2) {
    t_vec3 result;
    result.x = v1.x - v2.x;
    result.y = v1.y - v2.y;
    result.z = v1.z - v2.z;
    return result;
}

// Intersect ray with a sphere
void intersect_ray_sphere(t_ray r, t_sphere sphere, float *t1, float *t2) {
    t_vec3 CO = subtract(r.origin, sphere.center);

    float a = dot(r.direction, r.direction);
    float b = 2 * dot(CO, r.direction);
    float c = dot(CO, CO) - sphere.radius * sphere.radius;

    float discriminant = b * b - 4 * a * c;
    if (discriminant < 0) {
        *t1 = INFINITY;
        *t2 = INFINITY;
        return;
    }

    *t1 = (-b + sqrt(discriminant)) / (2 * a);
    *t2 = (-b - sqrt(discriminant)) / (2 * a);
}

// Trace a ray
int trace_ray(t_ray r, float t_min, float t_max, t_scene scene) {
    float closest_t = INFINITY;
    t_sphere *closest_sphere = NULL;

    for (int i = 0; i < 3; i++) {
        float t1, t2;
        intersect_ray_sphere(r, scene.spheres[i], &t1, &t2);
        
        if (t1 >= t_min && t1 <= t_max && t1 < closest_t) {
            closest_t = t1;
            closest_sphere = &scene.spheres[i];
        }

        if (t2 >= t_min && t2 <= t_max && t2 < closest_t) {
            closest_t = t2;
            closest_sphere = &scene.spheres[i];
        }
    }

    if (closest_sphere == NULL) 
	{
        return 0xFFFFFF; // Background color (white for now)
    }
    return (0xFF0000);
}

// Main drawing function
void render_scene(t_scene scene, t_all *all) 
{
    t_vec3 cam;
    t_vec3 D;
    t_ray r;
    int color;
    int x;
    int y;

    cam = vec3(0, 0, 0);
    
    x = -all->viewp.img_width / 2;

    while (x < all->viewp.img_width/2)
    {
        y = -all->viewp.img_height / 2;
        while (y < all->viewp.img_height/2)
        {
            D = canvas_to_viewport(x, y, &all->viewp);
            r = init_ray(cam, D);
            color = trace_ray(r, 1.0, INFINITY, scene);
            put_pixel_coord(all, x, y, color);
            y++;
        }
        x++;

    }
}

int start_draw(t_all *all)
{
	// int i;
	// int j;
	// t_vec3 dir;
	// t_ray r = { .origin = {0, 0, 0} };


	
	// i = 0;
	printf("Rendering... \n");

	// while (i < all->viewp.img_height)
	// {
	// 	j = 0;
	// 	while (j < all->viewp.img_width)
	// 	{
	// 		//put_pixel_original(&all->img, j, i, 0x01103d);
	// 		dir = canvas_to_viewport(j - all->viewp.img_width/2, all->viewp.img_height/2 - i, &all->viewp);
	// 		r.direction = dir;
	// 		put_pixel_original(&all->img, j, i, trace_ray(ray));
	// 		j++;
	// 	}
	// 	i++;
	// }
	render_scene(all->scene, all);
	
	printf("Done.\n");
	
	return(0);
}