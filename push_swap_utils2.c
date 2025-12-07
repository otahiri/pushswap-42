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

void	ra(t_dlist **lsta)
{
	rotate_top_bottom(lsta);
}
void	rb(t_dlist **lstb)
{
	rotate_top_bottom(lstb);
}
void	rr(t_dlist **lsta, t_dlist **lstb)
{
	ra(lsta);
	rb(lstb);
}
void	rra(t_dlist **lsta)
{
	rrotate_top_bottom(lsta);
}
void	rrb(t_dlist **lstb)
{
	rrotate_top_bottom(lstb);
}
