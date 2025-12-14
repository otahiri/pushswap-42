/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 09:38:41 by otahiri-          #+#    #+#             */
/*   Updated: 2025/12/13 11:53:43 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "push_swap.h"

void	print_list(t_dlist *lst)
{
	while (lst)
	{
		ft_printf("%d\n", lst->node->data);
		lst = lst->next;
	}
}

void	get_cheapest(t_dlist *lst, int *cost_a, int *cost_b)
{
	int	total;

	*cost_a = lst->node->cost_a;
	*cost_b = lst->node->cost_b;
	while (lst)
	{
		total = get_abs(*cost_b) + get_abs(*cost_a);
		if (get_abs(lst->node->cost_a) + get_abs(lst->node->cost_b) < total)
		{
			*cost_a = lst->node->cost_a;
			*cost_b = lst->node->cost_b;
		}
		lst = lst->next;
	}
}

void	sep_moves(t_dlist **lsta, t_dlist **lstb, int *cheap_a, int *cheap_b)
{
	if (*cheap_a < 0)
	{
		rra(lsta);
		(*cheap_a)++;
	}
	else if (*cheap_a > 0)
	{
		ra(lsta);
		(*cheap_a)--;
	}
	if (*cheap_b < 0)
	{
		rrb(lstb);
		(*cheap_b)++;
	}
	else if (*cheap_b > 0)
	{
		rb(lstb);
		(*cheap_b)--;
	}
}

void	sort_b(t_dlist **lstb)
{
	int	first;
	int	second;
	int	third;

	first = (*lstb)->node->rank;
	second = (*lstb)->next->node->rank;
	third = (*lstb)->next->next->node->rank;
	if (first < second && second < third && first < third)
		return ;
	else if (first < second && second > third && first < third)
	{
		rb(lstb);
		sb(lstb);
	}
	else if (first > second && second < third && first < third)
		sb(lstb);
	else if (first < second && second > third && first > third)
		rb(lstb);
	else if (first > second && second > third && first > third)
	{
		sb(lstb);
		rb(lstb);
	}
	else if (first > second && second < third && first > third)
		rrb(lstb);
}
