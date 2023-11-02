/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostin <acostin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:01:54 by acostin           #+#    #+#             */
/*   Updated: 2022/12/14 18:02:45 by acostin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*tab;

	if (!str)
		return (NULL);
	if (start >= ft_strlen(str))
	{
		tab = malloc(1);
		if (!tab)
			return (NULL);
		tab[0] = 0;
		return (tab);
	}
	if (len > (ft_strlen(str) - start))
		tab = (char *)malloc(ft_strlen(str) - start + 1);
	else
		tab = (char *)malloc(len + 1);
	if (!tab)
		return (NULL);
	ft_strlcpy(tab, str + start, len + 1);
	return (tab);
}
