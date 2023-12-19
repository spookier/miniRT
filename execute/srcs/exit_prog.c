/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_prog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:10:34 by acostin           #+#    #+#             */
/*   Updated: 2023/12/19 01:09:28 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minirt.h"

void	exit_prog(t_all *all, char *str)
{
	if (!all)
		exit(1);
	if (str)
		printf("%s\n", str);
	free_mem(all);
	exit(0);
}

int	mlx_exit(t_all *all)
{
	free_mem(all);
	exit(0);
}
