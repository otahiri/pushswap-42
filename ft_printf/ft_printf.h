/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:34:37 by otahiri-          #+#    #+#             */
/*   Updated: 2025/11/02 11:58:22 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

int		ft_printf(const char	*str, ...);
int		print_char(va_list *ap);
int		print_uint(va_list *ap);
int		print_int(va_list *ap);
int		print_decimal(va_list *ap);
int		print_pointer(va_list *ap);
int		print_hex(va_list *ap);
int		print_big_hex(va_list *ap);
int		print_str(va_list *ap);
char	*convert_base(unsigned long num, char *base);
char	*ft_uitoa(unsigned int n);

#endif
