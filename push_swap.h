/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 10:20:06 by otahiri-          #+#    #+#             */
/*   Updated: 2025/12/07 10:43:33 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./ft_printf/ft_printf.h"

typedef struct s_node
{
	int				data;
	int				rank;
}					t_node;

typedef struct s_dlist
{
	struct s_dlist	*next;
	struct s_dlist	*previous;
	t_node			*node;
}					t_dlist;

t_dlist				*new_list(int num);
t_dlist				*get_last(t_dlist *lst);
void				add_back(t_dlist **lst, t_dlist *node);
void				add_front(t_dlist **lst, t_dlist *node);
void				swap_last_elements(t_dlist **lst);
void				rotate_top_bottom(t_dlist **lst);
void				rrotate_top_bottom(t_dlist **lst);
void				sa(t_dlist **lst);
void				sb(t_dlist **lst);
void				ss(t_dlist **lsta, t_dlist **lstb);
void				pa(t_dlist **lsta, t_dlist **lstb);
void				pb(t_dlist **lsta, t_dlist **lstb);
void				ra(t_dlist **lsta);
void				rb(t_dlist **lstb);
void				rr(t_dlist **lsta, t_dlist **lstb);
void				rra(t_dlist **lsta);
void				rrb(t_dlist **lstb);
void				rrr(t_dlist **lsta, t_dlist **lstb);

#endif
