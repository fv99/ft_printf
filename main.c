/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:16:24 by fvonsovs          #+#    #+#             */
/*   Updated: 2023/02/13 18:07:42 by fvonsovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "ft_printf.c"
#include "./libft/libft.h"

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
	ft_printf("%d = -2147483647 max int\n", mi);
	ft_printf("char %c = 'a'\n", 'a');
	ft_printf("percent sign: %%\n");
	ft_printf("void pointer hex: %p \n", &i);
	ft_printf("unsigned 4294966876 = %u \n", -420);
	ft_printf("lowercase hex %x = ff\n", 0xff);
	ft_printf("uppercase hex %X = DEADBEEF\n", 3735928559);
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

/*
 * This should display :
 *
 * Hello world!
 * ft_printf test
 * (null) is null pointer
 * 5 = 5
 * -2147483647 = -2147483647 max int
 * char a = 'a'
 * hex ff = ff
 * hex 00 = 00
 * signed -3 = unsigned 4294967293 = hex fffffffd
 * 0 message(s)
 * 0 message(s) with %
 * justif: "left      "
 * justif: "     right"
 *  3: 0003 zero padded
 *  3: 3    left justif.
 *  3:    3 right justif.
 * -3: -003 zero padded
 * -3: -3   left justif.
 * -3:   -3 right justif.
 */