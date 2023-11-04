#include "../incs/minirt.h"

static void init_vars_viewport(t_viewport *viewp)
{
    //viewp->aspect_ratio = 16.0 / 9.0;
    viewp->img_width = 600;
    viewp->img_height = 600;
    //viewp->img_height = (int)(viewp->img_width / viewp->aspect_ratio);
    if (viewp->img_height < 1)
        viewp->img_height = 1;

    viewp->viewport_width = 1.0;
    viewp->viewport_height = 1.0;
    viewp->distance_cam_to_viewport = 1.0;
    viewp->fov = 53.0;
}

static void init_camera_vars(t_camera *camera)
{
    camera->origin = vec3(0.0, 0.0, 0.0);
    camera->direction = vec3(0.0, 0.0, 1.0);
}

void init_scene(t_scene *scene) 
{
    scene->viewport_size[0] = 1.0;
    scene->viewport_size[1] = 1.0;
    scene->projection_plane_d = 1.0;

    scene->spheres[0].center = vec3(0.0, -1.0, 3.0);
    scene->spheres[0].radius = 1.0;
    scene->spheres[0].color[0] = 255;
    scene->spheres[0].color[1] = 0;
    scene->spheres[0].color[2] = 0;

    scene->spheres[1].center = vec3(2.0, 0.0, 4.0);
    scene->spheres[1].radius = 1.0;
    scene->spheres[1].color[0] = 0;
    scene->spheres[1].color[1] = 255;
    scene->spheres[1].color[2] = 0;

    scene->spheres[2].center = vec3(-2.0, 0.0, 4.0);
    scene->spheres[2].radius = 1.0;
    scene->spheres[2].color[0] = 0;
    scene->spheres[2].color[1] = 0;
    scene->spheres[2].color[2] = 255;

    scene->spheres[3].center = vec3(0, -500, 0);
    scene->spheres[3].radius = 499.0;
    scene->spheres[3].color[0] = 255;
    scene->spheres[3].color[1] = 255;
    scene->spheres[3].color[2] = 0;

}

int init_vars(t_all *all)
{
    init_vars_viewport(&all->viewp);
    init_camera_vars(&all->cam);
    init_scene(&all->scene);
	return(0);
}