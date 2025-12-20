/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_list_funcs2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 10:12:49 by otahiri-          #+#    #+#             */
/*   Updated: 2025/12/16 18:19:40 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	rrotate_top_bottom(t_dlist **lst)
{
	t_dlist	*tail;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	tail = get_last(*lst);
	if (!tail->previous)
		return ;
	tail->previous->next = NULL;
	add_front(lst, tail);
}

void	rotate_top_bottom(t_dlist **lst)
{
	t_dlist	*head;
	t_dlist	*new_head;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	head = *lst;
	new_head = head->next;
	new_head->previous = NULL;
	head->next = NULL;
	*lst = new_head;
	add_back(lst, head);
}

int	dlst_size(t_dlist *lst)
{
	int		i;
	t_dlist	*head;

	i = 0;
	if (!lst)
		return (0);
	head = lst;
	while (1)
	{
		i++;
		lst = lst->next;
		if (lst == head)
			break ;
	}
	return (i);
}

int	my_str_cmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}
