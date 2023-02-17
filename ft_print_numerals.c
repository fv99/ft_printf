/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numerals.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:18:27 by fvonsovs          #+#    #+#             */
/*   Updated: 2023/02/17 15:35:28 by fvonsovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_integer_base10(va_list *args)
{
	char	*str;
	int		len;

	str = ft_itoa(va_arg(*args, int));
	ft_putstr_fd(str, 1);
	len = ft_strlen(str);
	if (ft_strncmp(str, "-2147483648", 12) != 0)
		free(str);
	return (len);
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
