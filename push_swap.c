/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 10:17:41 by otahiri-          #+#    #+#             */
/*   Updated: 2025/12/09 11:04:21 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	check_nums(char *num)
{
	int	i;

	i = 0;
	if (num[i] == '-' || num[i] == '+')
	{
		i++;
		if (!ft_isdigit(num[i]))
			throw_error();
	}
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

void	parse_string(t_dlist **lsta, char *nums)
{
	char		**split_nums;
	int			i;
	t_dlist		*tmp;
	long long	res_num;

	i = 0;
	split_nums = ft_split(nums, ' ');
	while (split_nums[i])
	{
		if (!check_nums(split_nums[i]))
			throw_error();
		res_num = custom_atoi(split_nums[i]);
		tmp = *lsta;
		while (tmp)
		{
			if (tmp->node->data == res_num)
				throw_error();
			tmp = tmp->next;
		}
		add_back(lsta, new_list(res_num));
		i++;
	}
}

void	sort_stack(t_dlist **lsta, t_dlist **lstb)
{
	int	*sorted_list;
	int	size;
	t_dlist	

	size = dlst_size(*lsta);
	sorted_list = ft_calloc(size, sizeof(int));
	copy_dlst(*lsta, sorted_list);
	sort_arr(sorted_list, size);
	set_ranks(lsta, sorted_list);
	while ()
	calculate_cost(lsta, lstb);
}

int	main(int argc, char *argv[])
{
	t_dlist	*lsta;
	t_dlist	*lstb;
	int		i;

	lsta = NULL;
	lstb = NULL;
	i = 0;
	i++;
	while (i < argc)
		parse_string(&lsta, argv[i++]);
	sort_stack(&lsta, &lstb);
	while (lsta)
	{
		ft_printf("num is %d rank is %d cost a are %d and %d cost b  are %d and %d\n", lsta->node->data, lsta->node->rank, lsta->node->cost_a_ra, lsta->node->cost_a_rra, lsta->node->cost_b_rb, lsta->node->cost_b_rrb);
		lsta = lsta->next;
	}
}
