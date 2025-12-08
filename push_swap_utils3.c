/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 10:39:39 by otahiri-          #+#    #+#             */
/*   Updated: 2025/12/07 10:43:28 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	rrr(t_dlist **lsta, t_dlist **lstb)
{
	rra(lsta);
	rrb(lstb);
}

void	throw_error(void)
{
	ft_putstr_fd("error\n", 2);
	exit(255);
}

void	copy_dlst(t_dlist *lst, int **arr)
{
	int	i;

	i = 0;
	while (lst)
	{
		*arr[i] = lst->node->data;
		lst = lst->next;
		i++;
	}
}

void	sort_arr(int **sorted_list, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			j++;
		}
	}
}
