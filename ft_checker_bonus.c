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
#include <stdlib.h>

void	excute_func(char *func_name, t_dlist **lsta, t_dlist **lstb)
{
	const char	*funcs_names[10] = {"ra", "rb", "rra", "rrb", "sa", "sb", "pa",
		"pb", "rr", "rrr"};

	if (func_name == funcs_names[0])
		ra(lsta);
	else if (func_name == funcs_names[1])
		rb(lsta);
	else if (func_name == funcs_names[2])
		rra(lsta);
	else if (func_name == funcs_names[3])
		rrb(lsta);
	else if (func_name == funcs_names[4])
		sa(lsta);
	else if (func_name == funcs_names[5])
		sb(lsta);
	else if (func_name == funcs_names[6])
		pa(lsta, lstb);
	else if (func_name == funcs_names[7])
		pb(lsta, lstb);
	else if (func_name == funcs_names[8])
		rr(lsta, lstb);
	else if (func_name == funcs_names[9])
		rrr(lsta, lstb);
}

void	apply_funcs(t_dlist **lsta, t_dlist **lstb)
{
	char	*lines;
	char	**sep_args;

	lines = get_next_line(0);
	sep_args = custom_split(lines, "\n");
	while (lines)
	{
		ft_printf("%s\n", sep_args[0]);
		if (*(sep_args + 1) != NULL)
		{
			free(lines);
			throw_error(lsta, sep_args);
		}
		excute_func(sep_args[0], lsta, lstb);
		free(lines);
		free_all(sep_args);
		lines = get_next_line(0);
		ft_printf("%s\n", lines);
		sep_args = custom_split(lines, "\n");
	}
}

int	main(int argc, char *argv[])
{
	t_dlist	*lsta;
	t_dlist	*lstb;
	t_dlist *head;
	int		i;

	i = 1;
	lsta = NULL;
	lstb = NULL;
	while (i < argc)
	{
		parse_string(&lsta, argv[i]);
		i++;
	}
	apply_funcs(&lsta, &lstb);
	head = lsta;
	while (1)
	{
		ft_printf("%d ", lsta->num);
		lsta = lsta->next;
		if (lsta == head)
			break ;
	}
}


