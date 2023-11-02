/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostin <acostin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 23:14:46 by acostin           #+#    #+#             */
/*   Updated: 2022/12/10 15:43:05 by acostin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	size_t	i;
	size_t	j;
	char	*final_str;

	size = 1 + ft_strlen(s1) + ft_strlen(s2);
	final_str = (char *)ft_calloc(size, sizeof(char));
	if (!final_str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		final_str[i] = s1[i];
		i++;
	}	
	j = 0;
	while (s2[j])
	{
		final_str[i++] = s2[j++];
	}
	return (final_str);
}
