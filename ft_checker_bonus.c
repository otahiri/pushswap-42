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

int	get_func_idx(int total)
{
	static int	hash_index[11] = {29537, 29538, 29281, 29282, 28769,
		28770, 29555, 29298, 7500402, 7500385, 7500386};
	int			i;

	i = 0;
	while (i < 11)
	{
		if (total == hash_index[i])
			return (i);
		i++;
	}
	return (-1);
}

int	total_of_three(char *lines)
{
	int	total;

	total = lines[0];
	total = total << 8;
	total |= lines[1];
	total = total << 8;
	total |= lines[2];
	return (total);
}

int	total_of_two(char *lines)
{
	int	total;

	total = lines[0];
	total = total << 8;
	total |= lines[1];
	return (total);
}

void	free_lsts_lines(t_dlist **lsta, t_dlist **lstb, char **lines)
{
	free_all(lines);
	free_lst(lstb);
	throw_error(lsta, NULL);
}

void	use_funcs(int *func_hash, int size, t_dlist **lsta, t_dlist **lstb)
{
	static void	(*func[11])(t_dlist **a, t_dlist **b) = {sa, sb, ra, rb, pa,
		pb, ss, rr, rrr, rra, rrb};
	int			i;

	i = 0;
	while (i < size)
	{
		func[func_hash[i]](lsta, lstb);
		i++;
	}
}

void	apply_funcs(t_dlist **lsta, t_dlist **lstb)
{
	char	*lines;
	char	**sep_lines;
	int		probable_idx;
	int		i;
	int		*func_hash;
	int		idx;

	idx = 0;
	i = 0;
	probable_idx = -1;
	func_hash = malloc(10000 * sizeof(int));
	lines = ft_calloc(40000, sizeof(char));
	read(0, lines, 40000);
	sep_lines = custom_split(lines, "\n");
	free(lines);
	while (sep_lines[i])
	{
		if (sep_lines[i][2] != '\0')
			probable_idx = total_of_three(sep_lines[i]);
		else if (sep_lines[i][2] == '\0')
			probable_idx = total_of_two(sep_lines[i]);
		probable_idx = get_func_idx(probable_idx);
		if (probable_idx < 0)
			free_lsts_lines(lsta, lstb, sep_lines);
		else
			func_hash[idx++] = probable_idx;
		i++;
	}
	use_funcs(func_hash, idx, lsta, lstb);
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
	t_dlist *head = lsta;
	while (lsta->next != head)
	{
		ft_printf("%d\n", lsta->num);
		lsta = lsta->next;
	}
	if (!ft_is_a_sorted(lsta))
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
}
