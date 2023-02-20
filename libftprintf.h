/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:41:22 by fvonsovs          #+#    #+#             */
/*   Updated: 2023/02/20 17:10:18 by fvonsovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include "./libft/libft.h"

# define HEX_CHARS "0123456789abcdef"
# define HEX_CHARS_UPPERCASE "0123456789ABCDEF"

int	ft_printf(const char *input, ...);

int	check_format(va_list *args, char c, int count);

int	initialize_pointer(va_list *args);

int	print_hex_pointer(const void *ptr, int count);

int	print_hex_lowercase(va_list *args);

int	print_hex_uppercase(va_list *args);

int	print_string(va_list *args);

int	putchar_return(va_list *args);

int	print_integer_base10(va_list *args);

int	print_unsigned_base10(va_list *args);

#endif