# Variables
NAME = minirt
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 #-fsanitize=address

SRCS_DIR = ./srcs/


INCS_DIR = ./incs

# path for MLX
MLX_DIR = ./mlx_linux
MLX_FLAGS = -lX11 -lXext -lm
MLX = $(addprefix $(MLX_DIR)/, libmlx.a)

FILES =		$(SRCS_DIR)main.c \
			$(SRCS_DIR)alloc_mem.c \
			$(SRCS_DIR)free_mem.c \
			$(SRCS_DIR)start_draw.c \
			$(SRCS_DIR)key_hooks.c \
			$(SRCS_DIR)exit_prog.c \
			$(SRCS_DIR)init_prog.c \
			$(SRCS_DIR)init_vars.c \
			$(SRCS_DIR)init_scene.c \
			$(SRCS_DIR)vec3_1.c \
			$(SRCS_DIR)vec3_2.c \
			$(SRCS_DIR)viewport.c \
			$(SRCS_DIR)ray.c \
			$(SRCS_DIR)ray_sp_pl.c \
			$(SRCS_DIR)ray_cy_body.c \
			$(SRCS_DIR)ray_cy_circle.c \
			$(SRCS_DIR)light.c \
			$(SRCS_DIR)rgb.c \

OBJ_FILES = $(FILES:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< -I $(INCS_DIR)


all : $(NAME)


$(NAME) : $(MLX) $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@ -I$(INCS_DIR) -L$(MLX_DIR) -lmlx $(MLX_FLAGS)
	@echo "\033[1;35m🦔 miniRT_execute compiled! 🦔\033[0m"

$(MLX):
	chmod 775 mlx_linux/configure
	make -C $(MLX_DIR)
	@echo "\033[1;35m🦔 mlx compiled! 🦔\033[0m"

clean : 
	make clean -C $(MLX_DIR)
	@echo "\033[1;35m🦔 deleted object files for mlx 🦔\033[0m"
	rm -rf $(OBJ_FILES)
	@echo "\033[1;35m🦔 deleted object files for miniRT_execute 🦔\033[0m"

fclean : clean
	rm -rf $(NAME)
	@echo "\033[1;35m🦔 deleted miniRT_execute executable 🦔\033[0m"

re : fclean
	make all

.PHONY : all clean fclean re
