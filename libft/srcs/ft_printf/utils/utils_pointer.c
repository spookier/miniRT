/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostin <acostin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 08:17:43 by acostin           #+#    #+#             */
/*   Updated: 2022/12/14 08:20:26 by acostin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

static int	ft_putpointer(unsigned long nb)
{
	int	len;

	len = 0;
	if (nb >= 16)
		len += ft_putpointer(nb / 16);
	if (nb % 16 < 10)
		len += ft_putchar((nb % 16) + 48);
	else
	{
		len += ft_putchar((nb % 16) + 87);
	}
	return (len);
}

int	ft_putpointer_check(unsigned long nb)
{
	if (!nb)
	{
		ft_putstr("(nil)");
		return (5);
	}
	else
	{
		ft_putstr("0x");
		return (2 + ft_putpointer(nb));
	}
}
