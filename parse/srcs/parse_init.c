/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:09:38 by yhwang            #+#    #+#             */
/*   Updated: 2023/12/18 19:13:08 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT_parse.h"

int	parse_init_scene_obj(t_p_scene *scene, int i)
{
	if (i == 0)
		scene->obj = (t_p_obj **)ft_calloc(sizeof(t_p_obj *), 2);
	else
		scene->obj = (t_p_obj **)ft_realloc(scene->obj,
				sizeof(t_p_obj *) * (i + 1), sizeof(t_p_obj *) * (i + 2));
	scene->obj[i] = (t_p_obj *)ft_calloc(sizeof(t_p_obj), 2);
	if (!(scene->obj) || !(scene->obj[i]))
	{
		if (i == 0)
			return (free_scene(scene, 1), 1);
		else
			return (err_msg("Malloc error"), 1);
	}
	return (0);
}

int	parse_init_scene(t_p_scene *scene)
{
	scene->ambient = (t_p_ambient *)ft_calloc(sizeof(t_p_ambient), 2);
	scene->camera = (t_p_camera *)ft_calloc(sizeof(t_p_camera), 2);
	scene->light = (t_p_light *)ft_calloc(sizeof(t_p_light), 2);
	if (!(scene->ambient) || !(scene->camera) || !(scene->light))
		return (free_scene(scene, 1), 1);
	if (parse_init_scene_obj(scene, 0))
		return (1);
	return (0);
}
