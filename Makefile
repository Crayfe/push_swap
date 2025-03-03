
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3

LIBFT_DIR = libft
SRC_DIR = src
OBJ_DIR = obj
BONUS_SRC_DIR = src_bonus
BONUS_OBJ_DIR = obj_bonus

# Archivos fuente y objetos
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

BONUS_SRCS = $(wildcard $(BONUS_SRC_DIR)/*.c)
BONUS_OBJS = $(patsubst $(BONUS_SRC_DIR)/%.c,$(BONUS_OBJ_DIR)/%.o,$(BONUS_SRCS))

# Nombre del ejecutable
NAME = push_swap
BONUS_NAME = checker

# Regla por defecto (compilar el ejecutable)
all: $(NAME)

# Regla para crear el ejecutable
$(NAME): $(OBJS) $(LIBFT_DIR)/libft.a
	$(CC) $(CFLAGS) -o $@ $^ -L $(LIBFT_DIR) -lft

# Regla para compilar los archivos objeto
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(LIBFT_DIR) -c $< -o $@

# Crear el directorio de objetos si no existe
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Regla para compilar la librería libft.a
$(LIBFT_DIR)/libft.a:
	@echo "Compilando libft..."
	$(MAKE) -C $(LIBFT_DIR)

# Limpiar los archivos generados
clean:
	rm -rf $(OBJ_DIR) $(BONUS_OBJ_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

# Nueva regla para compilar el bonus (checker)
bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS) $(LIBFT_DIR)/libft.a
	$(CC) $(CFLAGS) -o $@ $^ -L $(LIBFT_DIR) -lft

$(BONUS_OBJ_DIR)/%.o: $(BONUS_SRC_DIR)/%.c | $(BONUS_OBJ_DIR)
	$(CC) $(CFLAGS) -I $(LIBFT_DIR) -c $< -o $@

$(BONUS_OBJ_DIR):
	mkdir -p $(BONUS_OBJ_DIR)

.PHONY: all clean fclean re bonus