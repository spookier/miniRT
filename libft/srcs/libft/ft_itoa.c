/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostin <acostin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:24:14 by acostin           #+#    #+#             */
/*   Updated: 2022/12/10 15:34:51 by acostin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	calc_size(int n)
{
	int	size;

	size = 0;
	if (n <= 0)
	{
		n = n * -1;
		size++;
	}
	while (n > 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

static void	fill_positive_tab(char *str, int size, int n)
{
	str[size] = 0;
	while (size - 1 >= 0)
	{
		str[size - 1] = (n % 10) + 48;
		n = n / 10;
		size--;
	}
}

static void	fill_negative_tab(char *str, int size, int n)
{
	n = n * -1;
	while (size - 1 >= 0)
	{
		str[size - 1] = (n % 10) + 48;
		n = n / 10;
		size--;
	}
	str[0] = '-';
}

static void	fill_min_int(char *str)
{
	str[0] = '-';
	str[1] = '2';
	str[2] = '1';
	str[3] = '4';
	str[4] = '7';
	str[5] = '4';
	str[6] = '8';
	str[7] = '3';
	str[8] = '6';
	str[9] = '4';
	str[10] = '8';
	str[11] = 0;
}

char	*ft_itoa(int n)
{
	char	*res;
	int		size;

	if (n == -2147483648)
	{
		res = malloc(12 * sizeof(char));
		if (!res)
			return (NULL);
		fill_min_int(res);
		return (res);
	}
	size = calc_size(n);
	res = malloc((size + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[size] = 0;
	if (n >= 0)
		fill_positive_tab(res, size, n);
	else
		fill_negative_tab(res, size, n);
	return (res);
}
