/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:41:22 by fvonsovs          #+#    #+#             */
/*   Updated: 2023/01/31 17:58:56 by fvonsovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.a"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 255
# endif

# ifndef PAD_RIGHT
#  define PAD_RIGHT 1
# endif

# ifndef PAD_ZERO
#  define PAD_ZERO 2
# endif

int	ft_printf(const char *input, ...);

# endif