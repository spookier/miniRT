/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:27:39 by yhwang            #+#    #+#             */
/*   Updated: 2023/12/18 18:39:33 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT_parse.h"

int	parse_sphere_pos(t_p_scene *scene, int i, char *pos)
{
	char	**tmp;

	if (count_token(pos, ',', 3) != 3)
		return (err_msg("Map error: sp: invalid xyz pos token"), 1);
	tmp = ft_split(pos, ',');
	if (check_xyz_pos(ft_atod(tmp[0]), ft_atod(tmp[1]), ft_atod(tmp[2])))
		return (err_msg("Map error: sp: invalid xyz pos value"),
			free_2d(tmp), 1);
	scene->obj[i]->xyz_pos.x = ft_atod(tmp[0]);
	scene->obj[i]->xyz_pos.y = ft_atod(tmp[1]);
	scene->obj[i]->xyz_pos.z = ft_atod(tmp[2]);
	return (free_2d(tmp), 0);
}

int	parse_sphere_diameter(t_p_scene *scene, int i, char *diameter)
{
	if (check_double(ft_atod(diameter), 0, 0))
		return (err_msg("Map error: sp: invalid diameter value"), 1);
	scene->obj[i]->diameter = ft_atod(diameter);
	return (0);
}

int	parse_sphere_rgb(t_p_scene *scene, int i, char *rgb)
{
	char	**tmp;

	if (count_token(rgb, ',', 3) != 3)
		return (err_msg("Map error: sp: rgb: invalid rgb token"), 1);
	tmp = ft_split(rgb, ',');
	if (check_rgb(ft_atoi(tmp[0]), ft_atoi(tmp[1]), ft_atoi(tmp[2])))
		return (err_msg("Map error: sp: rgb: invalid rgb value"),
			free_2d(tmp), 1);
	scene->obj[i]->rgb.r = ft_atoi(tmp[0]);
	scene->obj[i]->rgb.g = ft_atoi(tmp[1]);
	scene->obj[i]->rgb.b = ft_atoi(tmp[2]);
	return (free_2d(tmp), 0);
}

int	parse_sphere(t_p_scene *scene, int i, char *line)
{
	char	**token;

	token = ft_split(line, ' ');
	if (!(!ft_strncmp(token[0], "sp", 2) && ft_strlen(token[0]) == 2))
		return (err_msg("Map error: sp: invalid identifier"),
			free_2d(token), 1);
	scene->obj[i]->obj_type = SPHERE;
	if (parse_sphere_pos(scene, i, token[1])
		|| parse_sphere_diameter(scene, i, token[2])
		|| parse_sphere_rgb(scene, i, token[3]))
		return (free_2d(token), 1);
	return (scene->n_sphere++, free_2d(token), 0);
}
