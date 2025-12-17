/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils6.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 12:38:28 by otahiri-          #+#    #+#             */
/*   Updated: 2025/12/17 16:10:08 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sort_three(t_dlist **lst)
{
	int	a;
	int	b;
	int	c;

	a = (*lst)->num;
	b = (*lst)->next->num;
	c = (*lst)->next->next->num;
	if (a < b && b < c && a < c)
		return ;
	else if (a < b && b > c && a < c)
	{
		sa(lst);
		ra(lst);
	}
	else if (a > b && b > c && a > c)
	{
		sa(lst);
		rra(lst);
	}
	else if (a > b && b < c && a > c)
		ra(lst);
	else if (a > b && b < c && a < c)
		sa(lst);
	else if (a < b && b > c && a > c)
		rra(lst);
}

void	apply_moves(int moves, t_dlist **lst)
{
	if (moves > 0)
	{
		while (moves > 0)
		{
			ra(lst);
			moves--;
		}
	}
	else
	{
		while (moves < 0)
		{
			rra(lst);
			moves++;
		}
	}
}

void	sort_more_than_three(t_dlist **lsta, t_dlist **lstb)
{
	int	moves;
	int	idx;

	idx = 0;
	while (dlst_size(*lsta) > 3)
	{
		moves = find_node(idx, *lsta);
		apply_moves(moves, lsta);
		pb(lsta, lstb);
		idx++;
	}
	sort_three(lsta);
	while (dlst_size(*lstb))
		pa(lsta, lstb);
}

void	hard_sort(t_dlist **lsta, t_dlist **lstb)
{
	int	size;

	size = dlst_size(*lsta);
	if (size <= 1)
		return ;
	else if (size == 2)
	{
		if ((*lsta)->num > (*lsta)->next->num)
			sa(lsta);
	}
	else if (size == 3)
		sort_three(lsta);
	else
		sort_more_than_three(lsta, lstb);
}

void	sort_arr(int *sorted_arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = 1;
		while (j < size)
		{
			if (sorted_arr[j - 1] > sorted_arr[j])
			{
				tmp = sorted_arr[j];
				sorted_arr[j] = sorted_arr[j - 1];
				sorted_arr[j - 1] = tmp;
			}
			j++;
		}
		i++;
	}
}
