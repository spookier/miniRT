/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostin <acostin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:03:18 by acostin           #+#    #+#             */
/*   Updated: 2022/12/10 15:30:47 by acostin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curr;
	t_list	*temp;

	if (*lst == NULL)
		return ;
	curr = *lst;
	while (curr)
	{
		del(curr->content);
		temp = curr;
		curr = curr->next;
		free(temp);
	}
	*lst = NULL;
}
