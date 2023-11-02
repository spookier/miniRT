/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostin <acostin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 08:17:38 by acostin           #+#    #+#             */
/*   Updated: 2022/12/14 08:19:43 by acostin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

int	ft_hexa(unsigned long nb, int sign)
{
	int	len;

	len = 0;
	if (nb >= 16)
		len += ft_hexa(nb / 16, sign);
	if (nb % 16 < 10)
		len += ft_putchar((nb % 16) + 48);
	else
	{
		if (sign == 1)
			len += ft_putchar((nb % 16) + 87);
		else
			len += ft_putchar((nb % 16) + 55);
	}
	return (len);
}
