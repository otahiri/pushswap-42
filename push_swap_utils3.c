/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 10:39:39 by otahiri-          #+#    #+#             */
/*   Updated: 2025/12/15 11:26:42 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	rrr(t_dlist **lsta, t_dlist **lstb)
{
	if (!lstb || !*lstb || (*lstb)->next == *lstb)
		return ;
	if (!lsta || !*lsta || (*lsta)->next == *lsta)
		return ;
	*lsta = (*lsta)->previous;
	*lstb = (*lstb)->previous;
}

void	throw_error(void)
{
	ft_putstr_fd("error\n", 2);
	exit(255);
}

void	copy_dlst(t_dlist *lst, int *arr)
{
	int		i;
	t_dlist	*head;

	i = 0;
	head = lst;
	while (1)
	{
		arr[i] = lst->node->data;
		lst = lst->next;
		i++;
		if (lst == head)
			break ;
	}
}

void	sort_arr(int *sorted_list, int size)
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
			if (sorted_list[j - 1] > sorted_list[j])
			{
				tmp = sorted_list[j];
				sorted_list[j] = sorted_list[j - 1];
				sorted_list[j - 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	set_ranks(t_dlist **lsta, int *sorted_list)
{
	int		i;
	t_dlist	*dlist;

	dlist = *lsta;
	while (1)
	{
		i = 0;
		while (sorted_list[i])
		{
			if (dlist->node->data == sorted_list[i])
			{
				dlist->node->rank = i + 1;
				break ;
			}
			i++;
		}
		dlist = dlist->next;
		if (dlist == *lsta)
			break ;
	}
}
