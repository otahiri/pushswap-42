/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 09:31:16 by otahiri-          #+#    #+#             */
/*   Updated: 2025/10/23 20:10:33 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	custom_atoi(const char *nptr)
{
	int		sign;
	long	num;

	num = 0;
	sign = 1;
	while (*nptr && (*nptr == ' ' || *nptr == '\n'))
		nptr++;
	if (*nptr && (*nptr == '-' || *nptr == '+'))
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr && (*nptr >= '0' && *nptr <= '9'))
	{
		num *= 10;
		num += *nptr - '0';
		nptr++;
		if (num * sign > INT_MAX || num * sign < INT_MIN)
			throw_error();
	}
	if (*nptr)
		throw_error();
	return (num * sign);
}
