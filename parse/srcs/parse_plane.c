/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:24:56 by yhwang            #+#    #+#             */
/*   Updated: 2023/12/18 18:39:27 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT_parse.h"

int	parse_plane_pos(t_p_scene *scene, int i, char *pos)
{
	char	**tmp;

	if (count_token(pos, ',', 3) != 3)
		return (err_msg("Map error: pl: invalid xyz pos token"), 1);
	tmp = ft_split(pos, ',');
	if (check_xyz_pos(ft_atod(tmp[0]), ft_atod(tmp[1]), ft_atod(tmp[2])))
		return (err_msg("Map error: pl: invalid xyz pos value"),
			free_2d(tmp), 1);
	scene->obj[i]->xyz_pos.x = ft_atod(tmp[0]);
	scene->obj[i]->xyz_pos.y = ft_atod(tmp[1]);
	scene->obj[i]->xyz_pos.z = ft_atod(tmp[2]);
	return (free_2d(tmp), 0);
}

int	parse_plane_vec(t_p_scene *scene, int i, char *vec)
{
	char	**tmp;

	if (count_token(vec, ',', 3) != 3)
		return (err_msg("Map error: pl: invalid xyz vec token"), 1);
	tmp = ft_split(vec, ',');
	if (check_xyz_vec(ft_atod(tmp[0]), ft_atod(tmp[1]), ft_atod(tmp[2])))
		return (err_msg("Map error: pl: invalid xyz vec value"),
			free_2d(tmp), 1);
	scene->obj[i]->xyz_vec.x = ft_atod(tmp[0]);
	scene->obj[i]->xyz_vec.y = ft_atod(tmp[1]);
	scene->obj[i]->xyz_vec.z = ft_atod(tmp[2]);
	return (free_2d(tmp), 0);
}

int	parse_plane_rgb(t_p_scene *scene, int i, char *rgb)
{
	char	**tmp;

	if (count_token(rgb, ',', 3) != 3)
		return (err_msg("Map error: pl: rgb: invalid rgb token"), 1);
	tmp = ft_split(rgb, ',');
	if (check_rgb(ft_atoi(tmp[0]), ft_atoi(tmp[1]), ft_atoi(tmp[2])))
		return (err_msg("Map error: pl: rgb: invalid rgb value"),
			free_2d(tmp), 1);
	scene->obj[i]->rgb.r = ft_atoi(tmp[0]);
	scene->obj[i]->rgb.g = ft_atoi(tmp[1]);
	scene->obj[i]->rgb.b = ft_atoi(tmp[2]);
	return (free_2d(tmp), 0);
}

int	parse_plane(t_p_scene *scene, int i, char *line)
{
	char	**token;

	token = ft_split(line, ' ');
	if (!(!ft_strncmp(token[0], "pl", 2) && ft_strlen(token[0]) == 2))
		return (err_msg("Map error: pl: invalid identifier"),
			free_2d(token), 1);
	scene->obj[i]->obj_type = PLANE;
	if (parse_plane_pos(scene, i, token[1])
		|| parse_plane_vec(scene, i, token[2])
		|| parse_plane_rgb(scene, i, token[3]))
		return (free_2d(token), 1);
	return (scene->n_plane++, free_2d(token), 0);
}
