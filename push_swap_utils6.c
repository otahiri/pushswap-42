/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils6.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 10:43:20 by otahiri-          #+#    #+#             */
/*   Updated: 2025/12/15 11:08:26 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	get_node_idx(t_dlist *lst, t_dlist *node)
{
	int	idx;
	int	size;

	idx = 0;
	size = dlst_size(lst);
	while (lst != node)
	{
		lst = lst->next;
		idx++;
		if (idx == size)
			break ;
	}
	return (idx);
}

int	get_lstb_cost(t_dlist *lstb, t_dlist *node)
{
	int		i_b;
	t_dlist	*start;

	start = lstb;
	i_b = 0;
	while (1)
	{
		if (lstb->node->data < node->node->data
			&& node->node->data < lstb->next->node->data)
			break ;
		if (lstb->node->data > lstb->next->node->data
			&& (node->node->data > lstb->node->data
				|| node->node->data < lstb->next->node->data))
			break ;
		lstb = lstb->next;
		i_b++;
		if (lstb == start)
			break ;
	}
	return (i_b);
}
