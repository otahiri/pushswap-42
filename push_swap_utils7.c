/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils7.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:09:42 by otahiri-          #+#    #+#             */
/*   Updated: 2025/12/17 16:10:48 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	*fill_and_sort_arr(t_dlist *lst)
{
	int	*sorted_arr;
	int	i;
	int	size;

	size = dlst_size(lst);
	sorted_arr = malloc(size * sizeof(int));
	i = 0;
	while (i < size)
	{
		sorted_arr[i++] = lst->num;
		lst = lst->next;
	}
	sort_arr(sorted_arr, size);
	return (sorted_arr);
}

void	set_rank(t_dlist **lst, int *arr)
{
	int		i;
	int		size;
	t_dlist	*tmp;
	t_dlist	*head;

	i = 0;
	head = *lst;
	size = dlst_size(*lst);
	while (i < size)
	{
		tmp = *lst;
		while (1)
		{
			if (tmp->num == arr[i])
			{
				tmp->rank = i;
				break ;
			}
			tmp = tmp->next;
			if (tmp == head)
				break ;
		}
		i++;
	}
}

int	find_max_index(t_dlist *lst)
{
	int		max;
	t_dlist	*head;

	head = lst;
	max = 0;
	while (1)
	{
		if (lst->rank > max)
			max = lst->rank;
		lst = lst->next;
		if (lst == head)
			break ;
	}
	return (max);
}
