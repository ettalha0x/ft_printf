# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nettalha <nettalha@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/28 18:07:34 by nettalha          #+#    #+#              #
#    Updated: 2022/11/27 03:36:44 by nettalha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRCS	=ft_printf.c \
			formats.c\
			check_minus.c\
			check_zero.c\
			check_point.c\
			check_sharp.c\
			check_space.c\
			check_pluse.c\
			ft_putchar.c \
			ft_putstr.c \
			ft_putnbr.c \
			ft_put_pointer.c \
			ft_putnbr_hexa.c \
			ft_put_unsigned.c \
			ft_strlen.c\
			ft_intlen.c\

OBJS	= $(SRCS:c=o)

FLAGS	= -Wall -Wextra -Werror

CC		= gcc

RM		= rm -f


%.o:%.c
			$(CC) $(FLAGS) -c $^ -o $@

$(NAME) :	$(OBJS)
			ar -rcs $(NAME) $^

all		:	$(NAME)
bonus	:	$(NAME)

clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

run: clean
	gcc -Wall -Wextra -Werror main.c libftprintf.a && ./a.out

.PHONY	:   all clean fclean re
