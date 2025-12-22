/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:48:40 by otahiri-          #+#    #+#             */
/*   Updated: 2025/12/22 09:12:34 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHECKER_BONUS_H
# define FT_CHECKER_BONUS_H

# include "ft_printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_dlist
{
	struct s_dlist	*next;
	struct s_dlist	*previous;
	int				num;
	int				rank;
}					t_dlist;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 400000
# endif

char				*get_next_line(int fd);
char				*my_strchr(const char *s, int c);
char				*my_strjoin(char *s1, char *s2);
size_t				my_strlen(const char *s);
char				*my_strdup(char *s);
char				*my_substr(char const *s, unsigned int start, size_t len);
size_t				my_strlen_new_line(const char *s);
size_t				find_nl(const char *s);
char				*read_from_fd(int fd, char *left_over);
void				*my_free(void **ptr);
char				*find_next_nl(char *buffer, int fd, char *temp_buffer);
t_dlist				*new_list(int num);
t_dlist				*get_last(t_dlist *lst);
void				add_back(t_dlist **lst, t_dlist *node);
void				add_front(t_dlist **lst, t_dlist *node);
void				swap_first_elements(t_dlist **lst);
void				rrotate_top_bottom(t_dlist **lst);
void				rotate_top_bottom(t_dlist **lst);
int					dlst_size(t_dlist *lst);
void				free_lst(t_dlist **lst);
void				ra(t_dlist **lsta, t_dlist **lstb);
void				rb(t_dlist **lsta, t_dlist **lstb);
void				rr(t_dlist **lsta, t_dlist **lstb);
void				rra(t_dlist **lsta, t_dlist **lstb);
void				rrb(t_dlist **lsta, t_dlist **lstb);
void				rrr(t_dlist **lsta, t_dlist **lstb);
void				sa(t_dlist **lsta, t_dlist **lstb);
void				sb(t_dlist **lsta, t_dlist **lstb);
void				ss(t_dlist **lsta, t_dlist **lstb);
void				pa(t_dlist **lsta, t_dlist **lstb);
void				pb(t_dlist **lsta, t_dlist **lstb);
void				free_all(char **str);
void				free_lst(t_dlist **lst);
void				throw_error(t_dlist **lst, char **str);
int					is_sep(char c, char *set);
char				**custom_split(char const *s, char *set);
long				custom_atoi(const char *nptr);
int					check_nums(char *num);
void				parse_string(t_dlist **lsta, char *nums);
int					ft_is_a_sorted(t_dlist *lst);
int					my_str_cmp(char *s1, char *s2);
int					get_idx(char *func);
void				use_funcs(int *funcs_idx, int size, t_dlist **lsta,
						t_dlist **lstb);
int					*get_func_idx(int *size);
void				apply_funcs(t_dlist **lsta, t_dlist **lstb);
void				check_dups(t_dlist **lsta);

#endif
