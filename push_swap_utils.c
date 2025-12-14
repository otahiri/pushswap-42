/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 11:11:29 by otahiri-          #+#    #+#             */
/*   Updated: 2025/12/13 11:19:38 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sa(t_dlist **lst)
{
	swap_last_elements(lst);
}

void	sb(t_dlist **lst)
{
	swap_last_elements(lst);
}

void	ss(t_dlist **lsta, t_dlist **lstb)
{
	swap_last_elements(lsta);
	swap_last_elements(lstb);
}

void	pa(t_dlist **lsta, t_dlist **lstb)
{
	t_dlist	*last_of_b;

	if (!(*lstb))
		return ;
	last_of_b = get_last(*lstb);
	if (!last_of_b->previous)
	{
		*lstb = NULL;
		add_back(lsta, last_of_b);
	}
	else
	{
		last_of_b->previous->next = NULL;
		add_back(lsta, last_of_b);
	}
}

void	pb(t_dlist **lsta, t_dlist **lstb)
{
	t_dlist	*last_of_a;

	if (!(*lsta))
		return ;
	last_of_a = get_last(*lsta);
	if (!last_of_a->previous)
	{
		last_of_a->previous = NULL;
		*lsta = NULL;
		add_back(lstb, last_of_a);
	}
	else
	{
		last_of_a->previous->next = NULL;
		last_of_a->previous = NULL;
		add_back(lstb, last_of_a);
	}
}
