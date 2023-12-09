/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostin <acostin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 21:48:34 by acostin           #+#    #+#             */
/*   Updated: 2023/12/09 21:48:35 by acostin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minirt.h"

int	key_hook(int keycode, t_all *all)
{
	if (keycode == KEY_ESC)
		exit_prog(all, NULL);
	return (0);
}
