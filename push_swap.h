/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:07:56 by otahiri-          #+#    #+#             */
/*   Updated: 2025/12/17 16:13:26 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./ft_printf/ft_printf.h"

typedef struct s_dlist
{
	struct s_dlist	*next;
	struct s_dlist	*previous;
	int				num;
	int				rank;
}					t_dlist;

t_dlist				*new_list(int num);
t_dlist				*get_last(t_dlist *lst);
void				add_back(t_dlist **lst, t_dlist *node);
void				add_front(t_dlist **lst, t_dlist *node);
void				swap_first_elements(t_dlist **lst);
void				rrotate_top_bottom(t_dlist **lst);
void				rotate_top_bottom(t_dlist **lst);
int					dlst_size(t_dlist *lst);
void				ra(t_dlist **lsta);
void				rb(t_dlist **lstb);
void				rr(t_dlist **lsta, t_dlist **lstb);
void				rra(t_dlist **lsta);
void				rrb(t_dlist **lstb);
void				rrr(t_dlist **lsta, t_dlist **lstb);
void				sa(t_dlist **lst);
void				sb(t_dlist **lst);
void				ss(t_dlist **lsta, t_dlist **lstb);
void				pa(t_dlist **lsta, t_dlist **lstb);
void				pb(t_dlist **lsta, t_dlist **lstb);
void				throw_error(t_dlist **lst, char **str);
long				custom_atoi(const char *nptr);
int					check_nums(char *num);
void				parse_string(t_dlist **lsta, char *nums);
int					ft_is_a_sorted(t_dlist *lst);
void				sort_arr(int *sorted_arr, int size);
int					*fill_and_sort_arr(t_dlist *lst);
void				set_rank(t_dlist **lst, int *arr);
void				free_all(char **str);
void				free_lst(t_dlist **lst);
void				chunks(t_dlist **lsta, t_dlist **lstb);
int					is_sep(char c, char *set);
char				**custom_split(char const *s, char *set);
int					find_node(int idx, t_dlist *lst);
void				sort_three(t_dlist **lst);
void				apply_moves(int moves, t_dlist **lst);
void				sort_more_than_three(t_dlist **lsta, t_dlist **lstb);
int					find_max_index(t_dlist *lst);
void				hard_sort(t_dlist **lsta, t_dlist **lstb);

#endif
