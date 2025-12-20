/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_list_funcs1.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 10:13:39 by otahiri-          #+#    #+#             */
/*   Updated: 2025/12/16 18:12:38 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_dlist	*new_list(int num)
{
	t_dlist	*node;

	node = ft_calloc(1, sizeof(t_dlist));
	if (!node)
		return (NULL);
	node->num = num;
	return (node);
}

t_dlist	*get_last(t_dlist *lst)
{
	t_dlist	*head;

	head = lst;
	if (!lst)
		return (lst);
	lst = lst->previous;
	return (lst);
}

void	add_back(t_dlist **lst, t_dlist *node)
{
	t_dlist	*tail;
	t_dlist	*head;

	if (!lst || !*lst)
	{
		node->next = node;
		node->previous = node;
		*lst = node;
		return ;
	}
	tail = get_last(*lst);
	head = *lst;
	node->next = head;
	node->previous = tail;
	tail->next = node;
	head->previous = node;
	*lst = head;
}

void	add_front(t_dlist **lst, t_dlist *node)
{
	if (!lst || !*lst)
	{
		node->next = node;
		node->previous = node;
		*lst = node;
		return ;
	}
	(*lst)->previous->next = node;
	node->previous = (*lst)->previous;
	node->next = (*lst);
	(*lst)->previous = node;
	(*lst) = node;
}

void	swap_first_elements(t_dlist **lst)
{
	t_dlist	*head;
	t_dlist	*second;
	t_dlist	*third;

	if (!lst || !*lst || (*lst)->next == *lst)
		return ;
	head = *lst;
	second = head->next;
	if (second->next == head)
	{
		*lst = second;
		return ;
	}
	third = second->next;
	second->previous = head->previous;
	second->previous->next = second;
	second->next = head;
	head->previous = second;
	head->next = third;
	third->previous = head;
	*lst = second;
}
