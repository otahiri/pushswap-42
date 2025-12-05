/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_stack_funcs1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:14:26 by otahiri-          #+#    #+#             */
/*   Updated: 2025/12/05 15:09:52 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf/libft/libft.h"
#include "push_swap.h"

t_array *init_arr(int cap)
{
	t_array	*arr;

	arr = (t_array *)malloc(sizeof(t_array));
	arr->cap = cap;
	arr->buffer = ft_calloc(arr->cap, sizeof(int));
	arr->size = 0;
	return (arr);
}

t_array *expand_arr(t_array *arr)
{
	t_array *res;
	res = init_arr(arr->cap * 10);
	ft_memcpy(res->buffer, arr->buffer, arr->cap);
	free(arr->buffer);
	free(arr);
	return (res);
}
