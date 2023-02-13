/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:41:22 by fvonsovs          #+#    #+#             */
/*   Updated: 2023/02/13 18:21:12 by fvonsovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include "./libft/libft.h"

# ifndef HEX_CHARS
#  define HEX_CHARS "0123456789abcdef"
# endif

# ifndef HEX_CHARS_UPPERCASE
#  define HEX_CHARS_UPPERCASE "0123456789ABCDEF"
# endif

int	ft_printf(const char *input, ...);

int	check_format(va_list *args, char c, int count);

int	putchar_return(va_list *args);

int	print_string(va_list *args);

int	print_hex_pointer(va_list *args);

#endif