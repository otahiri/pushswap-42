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
#include "ft_printf/ft_printf.h"

void	excute_func(char *func_name, t_dlist **lsta, t_dlist **lstb)
{
	const char	*funcs_names[10] = {"ra", "rb", "rra", "rrb", "sa", "sb", "pa",
		"pb", "rr", "rrr"};

	if (!ft_strncmp(func_name, funcs_names[0], 2) && dlst_size(*lsta))
		ra(lsta);
	else if (!ft_strncmp(func_name, funcs_names[1], 2))
		rb(lsta);
	else if (!ft_strncmp(func_name, funcs_names[2], 3))
		rra(lsta);
	else if (!ft_strncmp(func_name, funcs_names[3], 3))
		rrb(lsta);
	else if (!ft_strncmp(func_name, funcs_names[4], 2))
		sa(lsta);
	else if (!ft_strncmp(func_name, funcs_names[5], 2))
		sb(lsta);
	else if (!ft_strncmp(func_name, funcs_names[6], 2))
		pa(lsta, lstb);
	else if (!ft_strncmp(func_name, funcs_names[7], 2))
		pb(lsta, lstb);
	else if (!ft_strncmp(func_name, funcs_names[8], 2))
		rr(lsta, lstb);
	else if (!ft_strncmp(func_name, funcs_names[9], 3))
		rrr(lsta, lstb);
	else
	{
		free_lst(lstb);
		throw_error(lsta, NULL);
	}
}

void	apply_funcs(t_dlist **lsta, t_dlist **lstb)
{
	char	*lines;
	char	*func_name;

	lines = get_next_line(0);
	while (lines)
	{
		func_name = ft_strtrim(lines, "\n");
		excute_func(func_name, lsta, lstb);
		free(lines);
		free(func_name);
		lines = get_next_line(0);
	}
}

int	main(int argc, char *argv[])
{
	t_dlist	*lsta;
	t_dlist	*lstb;
	t_dlist	*head;
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
		lsta = lsta->next;
		if (lsta == head)
			break ;
	}
	if (!ft_is_a_sorted(lsta))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
