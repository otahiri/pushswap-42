/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 11:11:29 by otahiri-          #+#    #+#             */
/*   Updated: 2025/12/07 10:43:22 by otahiri-         ###   ########.fr       */
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

	last_of_b = get_last(*lstb);
	last_of_b->previous->next = NULL;
	add_back(lsta, last_of_b);
}
void	pb(t_dlist **lsta, t_dlist **lstb)
{
	t_dlist	*last_of_a;

	last_of_a = get_last(*lsta);
	last_of_a->previous->next = NULL;
	add_back(lstb, last_of_a);
}
