/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostin <acostin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:14:34 by acostin           #+#    #+#             */
/*   Updated: 2022/12/10 15:41:54 by acostin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*new_str;
	size_t	size;

	new_str = NULL;
	size = ft_strlen(str);
	if (!str)
		return (0);
	new_str = (char *)malloc((size + 1) * sizeof(char));
	if (!new_str)
		return (0);
	new_str[size] = 0;
	ft_strlcpy(new_str, str, size + 1);
	return (new_str);
}
