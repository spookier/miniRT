/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:51:36 by yhwang            #+#    #+#             */
/*   Updated: 2023/11/21 14:15:26 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT_parse.h"

void	err_msg(char *str)
{
	printf("%s", RED);
	printf("Error\n");
	printf("%s\n", str);
	printf("%s", BLACK);
}

int	get_char_idx(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	count_token(char *str, char del, int count)
{
	char	**temp;
	int		i;
	int		comma;

	temp = ft_split(str, del);
	i = 0;
	while (temp[i])
		i++;
	if (i != count)
		return (free_2d(temp), -1);
	if (del == ',')
	{
		i = -1;
		comma = 0;
		while (str[++i])
		{
			if (str[i] == ',')
				comma++;
		}
		if (str[0] == ',' || str[ft_strlen(str) - 1] == ',' || comma != 2)
			return (free_2d(temp), -1);
	}
	return (free_2d(temp), count);
}
