/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils4_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:00:56 by otahiri-          #+#    #+#             */
/*   Updated: 2025/12/17 17:01:05 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker_bonus.h"

int	check_nums(char *num)
{
	int	i;

	i = 0;
	if (num[i] == '-' || num[i] == '+')
	{
		i++;
		if (!ft_isdigit(num[i]))
			return (0);
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
	split_nums = custom_split(nums, " \n");
	while (split_nums[i])
	{
		if (!check_nums(split_nums[i]))
			throw_error(lsta, split_nums);
		res_num = custom_atoi(split_nums[i]);
		if (res_num > 2147483647)
			throw_error(lsta, split_nums);
		tmp = *lsta;
		while (tmp && tmp->next != *lsta)
		{
			if (tmp->num == res_num)
				throw_error(lsta, split_nums);
			tmp = tmp->next;
		}
		add_back(lsta, new_list(res_num));
		i++;
	}
	free_all(split_nums);
}

int	ft_is_a_sorted(t_dlist *lst)
{
	t_dlist	*head;

	head = lst;
	if (!lst)
		return (0);
	while (1)
	{
		if (lst->rank > lst->next->rank)
			return (0);
		lst = lst->next;
		if (lst == head)
			break ;
	}
	return (1);
}
