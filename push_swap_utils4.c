/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:56:37 by otahiri-          #+#    #+#             */
/*   Updated: 2025/12/13 12:04:05 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf/ft_printf.h"
#include "push_swap.h"

int	get_abs(int num)
{
	if (num < 0)
		return (-num);
	else
		return (num);
}

void	for_each_cost(t_dlist *node, t_dlist *lstb, t_dlist *lsta)
{
	int	i_a;
	int	i_b;
	int	l_a;
	int	l_b;

	i_a = 1;
	i_b = 1;
	l_a = dlst_size(lsta);
	l_b = dlst_size(lstb);
	while (lsta != node)
	{
		i_a++;
		lsta = lsta->next;
	}
	while (lstb)
	{
		i_b++;
		lstb = lstb->next;
	}
	node->node->cost_a = (i_a - l_a) * (i_a > l_a / 2) + i_a * (i_a <= l_a / 2);
	node->node->cost_b = (i_b - l_b) * (i_b > l_b / 2) + i_b * (i_b <= l_b / 2);
}

void	calculate_cost(t_dlist **lsta, t_dlist **lstb)
{
	t_dlist	*tmpa;
	t_dlist	*tmpb;

	tmpa = *lsta;
	tmpb = *lstb;
	while (tmpa)
	{
		for_each_cost(tmpa, *lstb, *lsta);
		tmpa = tmpa->next;
	}
	tmpb = *lstb;
	while (tmpb)
	{
		(tmpb) = (tmpb)->next;
	}
	ft_printf("\n");
}

void	push_three_to_b(t_dlist **lsta, t_dlist **lstb)
{
	pb(lsta, lstb);
	pb(lsta, lstb);
	pb(lsta, lstb);
}

void	apply_move(t_dlist **lsta, t_dlist **lstb)
{
	int	cheap_a;
	int	cheap_b;

	get_cheapest(*lsta, &cheap_a, &cheap_b);
	while (cheap_a != 0 || cheap_b != 0)
	{
		if (cheap_a > 0 && cheap_b > 0)
		{
			rrr(lsta, lstb);
			cheap_a--;
			cheap_b--;
		}
		else if (cheap_a < 0 || cheap_b < 0)
		{
			rr(lsta, lstb);
			cheap_a++;
			cheap_b++;
		}
		else
		{
			sep_moves(lsta, lstb, &cheap_a, &cheap_b);
		}
	}
}
