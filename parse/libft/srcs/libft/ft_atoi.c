/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 18:38:31 by yhwang            #+#    #+#             */
/*   Updated: 2023/11/21 11:30:16 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_valid_atoi(int c)
{
	return (c == '+' || c == '-' || c == '.' || ('0' <= c && c <= '9'));
}

int	check_after_point(const char *str, int i, int j, int *point)
{
	while (i < (int)ft_strlen(str))
	{
		if (str[i] == '.')
		{
			(*point)++;
			j = i;
		}
		i++;
	}
	if (j != 0)
	{
		while (j + 1 < (int)ft_strlen(str))
		{
			if (str[j + 1] == '0')
				j++;
			else
				return (1);
		}
	}
	return (0);
}

int	check_valid_str_atoi(const char *str)
{
	int	i;
	int	j;
	int	point;

	i = 0;
	while (i < (int)ft_strlen(str))
	{
		if (!check_valid_atoi(str[i++]))
			return (1);
	}
	if (str[0] == '.' || str[ft_strlen(str) - 1] == '.')
		return (1);
	i = 0;
	j = 0;
	point = 0;
	if (check_after_point(str, i, j, &point))
		return (1);
	if (point > 1)
		return (1);
	return (0);
}

int	ft_atoi_start(const char *str)
{
	long	sign;
	long	nbr;

	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	nbr = 0;
	while ('0' <= *str && *str <= '9')
		nbr = nbr * 10 + (*str++ - '0');
	if (*str == '+' || *str == '-')
		return (ERR_ATOI);
	return (sign * nbr);
}

int	ft_atoi(const char *str)
{
	if (check_valid_str_atoi(str))
		return (ERR_ATOI);
	else
		return (ft_atoi_start(str));
}
