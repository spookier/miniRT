/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:57:00 by yhwang            #+#    #+#             */
/*   Updated: 2023/12/18 18:38:49 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT_parse.h"

int	parse_camera_pos(t_p_scene *scene, char *pos)
{
	char	**tmp;

	if (count_token(pos, ',', 3) != 3)
		return (err_msg("Map error: C: invalid xyz pos token"), 1);
	tmp = ft_split(pos, ',');
	if (check_xyz_pos(ft_atod(tmp[0]), ft_atod(tmp[1]), ft_atod(tmp[2])))
		return (err_msg("Map error: C: invalid xyz pos value"),
			free_2d(tmp), 1);
	scene->camera->xyz_pos.x = ft_atod(tmp[0]);
	scene->camera->xyz_pos.y = ft_atod(tmp[1]);
	scene->camera->xyz_pos.z = ft_atod(tmp[2]);
	return (free_2d(tmp), 0);
}

int	parse_camera_vec(t_p_scene *scene, char *vec)
{
	char	**tmp;

	if (count_token(vec, ',', 3) != 3)
		return (err_msg("Map error: C: invalid xyz vec token"), 1);
	tmp = ft_split(vec, ',');
	if (check_xyz_vec(ft_atod(tmp[0]), ft_atod(tmp[1]), ft_atod(tmp[2])))
		return (err_msg("Map error: C: invalid xyz vec value"),
			free_2d(tmp), 1);
	scene->camera->xyz_vec.x = ft_atod(tmp[0]);
	scene->camera->xyz_vec.y = ft_atod(tmp[1]);
	scene->camera->xyz_vec.z = ft_atod(tmp[2]);
	return (free_2d(tmp), 0);
}

int	parse_camera_fov(t_p_scene *scene, char *fov)
{
	if (check_int(ft_atoi(fov), 0, 180))
		return (err_msg("Map error: C: invalid fov value"), 1);
	scene->camera->fov = ft_atoi(fov);
	return (0);
}

int	parse_camera(t_p_scene *scene, char *line)
{
	char	**token;

	if (scene->camera->check)
		return (err_msg("Map error: C: element already exists"), 1);
	if (count_token(line, ' ', 4) != 4)
		return (err_msg("Map error: C: invalid line token"), 1);
	token = ft_split(line, ' ');
	if (!(!ft_strncmp(token[0], "C", 1) && ft_strlen(token[0]) == 1))
		return (err_msg("Map error: C: invalid identifier"), free_2d(token), 1);
	if (parse_camera_pos(scene, token[1])
		|| parse_camera_vec(scene, token[2])
		|| parse_camera_fov(scene, token[3]))
		return (free_2d(token), 1);
	return (scene->camera->check++, free_2d(token), 0);
}
