/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:15:39 by acostin           #+#    #+#             */
/*   Updated: 2023/12/18 02:57:13 by yhwang           ###   ########.fr       */
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
    *light = light_create((t_vec3){0, 5, -5}, 0xFFFFFF, 0.35);
    *ambient = ambient_create(0xFFFFFF, 0.3);
}

void    init_scene(t_scene *scene) 
{

    scene->num_lights = 2;
    scene->num_spheres = 3;
    scene->num_planes = 4 * 2;
    scene->num_cylinder = 3;

    scene->viewport_size[0] = 1.0;
    scene->viewport_size[1] = 1.0;
    scene->projection_plane_d = 1.0;

    scene->obj[0].type = SPHERE;
    scene->obj[0].center = vec3(0.0, 0.0, 3.0);
    scene->obj[0].radius = 0.5;
    scene->obj[0].color = create_rgb(255, 0, 0);

    scene->obj[1].type = SPHERE;
    scene->obj[1].center = vec3(1.5, 0.0, 4.0);
    scene->obj[1].radius = 0.5;
    scene->obj[1].color = create_rgb(0, 255, 0);

    scene->obj[2].type = SPHERE;
    scene->obj[2].center = vec3(-1.5, 0.0, 4.0);
    scene->obj[2].radius = 0.5;
    scene->obj[2].color = create_rgb(0, 0, 255);

    scene->obj[3].type = PLANE;
    scene->obj[3].center = vec3(0, -1, 0);
    scene->obj[3].xyz_vec = vec3(0, 1, 0);
    scene->obj[3].color = create_rgb(255, 255, 255);

    scene->obj[4].type = PLANE;
    scene->obj[4].center = vec3(-1.7, 0, 0);
    scene->obj[4].xyz_vec = vec3(1, 0, 0);
    scene->obj[4].color = create_rgb(0, 255, 255);

    scene->obj[5].type = PLANE;
    scene->obj[5].center = vec3(1.7, 0, 0);
    scene->obj[5].xyz_vec = vec3(1, 0, 0);
    scene->obj[5].color = create_rgb(255, 0, 255);

    scene->obj[6].type = PLANE;
    scene->obj[6].center = vec3(0, 0, 5);
    scene->obj[6].xyz_vec = vec3(0, 0, 1);
    scene->obj[6].color = create_rgb(255, 0, 255);

///
    scene->obj[7].type = PLANE;
    scene->obj[7].center = vec3(0, -1, 0);
    scene->obj[7].xyz_vec = vec3(0, 1, 0);
    scene->obj[7].center = vec3_subtract(scene->obj[7].center, vec3_mult_scalar(scene->obj[7].xyz_vec, 0.001));
    scene->obj[7].xyz_vec = vec3_mult_scalar(scene->obj[7].xyz_vec, -1);
    scene->obj[7].color = create_rgb(255, 255, 255);

    scene->obj[8].type = PLANE;
    scene->obj[8].center = vec3(-1.7, 0, 0);
    scene->obj[8].xyz_vec = vec3(1, 0, 0);
    scene->obj[8].center = vec3_subtract(scene->obj[8].center, vec3_mult_scalar(scene->obj[8].xyz_vec, 0.001));
    scene->obj[8].xyz_vec = vec3_mult_scalar(scene->obj[8].xyz_vec, -1);
    scene->obj[8].color = create_rgb(0, 255, 255);

    scene->obj[9].type = PLANE;
    scene->obj[9].center = vec3(1.7, 0, 0);
    scene->obj[9].xyz_vec = vec3(1, 0, 0);
    scene->obj[9].center = vec3_subtract(scene->obj[9].center, vec3_mult_scalar(scene->obj[9].xyz_vec, 0.001));
    scene->obj[9].xyz_vec = vec3_mult_scalar(scene->obj[9].xyz_vec, -1);
    scene->obj[9].color = create_rgb(255, 0, 255);

    scene->obj[10].type = PLANE;
    scene->obj[10].center = vec3(0, 0, 5);
    scene->obj[10].xyz_vec = vec3(0, 0, 1);
    scene->obj[10].center = vec3_subtract(scene->obj[10].center, vec3_mult_scalar(scene->obj[10].xyz_vec, 0.001));
    scene->obj[10].xyz_vec = vec3_mult_scalar(scene->obj[10].xyz_vec, -1);
    scene->obj[10].color = create_rgb(255, 0, 255);
///

    scene->obj[11].type = CYLINDER;
    scene->obj[11].center = vec3(0, 0, 3);
    scene->obj[11].radius = 0.1;
    scene->obj[11].height = 1.8;
    scene->obj[11].xyz_vec = vec3_mult_scalar(vec3(-1, -1, 1), 1 / sqrt(3));
    scene->obj[11].color = create_rgb(255, 255, 0);

    scene->obj[12].type = CYLINDER;
    scene->obj[12].center = vec3(-0.5, 0, 2);
    scene->obj[12].radius = 0.1;
    scene->obj[12].height = 0.6;
    scene->obj[12].xyz_vec = vec3(0, 1, 0);
    scene->obj[12].color = create_rgb(100, 150, 200);

    scene->obj[13].type = CYLINDER;
    scene->obj[13].center = vec3(0.5, 0, 2);
    scene->obj[13].radius = 0.1;
    scene->obj[13].height = 0.6;
    scene->obj[13].xyz_vec = vec3(1, 0, 0);
    scene->obj[13].color = create_rgb(200, 150, 100);

}

int init_vars(t_all *all)
{
    init_vars_viewport(&all->viewp);
    init_camera_vars(&all->cam);
    init_scene(&all->scene);
    init_lights(&all->scene.light, &all->scene.ambient);
	return(0);
}