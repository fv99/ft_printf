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

#include "libftft_printf.h"



int	print(char **out, int *varg)
{
	register int	len;
	register int	pad;
	register int	i;
	register char	*format;
	char			scr[2];

	i = 0;
	len = 0;
	pad = 0;
	format = (char *)(*varg++);



}


int	ft_printf(const char *input, ...)
{




}

int main(void)
{
	char *ptr ="Hello world!";
	char *np = 0;
	it i = 5;
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
	ft_printf(uf, "justif: \"%10s\"\n", "right"); ft_printf("%s", buf);
	ft_printf(buf, " 3: %04d zero padded\n", 3); ft_printf("%s", buf);
	ft_printf(buf, " 3: %-4d left justif.\n", 3); ft_printf("%s", buf);
	ft_printf(buf, " 3: %4d right justif.\n", 3); ft_printf("%s", buf);
	ft_printf(buf, "-3: %04d zero padded\n", -3); ft_printf("%s", buf);
	ft_printf(buf, "-3: %-4d left justif.\n", -3); ft_printf("%s", buf);
	ft_printf(buf, "-3: %4d right justif.\n", -3); ft_printf("%s, buf);

	eurn 0;
}