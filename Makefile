# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yuwu <yuwu@student.hive.fi>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/03 16:36:29 by yuwu              #+#    #+#              #
#    Updated: 2025/06/15 18:44:12 by yuwu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap
HEADERS := include/push_swap.h
CFLAGS := -Wall -Wextra -Werror -Iinclude
CC := cc

SRCS := $(wildcard src/*.c)

OBJS := $(SRCS:%.c=%.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re			
