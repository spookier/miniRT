/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check_id.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:14:32 by yhwang            #+#    #+#             */
/*   Updated: 2023/12/18 19:15:09 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT_parse.h"

int	parse_obj(t_p_scene *scene, char *line)
{
	int	i;

	i = scene->n_sphere + scene->n_plane + scene->n_cylinder;
	if (!ft_strncmp(line, "sp", 2) && count_token(line, ' ', 4) == 4)
	{
		if ((i > 0 && parse_init_scene_obj(scene, i))
			|| parse_sphere(scene, i, line))
			return (1);
	}
	else if (!ft_strncmp(line, "pl", 2) && count_token(line, ' ', 4) == 4)
	{
		if ((i > 0 && parse_init_scene_obj(scene, i))
			|| parse_plane(scene, i, line))
			return (1);
	}
	else if (!ft_strncmp(line, "cy", 2) && count_token(line, ' ', 6) == 6)
	{
		if ((i > 0 && parse_init_scene_obj(scene, i))
			|| parse_cylinder(scene, i, line))
			return (1);
	}
	else
		return (printf("%sError\nMap error: %c%c: invalid line token\n%s",
				RED, line[0], line[1], BLACK), 1);
	return (0);
}

int	check_id(t_p_scene *scene, char *line, int *flag)
{
	if (!ft_strncmp(line, "A", 1))
	{
		if (parse_ambient(scene, line))
			return (1);
	}
	else if (!ft_strncmp(line, "C", 1))
	{
		if (parse_camera(scene, line))
			return (1);
	}
	else if (!ft_strncmp(line, "L", 1))
	{
		if (parse_light(scene, line))
			return (1);
	}
	else if (!ft_strncmp(line, "sp", 2)
		|| !ft_strncmp(line, "pl", 2) || !ft_strncmp(line, "cy", 2))
	{
		if (parse_obj(scene, line))
			return (1);
	}
	else
		return ((*flag)++, 1);
	return (0);
}
