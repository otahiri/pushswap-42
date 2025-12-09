/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:56:37 by otahiri-          #+#    #+#             */
/*   Updated: 2025/12/09 12:14:57 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	calculate_cost(t_dlist **lsta, t_dlist **lstb)
{
}

void	push_all_to_b(t_dlist **lsta, t_dlist **lstb)
{
	int	size;

	size = dlst_size(*lsta);
	while (size > 3)
	{
		pb(lsta, lstb);
		size--;
	}
}

void	sort_a(t_dlist **lsta)
{
	static const int	ap[6][3] = {{1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1},
	{3, 1, 2}, {3, 2, 1}};
	int					fn;
	int					sn;
	int					tn;

	fn = (*lsta)->node->data;
	sn = (*lsta)->next->node->data;
	tn = (*lsta)->next->next->node->data;
	if (fn == ap[0][0] && sn == ap[0][1] && tn == ap[0][2])
		return ;
	else if (fn == ap[1][0] && sn == ap[1][1] && tn == ap[1][2])
		(lsta);
	else if (fn == ap[2][0] && sn == ap[2][1] && tn == ap[2][2])
		 ;
	else if (fn == ap[3][0] && sn == ap[3][1] && tn == ap[3][2])
		return ;
	else if (fn == ap[4][0] && sn == ap[4][1] && tn == ap[4][2])
		return ;
	else if (fn == ap[5][0] && sn == ap[5][1] && tn == ap[5][2])
		return ;
}
312
