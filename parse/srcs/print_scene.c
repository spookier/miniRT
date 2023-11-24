/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 05:06:52 by yhwang            #+#    #+#             */
/*   Updated: 2023/11/21 19:24:20 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT_parse.h"

void	print_sphere(t_scene *scene)
{
	int	i;

	i = 0;
	while (scene->obj && scene->obj[i])
	{
		if (scene->obj[i]->obj_type == SPHERE)
		{
			printf("* OBJ[%d]: SPHERE *\n", i);
			printf("xyz pos: %.3f, %.3f, %.3f\n",
				scene->obj[i]->xyz_pos.x,
				scene->obj[i]->xyz_pos.y,
				scene->obj[i]->xyz_pos.z);
			printf("diameter: %.3f\n", scene->obj[i]->diameter);
			printf("rbg: %d, %d, %d\n", scene->obj[i]->rgb.r,
				scene->obj[i]->rgb.g, scene->obj[i]->rgb.b);
			printf("\n");
		}
		i++;
	}
}

void	print_plane(t_scene *scene)
{
	int	i;

	i = 0;
	while (scene->obj && scene->obj[i])
	{
		if (scene->obj[i]->obj_type == PLANE)
		{
			printf("* OBJ[%d]: PLANE *\n", i);
			printf("xyz pos: %.3f, %.3f, %.3f\n",
				scene->obj[i]->xyz_pos.x,
				scene->obj[i]->xyz_pos.y,
				scene->obj[i]->xyz_pos.z);
			printf("xyz vec: %.3f, %.3f, %.3f\n",
				scene->obj[i]->xyz_vec.x,
				scene->obj[i]->xyz_vec.y,
				scene->obj[i]->xyz_vec.z);
			printf("rbg: %d, %d, %d\n", scene->obj[i]->rgb.r,
				scene->obj[i]->rgb.g, scene->obj[i]->rgb.b);
			printf("\n");
		}
		i++;
	}
}

void	print_cylinder(t_scene *scene)
{
	int	i;

	i = 0;
	while (scene->obj && scene->obj[i])
	{
		if (scene->obj[i]->obj_type == CYLINDER)
		{
			printf("* OBJ[%d]: CYLINDER *\n", i);
			printf("xyz pos: %.3f, %.3f, %.3f\n",
				scene->obj[i]->xyz_pos.x,
				scene->obj[i]->xyz_pos.y,
				scene->obj[i]->xyz_pos.z);
			printf("xyz vec: %.3f, %.3f, %.3f\n",
				scene->obj[i]->xyz_vec.x,
				scene->obj[i]->xyz_vec.y,
				scene->obj[i]->xyz_vec.z);
			printf("diameter: %.3f\n", scene->obj[i]->diameter);
			printf("height: %.3f\n", scene->obj[i]->height);
			printf("rbg: %d, %d, %d\n", scene->obj[i]->rgb.r,
				scene->obj[i]->rgb.g, scene->obj[i]->rgb.b);
			printf("\n");
		}
		i++;
	}
}

void	print_scene(t_scene *scene)
{
	printf("* AMBIENT *\n");
	printf("lighting: %.3f\n", scene->ambient->lighting);
	printf("rbg: %d, %d, %d\n", scene->ambient->rgb.r,
		scene->ambient->rgb.g, scene->ambient->rgb.b);
	printf("\n");
	printf("* CAMERA *\n");
	printf("xyz pos: %.3f, %.3f, %.3f\n", scene->camera->xyz_pos.x,
		scene->camera->xyz_pos.y, scene->camera->xyz_pos.z);
	printf("xyz vec: %.3f, %.3f, %.3f\n", scene->camera->xyz_vec.x,
		scene->camera->xyz_vec.y, scene->camera->xyz_vec.z);
	printf("fov: %d\n", scene->camera->fov);
	printf("\n");
	printf("* LIGHT *\n");
	printf("xyz pos: %.3f, %.3f, %.3f\n", scene->light->xyz_pos.x,
		scene->light->xyz_pos.y, scene->light->xyz_pos.z);
	printf("brightness: %.3f\n", scene->light->brightness);
	printf("rbg: %d, %d, %d\n", scene->light->rgb.r,
		scene->light->rgb.g, scene->light->rgb.b);
	printf("\n");
	print_sphere(scene);
	print_plane(scene);
	print_cylinder(scene);
}
