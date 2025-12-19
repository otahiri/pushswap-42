/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:49:02 by otahiri-          #+#    #+#             */
/*   Updated: 2025/12/17 17:12:15 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_checker_bonus.h"

void	rrr(t_dlist **lsta, t_dlist **lstb)
{
	if (!lstb || !*lstb || (*lstb)->next == *lstb)
		return ;
	if (!lsta || !*lsta || (*lsta)->next == *lsta)
		return ;
	*lsta = (*lsta)->previous;
	*lstb = (*lstb)->previous;
}

void	free_all(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	if (!*str)
	{
		free(str);
		return ;
	}
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str[i]);
	free(str);
}

void	free_lst(t_dlist **lst)
{
	t_dlist	*head;
	t_dlist	*current;
	t_dlist	*next;

	if (lst && *lst)
	{
		head = *lst;
		current = head->next;
		while (current != head)
		{
			next = current->next;
			free(current);
			current = next;
		}
		free(head);
		*lst = NULL;
	}
}

void	throw_error(t_dlist **lst, char **str)
{
	free_lst(lst);
	free_all(str);
	write(2, "Error\n", 6);
	exit(1);
}

int	is_sep(char c, char *set)
{
	if (c == *set || c == *(set + 1))
		return (1);
	return (0);
}
