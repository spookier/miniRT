/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:52:44 by yhwang            #+#    #+#             */
/*   Updated: 2023/12/18 18:38:43 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT_parse.h"

int	parse_ambient_lighting(t_p_scene *scene, char *lighting)
{
	if (check_double(ft_atod(lighting), 0, 1))
		return (err_msg("Map error: A: invalid lighting value"), 1);
	scene->ambient->lighting = ft_atod(lighting);
	return (0);
}

int	parse_ambient_rgb(t_p_scene *scene, char *rgb)
{
	char	**tmp;

	if (count_token(rgb, ',', 3) != 3)
		return (err_msg("Map error: A: rgb: invalid rgb token"), 1);
	tmp = ft_split(rgb, ',');
	if (check_rgb(ft_atoi(tmp[0]), ft_atoi(tmp[1]), ft_atoi(tmp[2])))
		return (err_msg("Map error: A: rgb: invalid rgb value"),
			free_2d(tmp), 1);
	scene->ambient->rgb.r = ft_atoi(tmp[0]);
	scene->ambient->rgb.g = ft_atoi(tmp[1]);
	scene->ambient->rgb.b = ft_atoi(tmp[2]);
	return (free_2d(tmp), 0);
}

int	parse_ambient(t_p_scene *scene, char *line)
{
	char	**token;

	if (scene->ambient->check)
		return (err_msg("Map error: A: element already exists"), 1);
	if (count_token(line, ' ', 3) != 3)
		return (err_msg("Map error: A: invalid line token"), 1);
	token = ft_split(line, ' ');
	if (!(!ft_strncmp(token[0], "A", 1) && ft_strlen(token[0]) == 1))
		return (err_msg("Map error: A: invalid identifier"), free_2d(token), 1);
	if (parse_ambient_lighting(scene, token[1])
		|| parse_ambient_rgb(scene, token[2]))
		return (free_2d(token), 1);
	return (scene->ambient->check++, free_2d(token), 0);
}
