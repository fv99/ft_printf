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

#include "ft_printf.h"

static int	prints(int *varg, char *format, int width, int pad)
{
	int	printed;
	int	padchar;

	printed = 0;
	padchar = ' ';

	if (width > 0)
	{
		


	}

}

static int	printi()
{


}

static int	ft_print(int *varg, char *format, int printed, int width, int pad)
{
	char *s;

	if (*format == 's')
	{
		s = *((char **)varg++);
		

	}



}

static int	ft_format(int *varg, char *format, int printed)
{
	int		width;
	int		pad;

	while (*format != 0)
	{
		++format;
		width = pad = 0;
		if (*format == '-')
		{
			++format;
			pad = PAD_RIGHT;
		}
		while (*format == '0')
		{
			++format;
			pad |= PAD_ZERO;
		}
		while (*format >= '0' && *format <= '9')
		{
			++format;
			width *= 10;
			width += *format - '0';
		}
		ft_print(*varg, *format, printed, width, pad);


	}
}



int	ft_printf(const char *input, ...)
{
	int		*varg;
	char	*format;
	int		printed;

	varg = (int *)(&input);
	format = (char *)(*varg++);
	printed = 0;
	while (*format != 0)
	{
		format++;
		if (*format == '%')
			ft_format(*varg++, *format, printed);
		else
			ft_putchar_fd(*format, 1);
		printed++;
	}
	return (printed);
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