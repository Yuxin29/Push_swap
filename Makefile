# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yuwu <yuwu@student.hive.fi>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/08 09:58:20 by yuwu              #+#    #+#              #
#    Updated: 2025/05/09 17:11:01 by yuwu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a
HEADERS := ft_printf.h
CFLAGS := -Wall -Wextra -Werror
CC := cc

SRCS := ft_printf.c \
		ft_putchar.c \
		ft_putstr.c	\
		ft_putptr.c \
		ft_putint.c \
		ft_putdec.c \
		ft_putdecu.c \
		ft_puthexlower.c \
		ft_puthexupper.c \

OBJS := $(SRCS:%.c=%.o)

$(NAME): $(OBJS)
		ar -rcs $@ $^

%.o: %.c $(HEADERS)
		$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re			
