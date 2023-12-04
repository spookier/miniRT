/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostin <acostin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:30:42 by acostin           #+#    #+#             */
/*   Updated: 2023/12/04 12:30:43 by acostin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minirt.h"

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_all *all;

	all = NULL;
	if(alloc_struct_mem(&all) == -1)
		exit_prog(all, "Error - Malloc failed");
	init_vars(all);

	start_mlx(all);
	
	exit_prog(all, NULL);

	return (0);
}