/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 10:20:06 by otahiri-          #+#    #+#             */
/*   Updated: 2025/12/09 11:03:32 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./ft_printf/ft_printf.h"
# include <limits.h>

typedef struct s_node
{
	int				data;
	int				rank;
	int				cost_a_ra;
	int				cost_b_rb;
	int				cost_a_rra;
	int				cost_b_rrb;
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
int					custom_atoi(const char *nptr);
int					check_nums(char *num);
void				parse_string(t_dlist **lsta, char *nums);
void				throw_error(void);
int					dlst_size(t_dlist *lst);
void				copy_dlst(t_dlist *lst, int *arr);
void				sort_arr(int *sorted_list, int size);
void				set_ranks(t_dlist **lsta, int *sorted_list);
void				push_all_to_b(t_dlist **lsta, t_dlist **lstb);
void				calculate_cost(t_dlist **lsta, t_dlist **lstb);
void				set_cost(t_dlist **lst, int size, int idxa, int idxb);
void				for_each_cost(t_dlist *node, t_dlist **lstb,
						t_dlist **lsta);
void				calculate_cost(t_dlist **lsta, t_dlist **lstb);

#endif
