/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostin <acostin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:39:08 by acostin           #+#    #+#             */
/*   Updated: 2022/12/10 15:36:52 by acostin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*dest;
	unsigned char	*source;
	size_t			i;

	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	i = 0;
	if (dest == 0 && source == 0)
		return (0);
	if (dest < source)
	{
		while (i < n)
		{
			dest[i] = source[i];
			i++;
		}
	}
	else
	{
		while (0 < n--)
			dest[n] = source[n];
	}
	return (dest);
}
