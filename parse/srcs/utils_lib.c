/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lib.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:41:54 by yhwang            #+#    #+#             */
/*   Updated: 2023/11/21 17:37:43 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT_parse.h"

void	*ft_realloc(void *old_ptr, size_t old_len, size_t new_len)
{
	char	*new_ptr;

	new_ptr = malloc(new_len);
	if (!new_ptr)
		return (NULL);
	ft_bzero(new_ptr, new_len);
	ft_memcpy(new_ptr, old_ptr, old_len);
	free(old_ptr);
	return (new_ptr);
}

void	free_2d(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	free_scene(t_scene *scene, int flag)
{
	int	i;

	if (scene->ambient)
		free(scene->ambient);
	if (scene->camera)
		free(scene->camera);
	if (scene->light)
		free(scene->light);
	if (scene->obj)
	{
		i = 0;
		while (scene->obj[i])
			free(scene->obj[i++]);
		free(scene->obj);
	}
	free(scene);
	if (flag == 1)
		err_msg("Malloc error");
}
