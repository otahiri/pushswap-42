/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:40:20 by otahiri-          #+#    #+#             */
/*   Updated: 2025/12/18 09:32:03 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_checker_bonus.h"

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

int	get_idx(char *func)
{
	static char	*func_names[11] = {"sa\n", "sb\n", "ss\n", "pa\n", "pb\n",
		"ra\n", "rb\n", "rr\n", "rra\n", "rrb\n", "rrr\n"};
	int			i;

	i = 0;
	while (i < 11)
	{
		if (my_str_cmp(func, func_names[i]) == 0)
			return (i);
		i++;
	}
	return (-1);
}

void	use_funcs(int *funcs_idx, int size, t_dlist **lsta, t_dlist **lstb)
{
	int			i;
	static void	(*funcs[11])(t_dlist **lsta, t_dlist **lstb) = {sa, sb, ss,
		pa, pb, ra, rb, rr, rra, rrb, rrr};

	i = 0;
	while (i < size)
	{
		funcs[funcs_idx[i]](lsta, lstb);
		i++;
	}
}

int	*get_func_idx(int *size)
{
	char	*buffer;
	int		i;
	int		idx;
	int		*funcs_idx;
	int		tmp;

	i = 0;
	idx = 0;
	funcs_idx = malloc(10000 * sizeof(int));
	buffer = get_next_line(0);
	while (buffer)
	{
		tmp = get_idx(buffer);
		if (tmp < 0)
			return (free(funcs_idx), free(buffer), NULL);
		funcs_idx[idx++] = tmp;
		free(buffer);
		buffer = get_next_line(0);
	}
	*size = idx;
	return (funcs_idx);
}

void	apply_funcs(t_dlist **lsta, t_dlist **lstb)
{
	int	*funcs_idx;
	int	size;

	size = 0;
	funcs_idx = get_func_idx(&size);
	if (!funcs_idx)
		throw_error(lsta, NULL);
	use_funcs(funcs_idx, size, lsta, lstb);
	free(funcs_idx);
}

int	main(int argc, char *argv[])
{
	t_dlist	*lsta;
	t_dlist	*lstb;
	int		i;

	i = 1;
	lsta = NULL;
	lstb = NULL;
	if (argc < 2)
		return (1);
	while (i < argc)
	{
		parse_string(&lsta, argv[i]);
		i++;
	}
	apply_funcs(&lsta, &lstb);
	if (!ft_is_a_sorted(lsta) && !lstb)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	free_lst(&lsta);
	free_lst(&lstb);
}
