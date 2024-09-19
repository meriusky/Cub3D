# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mehernan <mehernan@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/19 14:41:41 by mehernan          #+#    #+#              #
#    Updated: 2024/09/19 16:04:31 by mehernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = parsing_cub3D

CC = gcc

SRCS = main.c get_next_line.c get_next_line_utils.c

OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)

BUFFER_SIZE = 0
CFLAGS = -Werror -Wextra -Wall -MMD -D BUFFER_SIZE=$(BUFFER_SIZE) 

LIBFT_PATH = libft/libft.a

all: 
	@$(MAKE) $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@echo "Parsing compiled!"
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(LIBFT):
	@make -C libft

clean:
	rm -f $(OBJS)
	rm -f $(DEPS)

fclean: clean
	$(MAKE) -C libft fclean
	rm -rf $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
