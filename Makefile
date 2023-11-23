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
			$(SRCS_DIR)vec3.c \
			$(SRCS_DIR)viewport.c \
			$(SRCS_DIR)ray.c \
			$(SRCS_DIR)light.c \
			$(SRCS_DIR)rgb.c \

OBJ_FILES = $(FILES:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< -I $(INCS_DIR)


all : $(NAME) print_success


$(NAME) : $(MLX) $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@ -I$(INCS_DIR) -L$(MLX_DIR) -lmlx $(MLX_FLAGS)


$(MLX):
	make -C $(MLX_DIR)


print_success:
	@echo "\n"
	@echo "\033[1;35m ~~ Build completed successfully!\033[0m"


print_cleaned:
	@echo "\n"
	@echo "\033[1;35m ~~ Clean operation completed!\033[0m"


clean : 
	rm -rf $(OBJ_FILES)
	make clean -C $(MLX_DIR)


fclean : clean
	rm -rf $(NAME)
	@make print_cleaned


re : fclean
	make all


.PHONY : all clean fclean re