# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fvonsovs <fvonsovs@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/27 12:36:48 by fvonsovs          #+#    #+#              #
#    Updated: 2023/02/17 15:35:57 by fvonsovs         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
NAME		=	libftprintf.a
SRCS		=	ft_printf.c ft_print_chars.c ft_print_hexadecimals.c ft_print_numerals.c
INCS		=	libftprintf.h
OBJS		=	${SRCS:.c=.o}
LIBC		=	ar -cvq
RM			=	rm -f
LIBFT		=	./libft/libft.a

.c.o:
	gcc ${CFLAGS} -c $< -o ${<:.c=.o} -I.

all: $(NAME)

$(NAME): ${OBJS}
	make -C ./libft
	cp ./libft/libft.a ${NAME}
	${LIBC} ${NAME} ${OBJS}

clean: 
	${MAKE} clean -C ./libft
	${RM} ${OBJS}

fclean: clean
	${MAKE} fclean -C ./libft
	${RM} ${NAME}

re: fclean all

.PHONY:	all clean fclean re
