/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostin <acostin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 08:18:17 by acostin           #+#    #+#             */
/*   Updated: 2022/12/14 08:22:39 by acostin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

int	count_flags(const char *str, char *flags)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (str[i] && str[i + 1])
	{
		j = 0;
		if (str[i] == '%' && str[i + 1])
		{
			while (flags[j] && str[i + 1] != flags[j])
			{
				j++;
			}
			if (flags[j] && str[i + 1] == flags[j])
			{
				count++;
			}
		}
		i++;
	}
	return (count);
}
