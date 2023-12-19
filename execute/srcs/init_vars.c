/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:15:39 by acostin           #+#    #+#             */
/*   Updated: 2023/12/19 09:00:14 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minirt.h"

static void	init_vars_viewport(t_p_scene *p_scene, t_viewport *viewp)
{
	viewp->img_width = 900;
	viewp->img_height = 900;
	viewp->fov = p_scene->camera->fov;
	viewp->viewport_width = 1.0;
	viewp->viewport_height = 2 * 1 * tan(viewp->fov * PI / 360);
	viewp->viewport_width = viewp->viewport_height
			* viewp->img_width / viewp->img_height;
	viewp->distance_cam_to_viewport = 1.0;
	
}

static void	init_camera_vars(t_p_scene *p_scene, t_camera *camera)
{
	// camera doesn't move
	camera->origin = vec3(p_scene->camera->xyz_pos.x,
			p_scene->camera->xyz_pos.y, p_scene->camera->xyz_pos.z);
	camera->direction = vec3(p_scene->camera->xyz_vec.x,
			p_scene->camera->xyz_vec.y, p_scene->camera->xyz_vec.z);
}

static void	init_lights(t_p_scene *p_scene, t_light *light, t_ambient *ambient)
{
	*light = light_create(vec3(p_scene->light->xyz_pos.x,
				p_scene->light->xyz_pos.y, p_scene->light->xyz_pos.z),
			(p_scene->light->rgb.r << 16) + (p_scene->light->rgb.g << 8)
			+ p_scene->light->rgb.b,
			p_scene->light->brightness);
	*ambient = ambient_create((p_scene->ambient->rgb.r << 16)
			+ (p_scene->ambient->rgb.g << 8) + p_scene->ambient->rgb.b,
			p_scene->ambient->lighting);
}

int	init_vars(t_p_scene *p_scene, t_all *all)
{
	init_vars_viewport(p_scene, &all->viewp);
	init_camera_vars(p_scene, &all->cam);
	init_lights(p_scene, &all->scene.light, &all->scene.ambient);
	init_scene(p_scene, &all->scene);
	return (0);
}
