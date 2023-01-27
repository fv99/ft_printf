# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fvonsovs <fvonsovs@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/27 12:36:48 by fvonsovs          #+#    #+#              #
#    Updated: 2023/01/27 12:38:30 by fvonsovs         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror 
NAME		=	libftprintf.a
SRCS		=	ft_printf.c
OBJS		=	${SRCS:.c=.o}
LIBC		=	ar -cvq
RM			=	rm -f


all: $(NAME)

$(NAME): ${OBJS}
	${LIBC} ${NAME} ${OBJS}

clean: 
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY:	all clean fclean re
