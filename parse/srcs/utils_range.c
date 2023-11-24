/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_range.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:17:24 by yhwang            #+#    #+#             */
/*   Updated: 2023/11/21 17:29:47 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT_parse.h"

int	check_int(int i, int min, int max)
{
	if (i == ERR_ATOI)
		return (1);
	if (min == 0 && max == 0)
		return (0);
	if (!(min <= i && i <= max))
		return (1);
	return (0);
}

int	check_double(double d, double min, double max)
{
	if (d == ERR_ATOD)
		return (1);
	if (min == 0 && max == 0)
		return (0);
	if (!(min <= d && d <= max))
		return (1);
	return (0);
}

int	check_rgb(int r, int g, int b)
{
	if (r == ERR_ATOI || g == ERR_ATOI || b == ERR_ATOI)
		return (1);
	if (!(0 <= r && r <= 255) || !(0 <= g && g <= 255) || !(0 <= b && b <= 255))
		return (1);
	return (0);
}

int	check_xyz_pos(double x, double y, double z)
{
	if (x == ERR_ATOD || y == ERR_ATOD || z == ERR_ATOD)
		return (1);
	return (0);
}

int	check_xyz_vec(double x, double y, double z)
{
	if (x == ERR_ATOD || y == ERR_ATOD || z == ERR_ATOD)
		return (1);
	if (!(-1 <= x && x <= 1) || !(-1 <= y && y <= 1) || !(-1 <= z && z <= 1))
		return (1);
	if (!(1 - EPSILON < sqrt(x * x + y * y + z * z)
			&& sqrt(x * x + y * y + z * z) < 1 + EPSILON))
		return (1);
	return (0);
}
