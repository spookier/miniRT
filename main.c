/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:26:09 by yhwang            #+#    #+#             */
/*   Updated: 2023/11/24 13:02:09 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parse/incs/miniRT_parse.h"
// #include "./execute/incs/minirt.h"

int	main(int argc, char **argv)
{
	t_scene	*scene;

	scene = parse_main(argc, argv);
	if (!scene)
		return (1);
	//execute

	free_scene(scene, 0);
	return (0);
}
