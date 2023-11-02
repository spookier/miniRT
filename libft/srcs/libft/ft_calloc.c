/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostin <acostin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:50:44 by acostin           #+#    #+#             */
/*   Updated: 2022/12/15 17:47:09 by acostin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*mem;
	size_t	malloc_size;

	mem = NULL;
	malloc_size = num * size;
	if (num && ((malloc_size / num) != size))
		return (NULL);
	mem = (void *)malloc(num * size);
	if (mem == NULL)
		return (NULL);
	ft_bzero(mem, num * size);
	return (mem);
}
