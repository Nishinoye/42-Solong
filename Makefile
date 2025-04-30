# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tedcarpi <tedcarpi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/30 02:28:16 by tedcarpi          #+#    #+#              #
#    Updated: 2025/04/30 10:03:32 by tedcarpi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
MLX_FLAGS = -Lminilibx-linux -lmlx_Linux -lXext -lX11 -lm

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes

SRC = main.c \
      ft_map.c \
      ft_map2.c \
      ft_move.c \
      ft_img.c \
      get_next_line.c \
      get_next_line_utils.c

OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C minilibx-linux
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -Iminilibx-linux -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@make -C minilibx-linux clean

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re