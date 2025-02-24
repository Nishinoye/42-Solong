# 🏗️ Variables
CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(MLX_DIR)
MLX_DIR = minilibx-linux
MLX_FLAGS = -I $(MLX_DIR) -L $(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd
NAME = so_long
SRC_DIR = src
OBJ_DIR = obj
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# 🎯 Règle principale : Compilation du programme
all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) -o $(NAME)
	@echo "✅ Compilation terminée !"

# 🛠️ Compilation des fichiers .c en .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "🔨 Compilation de $<"

# 📂 Création du dossier obj
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# 🧹 Nettoyage des fichiers objets et de l'exécutable
clean:
	@rm -rf $(OBJ_DIR)
	@echo "🧼 Suppression des fichiers objets."

fclean: clean
	@rm -f $(NAME)
	@echo "🗑️ Suppression de l'exécutable."

# 🔄 Recompiler proprement
re: fclean all

# 🛑 Ne pas traiter ces règles comme des fichiers
.PHONY: all clean fclean re
