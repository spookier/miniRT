/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostin <acostin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 08:17:33 by acostin           #+#    #+#             */
/*   Updated: 2022/12/16 21:45:26 by acostin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

int	ft_putnbr(int nb)
{
	int	len;

	len = 0;
	if (nb == -2147483648)
	{
		len += (ft_putstr("-2147483648"));
		return (len);
	}
	if (nb < 0)
	{
		len += (ft_putchar('-'));
		nb = -nb;
	}
	if (nb > 9)
	{
		len += (ft_putnbr(nb / 10));
		len += (ft_putnbr(nb % 10));
	}
	else
		len += (ft_putchar(nb + 48));
	return (len);
}
