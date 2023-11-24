/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:19:42 by yhwang            #+#    #+#             */
/*   Updated: 2023/11/24 13:04:25 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT_parse.h"

int	check_arg(char *argv)
{
	int	len;
	int	fd;

	len = ft_strlen(argv);
	if (ft_strncmp(".rt", argv + (len - 3), 3))
		return (err_msg("File extention error"), 1);
	fd = open(argv, O_RDONLY);
	if (fd <= 0)
		return (err_msg("File open error"), 1);
	close(fd);
	return (0);
}

int	check_element(t_scene *scene)
{
	if (!scene->ambient->check)
		return (err_msg("Map: A: element is missing"), 1);
	if (!scene->camera->check)
		return (err_msg("Map: C: element is missing"), 1);
	if (!scene->light->check)
		return (err_msg("Map: L: element is missing"), 1);
	if (!scene->n_sphere)
		return (err_msg("Map: sp: object is missing"), 1);
	if (!scene->n_plane)
		return (err_msg("Map: pl: object is missing"), 1);
	if (!scene->n_cylinder)
		return (err_msg("Map: cy: object is missing"), 1);
	return (0);
}

t_scene	*parse(t_scene *scene, char *argv)
{
	if (check_arg(argv))
		return (free_scene(scene, 0), NULL);
	if (init_scene(scene))
		return (free_scene(scene, 1), NULL);
	if (parse_map(scene, argv))
		return (free_scene(scene, 0), NULL);
	if (check_element(scene))
		return (free_scene(scene, 0), NULL);
	return (scene);
}

t_scene	*parse_main(int argc, char **argv)
{
	t_scene	*scene;

	if (argc != 2 || !argv[1][0])
	{
		err_msg("argument error");
		exit (1);
	}
	scene = (t_scene *)ft_calloc(sizeof(t_scene), 2);
	if (!scene)
		return (err_msg("Malloc error"), NULL);
	if (!parse(scene, argv[1]))
		return (NULL);
	print_scene(scene);
	return (scene);
}
