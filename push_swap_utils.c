/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 11:11:29 by otahiri-          #+#    #+#             */
/*   Updated: 2025/12/17 16:46:21 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sa(t_dlist **lsta, t_dlist **lstb)
{
	(void)lstb;
	swap_first_elements(lsta);
	ft_printf("sa\n");
}

void	sb(t_dlist **lsta, t_dlist **lstb)
{
	(void)lsta;
	swap_first_elements(lstb);
	ft_printf("sb\n");
}

void	ss(t_dlist **lsta, t_dlist **lstb)
{
	swap_first_elements(lsta);
	swap_first_elements(lstb);
	ft_printf("ss\n");
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
	ft_printf("pa\n");
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
	ft_printf("pb\n");
}
