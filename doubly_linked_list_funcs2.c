/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_list_funcs2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 10:12:49 by otahiri-          #+#    #+#             */
/*   Updated: 2025/12/06 11:15:04 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	rrotate_top_bottom(t_dlist **lst)
{
	t_dlist	*tail;

	tail = get_last(*lst);
	tail->previous->next = NULL;
	add_front(lst, tail);
}

void	rotate_top_bottom(t_dlist **lst)
{
	t_dlist	*head;

	head = *lst;
	head->next->previous = NULL;
	*lst = head->next;
	add_back(lst, head);
}
