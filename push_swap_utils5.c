/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:31:17 by otahiri-          #+#    #+#             */
/*   Updated: 2025/12/16 17:33:05 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	free_all(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str[i]);
	free(str);
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
				rrb(lsta, lstb);
		}
		else
		{
			while (moves-- > 0)
				rb(lsta, lstb);
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
			rb(lsta, lstb);
			i++;
			size--;
		}
		else
			ra(lsta, lstb);
	}
	push_to_a(lsta, lstb);
}
