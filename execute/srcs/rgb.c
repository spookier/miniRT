/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostin <acostin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:30:50 by acostin           #+#    #+#             */
/*   Updated: 2023/12/04 12:31:03 by acostin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minirt.h"

t_rgb create_rgb(double r, double g, double b)
{
    t_rgb res;

    res.r = (int)r;
    res.g = (int)g;
    res.b = (int)b;

    return (res);
}

int convert_rgb_to_int(t_rgb color)
{
	return ((color.r << 16) | (color.g << 8) | color.b);
}
