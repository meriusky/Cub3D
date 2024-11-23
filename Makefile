# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frankgar <frankgar@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 10:44:59 by frankgar          #+#    #+#              #
#    Updated: 2024/11/23 22:02:12 by frankgar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
FLAGS = -Wall -Werror -Wextra -O3 -g -fsanitize=address 
INCLUDES = -I ./inc/\
           -I ./libft/\
		   -I ./MLX42/include/MLX42/
SRC = main.c 

DIR_SRC = ./src
DIR_OBJ = $(DIR_SRC)/obj
OBJ = $(addprefix $(DIR_OBJ)/, $(SRC:.c=.o))
DEP = $(addprefix $(DIR_OBJ)/, $(SRC:.c=.d))

all: dir $(NAME)

-include $(DEP)

dir:
	cmake ./MLX42 -B ./MLX42/build/ && make -C ./MLX42/build/ -j4 --no-print-directory
	make -C ./libft --no-print-directory
	mkdir -p $(DIR_OBJ)

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c Makefile
	$(CC) -MMD $(FLAGS)  -c $< -o $@ $(INCLUDES)

$(NAME): $(OBJ) ./libft/libft.a ./MLX42/build/libmlx42.a 
	$(CC) $(FLAGS) $(OBJ) -Iinclude -ldl -lglfw -pthread -lm ./libft/libft.a ./MLX42/build/libmlx42.a -o $@ $(INCLUDES)
	echo "$(NAME) Created :D"

clean:
	rm -rf $(DIR_OBJ)
	rm -rf ./MLX42/build
	make clean -C ./libft/ --no-print-directory 
	echo "DEPENDENCIES Erased :D"

fclean: clean
	rm -rf $(NAME)
	make fclean -C ./libft/ --no-print-directory 
	echo "EVERYTHING Erased D:"

re: fclean all

.PHONY: fclean all clean re dir

.SILENT:
