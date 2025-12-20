/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:49:27 by otahiri-          #+#    #+#             */
/*   Updated: 2025/12/17 16:49:59 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_checker_bonus.h"

void	sa(t_dlist **lsta, t_dlist **lstb)
{
	(void)lstb;
	swap_first_elements(lsta);
}

void	sb(t_dlist **lsta, t_dlist **lstb)
{
	(void)lsta;
	swap_first_elements(lstb);
}

void	ss(t_dlist **lsta, t_dlist **lstb)
{
	swap_first_elements(lsta);
	swap_first_elements(lstb);
}

void	pa(t_dlist **lsta, t_dlist **lstb)
{
	t_dlist	*node;

	if (!lstb || !*lstb)
		return ;
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

	if (!lsta || !*lsta)
		return ;
	node = *lsta;
	if (node->next == node)
		*lsta = NULL;
	else
	{
		node->previous->next = node->next;
		node->next->previous = node->previous;
		*lsta = node->next;
	}
	node->next = node;
	node->previous = node;
	add_front(lstb, node);
}
