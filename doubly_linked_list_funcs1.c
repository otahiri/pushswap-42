/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_list_funcs1.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 10:13:39 by otahiri-          #+#    #+#             */
/*   Updated: 2025/12/06 11:58:27 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlist	*new_list(int num)
{
	t_dlist	*node;

	node = ft_calloc(1, sizeof(t_dlist));
	node->node = ft_calloc(1, sizeof(t_node));
	node->node->data = num;
	return (node);
}

t_dlist	*get_last(t_dlist *lst)
{
	if (!lst || !lst->next)
		return (lst);
	while (lst->next)
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
		*lst = node;
		return ;
	}
	last = get_last(*lst);
	last->next = node;
	node->previous = last;
	node->next = NULL;
}

void	add_front(t_dlist **lst, t_dlist *node)
{
	t_dlist	*last;

	if (!node || !lst)
		return ;
	if (!*lst)
	{
		node->next = NULL;
		node->previous = NULL;
		*lst = node;
		return ;
	}
	node->previous = NULL;
	node->next = *lst;
	(*lst)->previous = node;
	*lst = node;
}

void	swap_last_elements(t_dlist **lst)
{
	t_dlist	*last;
	t_dlist	*blast;
	t_dlist	*head;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	head = *lst;
	last = get_last(*lst);
	blast = last->previous;
	if (!blast->previous)
	{
		blast->next = NULL;
		last->previous = NULL;
		last->next = blast;
		blast->previous = last;
		*lst = last;
		return ;
	}
	last->next = blast;
	blast->next = NULL;
	last->previous = blast->previous;
	last->previous->next = last;
	blast->previous = last;
}
