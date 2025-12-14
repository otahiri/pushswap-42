/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_list_funcs1.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 10:13:39 by otahiri-          #+#    #+#             */
/*   Updated: 2025/12/13 11:20:33 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlist	*new_list(int num)
{
	t_dlist	*node;

	node = ft_calloc(1, sizeof(t_dlist));
	if (!node)
		return (NULL);
	node->node = ft_calloc(1, sizeof(t_node));
	if (!node->node)
		return (free(node), NULL);
	node->node->data = num;
	return (node);
}

t_dlist	*get_last(t_dlist *lst)
{
	t_dlist	*head;

	head = lst;
	if (!lst)
		return (lst);
	while (lst->next != head)
		lst = lst->next;
	return (lst);
}

void	add_back(t_dlist **lst, t_dlist *node)
{
	t_dlist	*last;

	if (!node || !lst)
		return ;
	if (!*lst)
	{
		node->next = node;
		node->previous = node;
		*lst = node;
		return ;
	}
	last = get_last(*lst);
	last->next = node;
	node->previous = last;
	node->next = *lst;
}

void	add_front(t_dlist **lst, t_dlist *node)
{
	t_dlist	*last;

	if (!node || !lst)
		return ;
	if (!*lst)
	{
		node->next = node;
		node->previous = node;
		*lst = node;
		return ;
	}
	node->previous = get_last(*lst);
	node->next = *lst;
	(*lst)->previous = node;
	*lst = node;
}

void	swap_last_elements(t_dlist **lst)
{
	t_dlist	*tail;
	t_dlist	*btail;
	int		size;

	size = dlst_size(*lst);
	if (size < 2)
		return ;
	else if (size == 2)
	{
		*lst = (*lst)->next;
	}
	tail = get_last(*lst);
	btail = tail->previous;
	btail->previous->next = *lst;
	add_back(lst, tail);
	add_back(lst, btail);
}
