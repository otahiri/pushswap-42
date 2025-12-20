/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 10:38:29 by otahiri-          #+#    #+#             */
/*   Updated: 2025/12/07 10:43:25 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ra(t_dlist **lsta, t_dlist **lstb)
{
	(void)lstb;
	if (!lsta || !*lsta || (*lsta)->next == *lsta)
		return ;
	*lsta = (*lsta)->next;
	ft_printf("ra\n");
}

void	rb(t_dlist **lsta, t_dlist **lstb)
{
	(void)lsta;
	if (!lstb || !*lstb || (*lstb)->next == *lstb)
		return ;
	*lstb = (*lstb)->next;
	ft_printf("rb\n");
}

void	rr(t_dlist **lsta, t_dlist **lstb)
{
	if (!lstb || !*lstb || (*lstb)->next == *lstb)
		return ;
	if (!lsta || !*lsta || (*lsta)->next == *lsta)
		return ;
	*lsta = (*lsta)->next;
	*lstb = (*lstb)->next;
	ft_printf("rr\n");
}

void	rra(t_dlist **lsta, t_dlist **lstb)
{
	(void)lstb;
	if (!lsta || !*lsta || (*lsta)->next == *lsta)
		return ;
	*lsta = (*lsta)->previous;
	ft_printf("rra\n");
}

void	rrb(t_dlist **lsta, t_dlist **lstb)
{
	(void)lsta;
	if (!lstb || !*lstb || (*lstb)->next == *lstb)
		return ;
	*lstb = (*lstb)->previous;
	ft_printf("rrb\n");
}
