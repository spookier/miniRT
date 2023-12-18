/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:47:31 by yhwang            #+#    #+#             */
/*   Updated: 2023/12/18 18:39:10 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT_parse.h"

int	parse_light_pos(t_p_scene *scene, char *pos)
{
	char	**tmp;

	if (count_token(pos, ',', 3) != 3)
		return (err_msg("Map error: L: invalid xyz pos token"), 1);
	tmp = ft_split(pos, ',');
	if (check_xyz_pos(ft_atod(tmp[0]), ft_atod(tmp[1]), ft_atod(tmp[2])))
		return (err_msg("Map error: L: invalid xyz pos value"),
			free_2d(tmp), 1);
	scene->light->xyz_pos.x = ft_atod(tmp[0]);
	scene->light->xyz_pos.y = ft_atod(tmp[1]);
	scene->light->xyz_pos.z = ft_atod(tmp[2]);
	return (free_2d(tmp), 0);
}

int	parse_light_brightness(t_p_scene *scene, char *brightness)
{
	if (check_double(ft_atod(brightness), 0, 1))
		return (err_msg("Map error: L: invalid brightness value"), 1);
	scene->light->brightness = ft_atod(brightness);
	return (0);
}

int	parse_light_rgb(t_p_scene *scene, char *rgb)
{
	char	**tmp;

	if (count_token(rgb, ',', 3) != 3)
		return (err_msg("Map error: L: rgb: invalid rgb token"), 1);
	tmp = ft_split(rgb, ',');
	if (check_rgb(ft_atoi(tmp[0]), ft_atoi(tmp[1]), ft_atoi(tmp[2])))
		return (err_msg("Map error: L: rgb: invalid rgb value"),
			free_2d(tmp), 1);
	scene->light->rgb.r = ft_atoi(tmp[0]);
	scene->light->rgb.g = ft_atoi(tmp[1]);
	scene->light->rgb.b = ft_atoi(tmp[2]);
	return (free_2d(tmp), 0);
}

int	parse_light(t_p_scene *scene, char *line)
{
	char	**token;

	if (scene->light->check)
		return (err_msg("Map error: L: element already exists"), 1);
	if (count_token(line, ' ', 4) != 4)
		return (err_msg("Map error: L: invalid line token"), 1);
	token = ft_split(line, ' ');
	if (!(!ft_strncmp(token[0], "L", 1) && ft_strlen(token[0]) == 1))
		return (err_msg("Map error: L: invalid identifier"), free_2d(token), 1);
	if (parse_light_pos(scene, token[1])
		|| parse_light_brightness(scene, token[2])
		|| parse_light_rgb(scene, token[3]))
		return (free_2d(token), 1);
	return (scene->light->check++, free_2d(token), 0);
}
