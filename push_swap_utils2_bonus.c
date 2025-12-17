/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:48:48 by otahiri-          #+#    #+#             */
/*   Updated: 2025/12/17 16:50:14 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_checker_bonus.h"

void	ra(t_dlist **lsta)
{
	if (!lsta || !*lsta || (*lsta)->next == *lsta)
		return ;
	*lsta = (*lsta)->next;
}

void	rb(t_dlist **lstb)
{
	if (!lstb || !*lstb || (*lstb)->next == *lstb)
		return ;
	*lstb = (*lstb)->next;
}

void	rr(t_dlist **lsta, t_dlist **lstb)
{
	if (!lstb || !*lstb || (*lstb)->next == *lstb)
		return ;
	if (!lsta || !*lsta || (*lsta)->next == *lsta)
		return ;
	*lsta = (*lsta)->next;
	*lstb = (*lstb)->next;
}

void	rra(t_dlist **lsta)
{
	if (!lsta || !*lsta || (*lsta)->next == *lsta)
		return ;
	*lsta = (*lsta)->previous;
}

void	rrb(t_dlist **lstb)
{
	if (!lstb || !*lstb || (*lstb)->next == *lstb)
		return ;
	*lstb = (*lstb)->previous;
}
