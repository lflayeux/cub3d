CC = cc

INCLUDE = -I./libft -I./minilibx

CFLAGS = -Wall -Werror -Wextra -g3 $(INCLUDE)

NAME = ./cub3d

MLX_FLAGS = -L./minilibx -lmlx -lXext -lX11 -lm

SRC = src/main.c

GREEN = \033[32m
RED = \033[31m
YELLOW = \033[33m
RESET = \033[0m

LIBFT_DIR = ./libft
LIBFT_A = $(LIBFT_DIR)/libft.a
build/%.o: src/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

OBJ = $(SRC:src/%.c=build/%.o)

$(NAME): $(OBJ) $(LIBFT_A)
	@$(CC) $(CFLAGS) -o $@ $^ $(MLX_FLAGS)
	@echo "$(GREEN)Compilation successful ! ✅$(RESET)"

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

all: $(NAME)

clean:
	@rm -rf build/
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory 
	@echo "$(YELLOW)All object files cleaned. 🧹$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory 
	@echo "$(YELLOW)Executable cleaned. 🧹$(RESET)"

re: fclean all

valg: re
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

.PHONY: clean fclean re valg
