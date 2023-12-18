/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:15:39 by acostin           #+#    #+#             */
/*   Updated: 2023/12/18 21:24:45 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minirt.h"

static void	init_vars_viewport(t_p_scene *p_scene, t_viewport *viewp)
{
	viewp->img_width = 900;
	viewp->img_height = 900;

	if (viewp->img_height < 1)
		viewp->img_height = 1;

	viewp->viewport_width = 1.0;
	viewp->viewport_height = 1.0;
	viewp->distance_cam_to_viewport = 1.0;
	viewp->fov = p_scene->camera->fov; //[add]calculate fov
}

static void	init_camera_vars(t_p_scene *p_scene, t_camera *camera)
{
	// camera doesn't move
	camera->origin = vec3(p_scene->camera->xyz_pos.x,
		p_scene->camera->xyz_pos.y, p_scene->camera->xyz_pos.z);
	camera->direction = vec3(p_scene->camera->xyz_vec.x,
		p_scene->camera->xyz_vec.y, p_scene->camera->xyz_vec.z);
}

static void init_lights(t_p_scene *p_scene, t_light *light, t_ambient *ambient)
{
	*light = light_create(vec3(p_scene->light->xyz_pos.x,
		p_scene->light->xyz_pos.y, p_scene->light->xyz_pos.z),
		(p_scene->light->rgb.r << 16) + (p_scene->light->rgb.g << 8) + p_scene->light->rgb.b,
		p_scene->light->brightness);
	*ambient = ambient_create((p_scene->ambient->rgb.r << 16) + (p_scene->ambient->rgb.g << 8) + p_scene->ambient->rgb.b,
		p_scene->ambient->lighting);
}

void init_scene(t_p_scene *p_scene, t_scene *scene)
{
	int i;

	scene->num_lights = 2;
	scene->viewport_size[0] = 1.0;
	scene->viewport_size[1] = 1.0;
	scene->projection_plane_d = 1.0;

	scene->num_spheres = p_scene->n_sphere;
	scene->num_planes = p_scene->n_plane * 2;
	scene->num_cylinder = p_scene->n_cylinder;

	scene->obj = (t_obj *)ft_calloc(sizeof(t_obj),
					scene->num_spheres + scene->num_planes + scene->num_cylinder + 1);
	i = 0;
	while (p_scene->obj[i])
	{
		scene->obj[i].type = p_scene->obj[i]->obj_type;
		scene->obj[i].center = vec3(p_scene->obj[i]->xyz_pos.x,
					    p_scene->obj[i]->xyz_pos.y, p_scene->obj[i]->xyz_pos.z);
		scene->obj[i].xyz_vec = vec3(p_scene->obj[i]->xyz_vec.x,
					     p_scene->obj[i]->xyz_vec.y, p_scene->obj[i]->xyz_vec.z);
		scene->obj[i].radius = p_scene->obj[i]->diameter / 2;
		scene->obj[i].height = p_scene->obj[i]->height;
		scene->obj[i].color = create_rgb(p_scene->obj[i]->rgb.r,
						 p_scene->obj[i]->rgb.g, p_scene->obj[i]->rgb.b);
		i++;
	}
}

int init_vars(t_p_scene *p_scene, t_all *all)
{
	init_vars_viewport(p_scene, &all->viewp);
	init_camera_vars(p_scene, &all->cam);
	init_scene(p_scene, &all->scene);
	init_lights(p_scene, &all->scene.light, &all->scene.ambient);
	return (0);
}