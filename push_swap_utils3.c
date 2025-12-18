/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 10:39:39 by otahiri-          #+#    #+#             */
/*   Updated: 2025/12/16 18:21:11 by otahiri-         ###   ########.fr       */
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
	ft_printf("rrr\n");
}

void	throw_error(t_dlist **lst, char **str)
{
	free_lst(lst);
	free_all(str);
	write(2, "Error\n", 6);
	exit(1);
}
