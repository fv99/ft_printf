/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:42:46 by fvonsovs          #+#    #+#             */
/*   Updated: 2023/02/20 16:52:07 by fvonsovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	check_format(va_list *args, char c, int count)
{
	if (c == 'c')
		count += putchar_return(args);
	if (c == 's')
		count += print_string(args);
	if (c == 'p')
		count += initialize_pointer(args);
	if (c == 'd' || c == 'i')
		count += print_integer_base10(args);
	if (c == 'u')
		count += print_unsigned_base10(args);
	if (c == 'x')
		count += print_hex_lowercase(args);
	if (c == 'X')
		count += print_hex_uppercase(args);
	if (c == '%')
		count += write(1, "%", 1);
	return (count);
}

// The va_list data type is a type definition 
// for a type that holds a list of arguments. 
// va_start is a macro that initializes a 
// va_list type with the first unnamed argument. 
// va_arg is a macro that returns the next argument
// in the va_list and updates the pointer to the next argument. 
// va_end is a macro that should be called after 
// all the arguments have been processed 
// to perform any necessary cleanup.
int	ft_printf(const char *input, ...)
{
	int		count;
	int		i;
	va_list	args;
	char	*ptr;

	i = 0;
	count = 0;
	ptr = (char *)input;
	va_start(args, input);
	while (ptr[i] != '\0')
	{
		if (ptr[i] == '%')
		{
			count = check_format(&args, ptr[i + 1], count);
			i += 2;
		}
		else
		{
			ft_putchar_fd(ptr[i], 1);
			i++;
			count++;
		}
	}
	va_end(args);
	return (count);
}
