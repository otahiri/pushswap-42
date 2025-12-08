/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_list_funcs2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 10:12:49 by otahiri-          #+#    #+#             */
/*   Updated: 2025/12/07 11:00:05 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	rrotate_top_bottom(t_dlist **lst)
{
	t_dlist	*tail;

	tail = get_last(*lst);
	tail->previous->next = NULL;
	add_front(lst, tail);
}

void	rotate_top_bottom(t_dlist **lst)
{
	t_dlist	*head;

	head = *lst;
	head->next->previous = NULL;
	*lst = head->next;
	add_back(lst, head);
}

int	dlst_size(t_dlist *lst)
{
	int	i;

	if (!lst)
		return (0);
	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
