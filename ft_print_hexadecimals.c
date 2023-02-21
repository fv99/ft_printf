/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexadecimals.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:22:06 by fvonsovs          #+#    #+#             */
/*   Updated: 2023/02/21 15:22:55 by fvonsovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

// initializes the variatic into a pointer
// to pass to the print_hex_pointer function
int	initialize_pointer(va_list *args)
{
	int		count;
	void	*ptr;

	count = 0;
	ptr = va_arg(*args, void *);
	count = print_hex_pointer(ptr, count);
	return (count);
}

// prints our hex pointer
int	print_hex_pointer(const void *ptr, int count)
{
	uintptr_t	val;
	int			i;
	int			j;
	char		buf[sizeof(uintptr_t) * 2 + 1];

	i = 0;
	val = (uintptr_t)ptr;
	if (val == 0)
		return (write (1, "(nil)", 5));
	count += write(1, "0x", 2);
	while (val != 0)
	{
		buf[i++] = HEX_CHARS[val % 16];
		val /= 16;
	}
	buf[ft_strlen(buf)] = '\0';
	j = i - 1;
	while (j >= 0)
	{
		write(1, &buf[j], 1);
		count++;
		j--;
	}
	return (count);
}

// in C hex values unsigned by default
int	print_hex_lowercase(va_list *args)
{
	unsigned int	n;
	char			buf[9];
	int				i;
	int				digit;
	int				len;

	n = va_arg(*args, unsigned int);
	i = 0;
	if (n == 0)
		buf[i++] = '0';
	while (n > 0)
	{
		digit = n % 16;
		buf[i++] = HEX_CHARS[digit];
		n /= 16;
	}
	len = i;
	while (i > 0)
	{
		i--;
		write(1, &buf[i], 1);
	}
	return (len);
}

int	print_hex_uppercase(va_list *args)
{
	unsigned int	n;
	char			buf[9];
	int				i;
	int				digit;
	int				len;

	n = va_arg(*args, unsigned int);
	i = 0;
	if (n == 0)
		buf[i++] = '0';
	while (n > 0)
	{
		digit = n % 16;
		buf[i++] = HEX_CHARS_UPPERCASE[digit];
		n /= 16;
	}
	len = i;
	while (i > 0)
	{
		i--;
		write(1, &buf[i], 1);
	}
	return (len);
}
