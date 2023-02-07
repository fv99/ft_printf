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

static int	print_string(va_list *args)
{
	char	*str;
	int		len;

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

	if (c == 'd' || c == 'i')

	if (c == 'u')

	if (c == 'x')

	if (c == 'X')

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

int main(void)
{
	char *ptr ="Hello world!";
	char *np = 0;
	int i = 5;
	unsigned int bs = sizeof(int)*8;
	int mi;
	char buf[80];

	mi = (1 << (bs-1)) + 1;
	ft_printf("%s\n", ptr);
	ft_printf("ft_printf test\n");
	ft_printf("%s is null pointer\n", np);
	ft_printf("%d = 5\n", i);
	ft_printf("%d = - max int\n", mi);
	ft_printf("char %c = 'a'\n", 'a');
	ft_printf("hex %x = ff\n", 0xff);
	ft_printf("hex %02x = 00\n", 0);
	ft_printf("signed %d = unsigned %u = hex %x\n", -3, -3, -3);
	ft_printf("%d %s(s)%", 0, "message");
	ft_printf("\n");
	ft_printf("%d %s(s) with %%\n", 0, "message");
	ft_printf(buf, "justif: \"%-10s\"\n", "left"); ft_printf("%s", buf);
	ft_printf(buf, "justif: \"%10s\"\n", "right"); ft_printf("%s", buf);
	ft_printf(buf, " 3: %04d zero padded\n", 3); ft_printf("%s", buf);
	ft_printf(buf, " 3: %-4d left justif.\n", 3); ft_printf("%s", buf);
	ft_printf(buf, " 3: %4d right justif.\n", 3); ft_printf("%s", buf);
	ft_printf(buf, "-3: %04d zero padded\n", -3); ft_printf("%s", buf);
	ft_printf(buf, "-3: %-4d left justif.\n", -3); ft_printf("%s", buf);
	ft_printf(buf, "-3: %4d right justif.\n", -3); ft_printf("%s", buf);

	return (0);
}