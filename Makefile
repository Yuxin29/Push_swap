# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yuwu <yuwu@student.hive.fi>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/03 16:36:29 by yuwu              #+#    #+#              #
#    Updated: 2025/06/03 16:37:39 by yuwu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap.a
HEADERS := push_swap.h
CFLAGS := -Wall -Wextra -Werror
CC := cc

SRCS := firststep_dealinput.c \
	ft_operations.c \
	push_swap_by_size.c \
	sort_big.c \
	finalstep_main.c \

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
