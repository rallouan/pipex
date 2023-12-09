# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rallouan <rallouan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/26 16:05:06 by rallouan          #+#    #+#              #
#    Updated: 2023/10/28 20:28:33 by rallouan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS =	pipex.c \
		parsing.c \
		utils.c \
		children.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@cd lib && make --silent
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) ./lib/lib.a

clean:
	@cd lib && make fclean
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
