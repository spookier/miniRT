/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostin <acostin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:47:32 by acostin           #+#    #+#             */
/*   Updated: 2022/12/10 15:52:51 by acostin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		j;

	str = NULL;
	if (!set && s1)
		str = ft_strdup(s1);
	else if (s1)
	{
		i = 0;
		j = ft_strlen(s1);
		if (j > 0)
			j--;
		while (s1[i] && ft_strchr(set, s1[i]))
			i++;
		while (j > 0 && ft_strchr(set, s1[j]))
			j--;
		str = ft_substr(s1, i, (j - i + 1));
	}
	return (str);
}
