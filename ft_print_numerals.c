/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numerals.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:18:27 by fvonsovs          #+#    #+#             */
/*   Updated: 2023/02/20 17:31:53 by fvonsovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_integer_base10(va_list *args)
{
	char	*str;
	int		len;
	int		n;

	n = va_arg(*args, int);
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", 1);
		return (11);
	}
	str = ft_itoa(n);
	ft_putstr_fd(str, 1);
	len = ft_strlen(str);
	free(str);
	return (len);
}

// buffer size of 21 should be ok for 32-bit unsigned int
int	print_unsigned_base10(va_list *args)
{
	unsigned int	n;
	char			buf[21];
	int				i;
	int				len;

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
	len = i;
	while (i > 0)
	{
		i--;
		write(1, &buf[i], 1);
	}
	return (len);
}
