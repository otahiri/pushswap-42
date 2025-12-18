/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_atoi_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 09:31:16 by otahiri-          #+#    #+#             */
/*   Updated: 2025/12/18 09:32:01 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

long	custom_atoi(const char *nptr)
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
		if (num * sign > 2147483647 || num * sign < -2147483648)
			return (2147483648);
	}
	if (*nptr)
		return (2147483648);
	return (num * sign);
}
