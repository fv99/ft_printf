/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:42:46 by fvonsovs          #+#    #+#             */
/*   Updated: 2023/01/31 16:40:47 by fvonsovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

// The val & 0x0f operation retrieves
// the rightmost 4 bits of the binary
// number val, and indexes the HEX_CHARS
// string with this 4-bit value to get the
// corresponding hexadecimal character. 
// The val >>= 4 operation shifts the
// binary number val 4 bits to the right, 
// effectively dividing the binary number by 16. 
static int	print_hex_pointer(va_list args)
{
	char		buf[sizeof(uintptr_t) * 2 + 2];
	void		*ptr;
	uintptr_t	val;
	int			i;

	i = sizeof(buf) - 1;
	ptr = va_arg(args, void *);
	val = (uintptr_t)ptr;
	buf[0] = '0';
	buf[1] = 'x';
	while (i >= 2)
	{
		buf[i] = HEX_CHARS[val & 0x0f];
		val >>= 4;
		i--;
	}
	write(1, buf, sizeof(buf));
	return (sizeof(buf));
}


static int	print_string(va_list *args)
{
	char	*str;

	str = va_arg(*args, char *);
	if (!str)
		str = "(null)";
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}	

static int	putchar_return(va_list *args)
{
	ft_putchar_fd(va_arg(*args, int), 1);
	return (1);
}	

static int	check_format(va_list *args, char c, int count)
{
	if (c == 'c')
		count += putchar_return(args);
	if (c == 's')
		count += print_string(args);
	if (c == 'p')
		count += print_hex_pointer(va_arg(*args, va_list));
	// if (c == 'd' || c == 'i')

	// if (c == 'u')

	// if (c == 'x')

	// if (c == 'X')

	if (c == '%')
		count += putchar_return(args);
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
			count += check_format(&args, ptr[i + 1], count);
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
