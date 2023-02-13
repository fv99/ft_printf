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
int	print_hex_pointer(va_list *args)
{
	char		buf[sizeof(uintptr_t) * 2 + 3] = {0};
	uintptr_t	val;
	int			i;
	int 		len;

	i = sizeof(buf) - 2;
	val = (uintptr_t)va_arg(*args, void *);
	buf[0] = '0';
	buf[1] = 'x';
	while (i >= 2)
	{
		buf[i] = HEX_CHARS[val & 0x0f];
		val >>= 4;
		i--;
		if (val == 0)
			break;
	}
	buf[sizeof(buf) - 1] = '\0';
	len = sizeof(buf) - i - 1;
	write(1, buf, len);
	return (len);
}


int	print_string(va_list *args)
{
	char	*str;

	str = va_arg(*args, char *);
	if (!str)
		str = "(null)";
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}	

int	putchar_return(va_list *args)
{
	ft_putchar_fd(va_arg(*args, int), 1);
	return (1);
}	

int	print_integer_base10(va_list *args)
{
	char	*str;
	int		len;

	str = ft_itoa(va_arg(*args, int));
	ft_putstr_fd(str, 1);
	len = ft_strlen(str);
	if (ft_strncmp(str, "-2147483648", 12) != 0)
		free(str);
	return(len);
}

// buffer size of 21 should be ok for 32-bit unsigned int
int	print_unsigned_base10(va_list *args)
{
	unsigned int	n;
	char			buf[21];
	int				i;

	n = va_arg(*args, unsigned int);
	i = 0;
	if (n == 0)
        buf[i++] = '0';
	else
	{
		while (n > 0)
		{
			buf[i++] = n % 10 + '0';
			n /= 10;
		}
	}
	while (i > 0)
	{
		i--;
		write(1, &buf[i], 1);
	}
	return (i);
}

int	check_format(va_list *args, char c, int count)
{
	if (c == 'c')
		count += putchar_return(args);
	if (c == 's')
		count += print_string(args);
	if (c == 'p')
		count += print_hex_pointer(args);
	if (c == 'd' || c == 'i')
		count += print_integer_base10(args);
	if (c == 'u')
		count += print_unsigned_base10(args);
	// if (c == 'x')

	// if (c == 'X')

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
