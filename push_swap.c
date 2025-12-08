/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 10:17:41 by otahiri-          #+#    #+#             */
/*   Updated: 2025/12/07 13:38:04 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include "ft_printf/libft/libft.h"

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

void	parse_string(t_dlist **lsta, t_dlist **lstb, char *nums)
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

	sorted_list = ft_calloc(dlst_size(*lsta), sizeof(int));
	copy_dlst(*lsta, &sorted_list);
	sort_arr(&sorted_list);
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
		parse_string(&lsta, &lstb, argv[i++]);
	sort_stack(&lsta, lstb);
	while (lsta)
	{
		ft_printf("%d\n", lsta->node->data);
		lsta = lsta->next;
	}
}
