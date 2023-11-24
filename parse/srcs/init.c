/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:09:38 by yhwang            #+#    #+#             */
/*   Updated: 2023/11/21 17:49:32 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT_parse.h"

int	init_scene_obj(t_scene *scene, int i)
{
	if (i == 0)
		scene->obj = (t_obj **)ft_calloc(sizeof(t_obj *), 2);
	else
		scene->obj = (t_obj **)ft_realloc(scene->obj,
				sizeof(t_obj *) * (i + 1), sizeof(t_obj *) * (i + 2));
	scene->obj[i] = (t_obj *)ft_calloc(sizeof(t_obj), 2);
	if (!(scene->obj) || !(scene->obj[i]))
	{
		if (i == 0)
			return (free_scene(scene, 1), 1);
		else
			return (err_msg("Malloc error"), 1);
	}
	return (0);
}

int	init_scene(t_scene *scene)
{
	scene->ambient = (t_ambient *)ft_calloc(sizeof(t_ambient), 2);
	scene->camera = (t_camera *)ft_calloc(sizeof(t_camera), 2);
	scene->light = (t_light *)ft_calloc(sizeof(t_light), 2);
	if (!(scene->ambient) || !(scene->camera) || !(scene->light))
		return (free_scene(scene, 1), 1);
	if (init_scene_obj(scene, 0))
		return (1);
	return (0);
}
