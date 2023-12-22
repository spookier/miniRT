/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_prog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:10:34 by acostin           #+#    #+#             */
/*   Updated: 2023/12/22 15:23:42 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minirt.h"

void	exit_prog(t_all *all, char *str)
{
	if (!all)
		exit(1);
	if (str)
		printf("%s%s%s\n", RED, str, BLACK);
	free_mem(all);
	exit(0);
}

int	mlx_exit(t_all *all)
{
	free_mem(all);
	exit(0);
}
