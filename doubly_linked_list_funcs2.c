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

	if (!lst || !*lst || !(*lst)->next)
		return ;
	tail = get_last(*lst);
	if (!tail->previous)
		return ;
	tail->previous->next = NULL;
	add_front(lst, tail);
}

void	rotate_top_bottom(t_dlist **lst)
{
	t_dlist	*head;
	t_dlist	*new_head;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	head = *lst;
	new_head = head->next;
	new_head->previous = NULL;
	head->next = NULL;
	*lst = new_head;
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
