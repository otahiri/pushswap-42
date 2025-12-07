/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 10:17:41 by otahiri-          #+#    #+#             */
/*   Updated: 2025/12/05 15:09:58 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf/ft_printf.h"
#include "push_swap.h"

int	check_nums(char *num)
{
	int	i;

	i = 0;
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
	char	**split_nums;
	int		i;

	i = 0;
	split_nums = ft_split(nums, ' ');
	while (split_nums[i])
	{
		ft_printf("%s\n", split_nums[i]);
		if (!check_nums(split_nums[i]))
			exit(0);
		add_back(lsta, new_list(ft_atoi(split_nums[i])));
		i++;
	}
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
	while (lsta)
	{
		ft_printf("%d\n", lsta->node->data);
		lsta = lsta->next;
	}
}
