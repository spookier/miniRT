/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:26:09 by yhwang            #+#    #+#             */
/*   Updated: 2023/12/19 23:28:55 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parse/incs/miniRT_parse.h"
#include "./execute/incs/minirt.h"

int	main(int argc, char **argv)
{
	t_p_scene	*p_scene;
	t_all		*all;

	p_scene = parse_main(argc, argv);
	if (!p_scene)
		return (1);
	all = NULL;
	if (alloc_struct_mem(&all) == -1)
		exit_prog(all, "Error - Malloc failed");
	init_vars(p_scene, all);
	free_scene(p_scene, 0);
	if (all->cam.direction.z != 1)
		set_cam_vec(all);
	start_mlx(all);
	exit_prog(all, NULL);
	return (0);
}
