CC = cc

INCLUDE = -I./libft -I./minilibx -I./includes

CFLAGS = -Wall -Werror -Wextra -g3 $(INCLUDE)

NAME = ./cub3d

MLX_FLAGS = -L./minilibx -lmlx -lXext -lX11 -lm

SRC =	src/main.c \
		src/parsing/check_color.c \
		src/parsing/check_texture.c \
		src/parsing/check_file_validity.c \
		src/parsing/check_map.c \
		src/parsing/color_utils_1.c \
		src/parsing/color_utils_2.c \
		src/parsing/check_map_utils.c \
		src/parsing/check_map_algo.c \
		src/parsing/init.c \
		src/parsing/parse_error.c \
		src/parsing/texture_loading.c\
		src/game/init_struct_game.c \
		src/game/render.c \
		src/game/render_utils.c \
		src/game/mini_map.c \
		src/game/mini_map_ray.c \
		src/utils/free.c \
		src/utils/mlx_utils.c \
		src/utils/mlx_key.c \
		src/utils/game_move.c \

# ======================
# ======= COLOR ========
# ======================

GREEN = \033[32m
RED = \033[31m
YELLOW = \033[33m
RESET = \033[0m

# ======================
# ======= LIBFT ========
# ======================

LIBFT_DIR = ./libft
LIBFT_A = $(LIBFT_DIR)/libft.a

# ======================
# ==== COMPILATION =====
# ======================

build/%.o: src/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

OBJ = $(SRC:src/%.c=build/%.o)

$(NAME): $(OBJ) $(LIBFT_A)
	@$(CC) $(CFLAGS) -o $@ $^ $(MLX_FLAGS)
	@echo "$(GREEN)Compilation successful ! ✅$(RESET)"

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

# ======================
# ======= RULES ========
# ======================

all: $(NAME)

clean:
	@rm -rf build/
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory
	@$(MAKE) -C tests clean --no-print-directory
	@echo "$(YELLOW)All object files cleaned. 🧹$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory
	@echo "$(YELLOW)Executable cleaned. 🧹$(RESET)"

re: fclean all

valg: re
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

# ======================
# ======= TESTS ========
# ======================
test: re
	@$(MAKE) -C tests run --no-print-directory

# ======================
# ======= PHONY ========
# ======================

.PHONY: clean fclean re valg test
