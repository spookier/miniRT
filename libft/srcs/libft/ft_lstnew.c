/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostin <acostin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:12:54 by acostin           #+#    #+#             */
/*   Updated: 2022/12/10 15:30:21 by acostin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*my_lst;

	my_lst = malloc(sizeof(t_list));
	if (!my_lst)
		return (NULL);
	my_lst->content = content;
	my_lst->next = NULL;
	return (my_lst);
}
