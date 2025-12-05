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
#include "ft_printf/libft/libft.h"
#include "push_swap.h"

int	check_if_num(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (ft_isdigit(str[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	t_list	*lst;
	char	**nums;
	int		idx;

	i = 1;
	lst = NULL;
	if (argc < 2)
		return (ft_printf("please enter at least 2 numbers"), 0);
	while (i < argc)
	{
		idx = 0;
		nums = ft_split(argv[i], ' ');
		if (check_if_num(nums))
			exit(1);
		i++;
	}
	
}
