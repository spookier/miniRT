/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 02:33:56 by yhwang            #+#    #+#             */
/*   Updated: 2023/12/19 02:41:30 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minirt.h"

static void	init_obj_pl_dup(t_p_scene *p_scene, t_scene *scene)
{
	int	i;
	int	j;
	
	i = p_scene->n_sphere + p_scene->n_plane + p_scene->n_cylinder;
	j = -1;
	while (p_scene->obj[++j])
	{
		if (p_scene->obj[j]->obj_type == PLANE)
		{
			scene->obj[i].type = p_scene->obj[j]->obj_type;
			scene->obj[i].center = vec3(p_scene->obj[j]->xyz_pos.x,
					p_scene->obj[j]->xyz_pos.y, p_scene->obj[j]->xyz_pos.z);
			scene->obj[i].xyz_vec = vec3(p_scene->obj[j]->xyz_vec.x,
					p_scene->obj[j]->xyz_vec.y, p_scene->obj[j]->xyz_vec.z);
			scene->obj[i].center = vec3_subtract(scene->obj[i].center,
					vec3_mult_scalar(scene->obj[i].xyz_vec, 0.001));
			scene->obj[i].xyz_vec = vec3_mult_scalar(scene->obj[i].xyz_vec, -1);
			scene->obj[i].color = create_rgb(p_scene->obj[j]->rgb.r,
					p_scene->obj[j]->rgb.g, p_scene->obj[j]->rgb.b);
			i++;
		}
	}
}

void	init_scene(t_p_scene *p_scene, t_scene *scene)
{
	int	i;

	scene->num_spheres = p_scene->n_sphere;
	scene->num_planes = p_scene->n_plane * 2;
	scene->num_cylinder = p_scene->n_cylinder;
	scene->obj = (t_obj *)ft_calloc(sizeof(t_obj),
			scene->num_spheres + scene->num_planes + scene->num_cylinder + 1);
	i = -1;
	while (p_scene->obj[++i])
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
	}
	init_obj_pl_dup(p_scene, scene);
}
