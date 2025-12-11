/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:56:37 by otahiri-          #+#    #+#             */
/*   Updated: 2025/12/09 12:14:57 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf/ft_printf.h"
#include "push_swap.h"

void	set_cost(t_dlist **lst, int size, int idxa, int idxb)
{
	if (idxa > (size / 2))
		(*lst)->node->cost_a_ra = idxa;
	else
		(*lst)->node->cost_a_rra = idxa;
	if (idxb > (size / 2))
		(*lst)->node->cost_b_rb = idxb;
	else
		(*lst)->node->cost_b_rrb = idxb;
}

void	for_each_cost(t_dlist *node, t_dlist **lstb, t_dlist **lsta)
{
	int		size;
	int		idx_a;
	int		idx_b;
	t_dlist	*tmpa;
	t_dlist	*tmpb;

	tmpa = *lsta;
	tmpb = *lstb;
	size = dlst_size(*lsta);
	idx_a = 0;
	idx_b = 0;
	while (tmpa != node)
	{
		idx_a++;
		tmpa = tmpa->next;
	}
	ft_printf("%d\n", idx_a);
	while (tmpb && tmpb->node->rank < node->node->rank)
	{
		idx_b++;
		tmpb = tmpb->next;
	}
	set_cost(&node, size, idx_a, idx_b);
}

void	calculate_cost(t_dlist **lsta, t_dlist **lstb)
{
	t_dlist	*tmpa;
	t_dlist	*tmpb;

	tmpa = *lsta;
	tmpb = *lstb;
	while (tmpa)
	{
		for_each_cost(tmpa, lstb, lsta);
		tmpa = tmpa->next;
	}
}
