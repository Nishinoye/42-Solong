# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tedcarpi <tedcarpi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/10 12:00:00 by YourLogin         #+#    #+#              #
#    Updated: 2025/02/25 20:53:13 by tedcarpi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nom de l'exécutable
NAME		= so_long

# Compilateur et options
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g

# Répertoires
SRC_DIR		= src
OBJ_DIR		= obj
INC_DIR		= includes
MLX_DIR		= minilibx-linux
LIBFT_DIR	= libft

# Bibliothèques
MLX_LIB		= $(MLX_DIR)/libmlx_Linux.a
MLX_FLAGS	= -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm
LIBFT_LIB	= $(LIBFT_DIR)/libft.a
LIBFT_FLAGS	= -L$(LIBFT_DIR) -lft

# Fichiers sources et objets
SRC_FILES	= main.c ft_map.c get_next_line.c get_next_line_utils.c
SRC			= $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ			= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Règle par défaut
all: $(NAME)

# Règle pour compiler minilibx
$(MLX_LIB):
	@echo "Compiling minilibx..."
	@make -C $(MLX_DIR)

# Règle pour compiler libft
$(LIBFT_LIB):
	@echo "Compiling libft..."
	@make -C $(LIBFT_DIR)

# Règle de compilation
$(NAME): $(OBJ) $(MLX_LIB) $(LIBFT_LIB)
	@echo "Compiling $(NAME)..."
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) $(LIBFT_FLAGS) -o $(NAME)

# Règle pour compiler les fichiers objets
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -I$(MLX_DIR) -I$(LIBFT_DIR) -c $< -o $@

# Règle pour nettoyer les fichiers objets
clean:
	@echo "Cleaning object files..."
	rm -rf $(OBJ_DIR)

# Règle pour nettoyer les fichiers objets et l'exécutable
fclean: clean
	@echo "Cleaning executable..."
	rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

# Règle pour tout recompiler
re: fclean all

# Règle pour éviter les conflits avec des fichiers du même nom
.PHONY: all clean fclean re