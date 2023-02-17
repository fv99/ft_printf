/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexadecimals.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:22:06 by fvonsovs          #+#    #+#             */
/*   Updated: 2023/02/17 15:35:28 by fvonsovs         ###   ########.fr       */
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
	char		buf[sizeof(uintptr_t) * 2 + 3];
	uintptr_t	val;
	int			i;
	int			len;

	ft_memset(buf, 0, sizeof(buf));
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
			break ;
	}
	buf[sizeof(buf) - 1] = '\0';
	len = sizeof(buf) - i - 1;
	write(1, buf, len);
	return (len);
}

// in C hex values unsigned by default
int	print_hex_lowercase(va_list *args)
{
	unsigned int	n;
	char			buf[9];
	int				i;
	int				digit;

	n = va_arg(*args, unsigned int);
	i = 0;
	if (n == 0)
		buf[i++] = '0';
	else
	{
		while (n > 0)
		{
			digit = n % 16;
			buf[i++] = HEX_CHARS[digit];
			n /= 16;
		}
	}
	while (i > 0)
	{
		i--;
		write(1, &buf[i], 1);
	}
	return (i);
}

int	print_hex_uppercase(va_list *args)
{
	unsigned int	n;
	char			buf[9];
	int				i;
	int				digit;

	n = va_arg(*args, unsigned int);
	i = 0;
	if (n == 0)
		buf[i++] = '0';
	else
	{
		while (n > 0)
		{
			digit = n % 16;
			buf[i++] = HEX_CHARS_UPPERCASE[digit];
			n /= 16;
		}
	}
	while (i > 0)
	{
		i--;
		write(1, &buf[i], 1);
	}
	return (i);
}
