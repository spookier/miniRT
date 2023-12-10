/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostin <acostin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:15:39 by acostin           #+#    #+#             */
/*   Updated: 2023/12/10 02:32:41 by acostin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minirt.h"

static void init_vars_viewport(t_viewport *viewp)
{
    viewp->img_width = 900;
    viewp->img_height = 900;

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

static void init_lights(t_light *light, t_ambient *ambient)
{
    *light = light_create((t_vec3){0, 10, 0}, 0xFFFFFF, 0.35);
    *ambient = ambient_create(0xFFFFFF, 0.0);
}

void    init_scene(t_scene *scene) 
{

    scene->num_spheres = 4;
    scene->num_lights = 2;

    scene->viewport_size[0] = 1.0;
    scene->viewport_size[1] = 1.0;
    scene->projection_plane_d = 1.0;

    scene->spheres[0].center = vec3(0.0, -1.0, 3.0);
    scene->spheres[0].radius = 1.0;
    scene->spheres[0].color = create_rgb(255, 0, 0);

    scene->spheres[1].center = vec3(2.0, 0.0, 4.0);
    scene->spheres[1].radius = 1.0;
    scene->spheres[1].color = create_rgb(0, 255, 0);

    scene->spheres[2].center = vec3(-2.0, 0.0, 4.0);
    scene->spheres[2].radius = 1.0;
    scene->spheres[2].color = create_rgb(0, 0, 255);

    // BIG YELLOW GROUND
    scene->spheres[3].center = vec3(0, -500, 0);
    scene->spheres[3].radius = 499.0;
    scene->spheres[3].color = create_rgb(255, 255, 0);
}

int init_vars(t_all *all)
{
    init_vars_viewport(&all->viewp);
    init_camera_vars(&all->cam);
    init_scene(&all->scene);
    init_lights(&all->scene.light, &all->scene.ambient);
	return(0);
}