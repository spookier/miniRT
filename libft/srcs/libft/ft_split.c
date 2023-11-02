/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostin <acostin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 06:07:33 by acostin           #+#    #+#             */
/*   Updated: 2022/12/15 17:51:35 by acostin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free (tab[i]);
		i++;
	}
	free (tab);
}

static size_t	calc_2dsize(char const *str, char c)
{
	size_t	size;
	size_t	i;

	i = 0;
	size = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			size++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (size);
}

static int	alloc_tab(char const *str, char **tab, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			tab[j] = ft_substr(str, i, ft_strchr(str + i, c) - (str + i));
			if (!tab[j])
			{
				free_tab(tab);
				return (1);
			}
			j++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	tab[j] = NULL;
	return (0);
}

char	**ft_split(char const *str, char c)
{
	char	**tab;

	tab = NULL;
	if (!str)
		return (NULL);
	tab = malloc(sizeof(char *) * (calc_2dsize(str, c) + 1));
	if (!tab)
		return (NULL);
	if (alloc_tab(str, tab, c) == 1)
		return (NULL);
	return (tab);
}
