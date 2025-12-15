/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 10:20:06 by otahiri-          #+#    #+#             */
/*   Updated: 2025/12/15 11:53:28 by otahiri-         ###   ########.fr       */
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
	int				cost_a;
	int				cost_b;
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
void				swap_first_elements(t_dlist **lst);
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
void				for_each_cost(t_dlist *node, t_dlist *lstb, t_dlist *lsta);
void				calculate_cost(t_dlist **lsta, t_dlist **lstb);
int					get_abs(int num);
void				push_three_to_b(t_dlist **lsta, t_dlist **lstb);
void				get_cheapest(t_dlist *lst, int *cost_a, int *cost_b);
void				sep_moves(t_dlist **lsta, t_dlist **lstb, int *cheap_a,
						int *cheap_b);
void				apply_move(t_dlist **lsta, t_dlist **lstb);
void				sort_b(t_dlist **lstb);
void				print_list(t_dlist *lst);
t_dlist				*get_biggest_num(t_dlist *lst);
int					get_node_idx(t_dlist *lst, t_dlist *node);
int					get_lstb_cost(t_dlist *lstb, t_dlist *node);

#endif
