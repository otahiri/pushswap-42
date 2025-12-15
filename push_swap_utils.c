/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 11:11:29 by otahiri-          #+#    #+#             */
/*   Updated: 2025/12/15 11:40:21 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sa(t_dlist **lst)
{
	swap_first_elements(lst);
}

void	sb(t_dlist **lst)
{
	swap_first_elements(lst);
}

void	ss(t_dlist **lsta, t_dlist **lstb)
{
	swap_first_elements(lsta);
	swap_first_elements(lstb);
}

void	pa(t_dlist **lsta, t_dlist **lstb)
{
	t_dlist	*node;

	node = *lstb;
	if (node->next == node)
		*lstb = NULL;
	else
	{
		node->previous->next = node->next;
		node->next->previous = node->previous;
		*lstb = node->next;
	}
	add_front(lsta, node);
}

void	pb(t_dlist **lsta, t_dlist **lstb)
{
	t_dlist	*node;

	node = *lsta;
	if (node->next == node)
		*lsta = NULL;
	else
	{
		node->previous->next = node->next;
		node->next->previous = node->previous;
		*lsta = node->next;
	}
	add_front(lstb, node);
}
