# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nettalha <nettalha@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/28 18:07:34 by nettalha          #+#    #+#              #
#    Updated: 2022/10/28 18:07:37 by nettalha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRCS	=ft_printf.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_putnbr.c \
			ft_strlen.c \
			ft_put_pointer.c \
			ft_putnbr_base.c \
			ft_put_unsigned.c \

OBJS	= $(SRCS:c=o)

FLAGS	= -Wall -Wextra -Werror

CC		= gcc

RM		= rm -f


%.o:%.c
			$(CC) $(FLAGS) -c $^ -o $@

$(NAME) :	$(OBJS)
			ar -rcs $(NAME) $^

all		:	$(NAME)

clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY	:   all clean fclean re
