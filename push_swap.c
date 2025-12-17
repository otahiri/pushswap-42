/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 10:17:41 by otahiri-          #+#    #+#             */
/*   Updated: 2025/12/17 16:13:30 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	find_node(int idx, t_dlist *lst)
{
	int		i;
	int		size;
	t_dlist	*head;

	i = 0;
	size = dlst_size(lst);
	head = lst;
	while (lst->rank != idx)
	{
		lst = lst->next;
		i++;
		if (lst == head)
			return (-1);
	}
	if (i <= size / 2)
		return (i);
	else
		return (i - size);
}

void	push_to_a(t_dlist **lsta, t_dlist **lstb)
{
	int	size;
	int	moves;
	int	max;

	size = dlst_size(*lstb);
	while (size)
	{
		max = find_max_index(*lstb);
		moves = find_node(max, *lstb);
		if (moves < 0)
		{
			while (moves++ < 0)
				rrb(lstb);
		}
		else
		{
			while (moves-- > 0)
				rb(lstb);
		}
		pa(lsta, lstb);
		size--;
	}
}

void	pointless(int *range, int *size, int *i, t_dlist *lsta)
{
	*size = dlst_size(lsta);
	*i = 0;
	*range = (30 * (*size > 100)) + (15 * (*size <= 100));
}

void	chunks(t_dlist **lsta, t_dlist **lstb)
{
	int	range;
	int	size;
	int	i;

	pointless(&range, &size, &i, *lsta);
	while (size)
	{
		if ((*lsta)->rank <= i)
		{
			pb(lsta, lstb);
			i++;
			size--;
		}
		else if ((*lsta)->rank <= i + range)
		{
			pb(lsta, lstb);
			rb(lstb);
			i++;
			size--;
		}
		else
			ra(lsta);
	}
	push_to_a(lsta, lstb);
}

int	main(int argc, char *argv[])
{
	t_dlist	*lsta;
	t_dlist	*lstb;
	int		*sorted_arr;
	int		i;

	lsta = NULL;
	lstb = NULL;
	i = 0;
	i++;
	while (i < argc)
		parse_string(&lsta, argv[i++]);
	sorted_arr = fill_and_sort_arr(lsta);
	set_rank(&lsta, sorted_arr);
	free(sorted_arr);
	if (dlst_size(lsta) < 6)
		hard_sort(&lsta, &lstb);
	else
		chunks(&lsta, &lstb);
	free_lst(&lsta);
	free_lst(&lstb);
}
