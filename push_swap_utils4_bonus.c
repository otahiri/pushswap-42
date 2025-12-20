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

int	check_nums(char *n)
{
	int	i;

	i = 0;
	if (n[i] == '-' || n[i] == '+')
		i++;
	if (!ft_isdigit(n[i]))
		return (0);
	while (n[i])
	{
		if (!ft_isdigit(n[i]))
			return (0);
		i++;
	}
	return (1);
}

void	check_dups(t_dlist **lsta)
{
	t_dlist	*a;
	t_dlist	*b;
	t_dlist	*head;

	if (!lsta || !*lsta || (*lsta)->next == *lsta)
		return ;
	a = *lsta;
	head = *lsta;
	while (a->next != head)
	{
		b = a->next;
		while (b != head)
		{
			if (a->num == b->num)
				throw_error(lsta, NULL);
			b = b->next;
		}
		a = a->next;
	}
}

void	parse_string(t_dlist **lsta, char *nums)
{
	char		**split_nums;
	int			i;
	long long	res_num;

	i = 0;
	split_nums = custom_split(nums, " ");
	if (!split_nums[i])
		throw_error(lsta, split_nums);
	while (split_nums[i])
	{
		if (!check_nums(split_nums[i]))
			throw_error(lsta, split_nums);
		res_num = custom_atoi(split_nums[i]);
		if (res_num > 2147483647)
			throw_error(lsta, split_nums);
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
	while (lst->next != head)
	{
		if (lst->rank > lst->next->rank)
			return (0);
		lst = lst->next;
	}
	return (1);
}
