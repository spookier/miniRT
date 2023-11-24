# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/23 16:05:09 by yhwang            #+#    #+#              #
#    Updated: 2023/11/24 12:57:26 by yhwang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RESET		:= $(shell tput -Txterm sgr0)
YELLOW		:= $(shell tput -Txterm setaf 3)

NAME = miniRT
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -f

LIBFT_DIR = ./parse/libft
LIBFT_NAME = libft.a
LIBFT = $(addprefix $(LIBFT_DIR)/, $(LIBFT_NAME))

MLX_DIR = ./execute/mlx_linux
MLX_FLAGS = -lX11 -lXext -lm
MLX = $(addprefix $(MLX_DIR)/, libmlx.a)

PARSE_DIR = ./parse/srcs/
# EXECUTE_DIR = ./execute/srcs/

PARSE_INCS_DIR = ./parse/incs/
# EXECUTE_INCS_DIR = ./execute/incs/

FILES = ./main \
			$(PARSE_DIR)parse_main \
			$(PARSE_DIR)init \
			$(PARSE_DIR)parse_map \
			$(PARSE_DIR)parse_check_id \
			$(PARSE_DIR)parse_ambient \
			$(PARSE_DIR)parse_camera \
			$(PARSE_DIR)parse_light \
			$(PARSE_DIR)parse_sphere \
			$(PARSE_DIR)parse_plane \
			$(PARSE_DIR)parse_cylinder \
			$(PARSE_DIR)print_scene \
			$(PARSE_DIR)utils_lib \
			$(PARSE_DIR)utils_range \
			$(PARSE_DIR)utils
# $(EXECUTE_DIR)main.c \
# $(EXECUTE_DIR)alloc_mem.c \
# $(EXECUTE_DIR)free_mem.c \
# $(EXECUTE_DIR)start_draw.c \
# $(EXECUTE_DIR)key_hooks.c \
# $(EXECUTE_DIR)exit_prog.c \
# $(EXECUTE_DIR)init_prog.c \
# $(EXECUTE_DIR)init_vars.c \
# $(EXECUTE_DIR)vec3.c \
# $(EXECUTE_DIR)viewport.c \
# $(EXECUTE_DIR)ray.c \
# $(EXECUTE_DIR)light.c \
# $(EXECUTE_DIR)rgb.c \

SRCS = $(addsuffix .c, $(FILES))
OBJS = $(addsuffix .o, $(FILES))

# %.o: %.c $(PARSE_INCS_DIR) $(EXECUTE_INCS_DIR)
# 	$(CC) $(CFLAGS) -c $< -o $@ -lm -I$(PARSE_INCS_DIR) -I$(EXECUTE_INCS_DIR)
%.o: %.c $(PARSE_INCS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -lm -I$(PARSE_INCS_DIR)

all: $(LIBFT_NAME) $(NAME)

$(LIBFT_NAME):
	@make -C $(LIBFT_DIR)
	@echo "$(YELLOW)🐥 libft compiled! 🐥$(RESET)"

# $(NAME): $(MLX) $(OBJS) $(LIBFT)
# 	$(CC) $(CFLAGS) $^ -o $@ -I$(PARSE_INCS_DIR) -I$(EXECUTE_INCS_DIR) -L$(MLX_DIR) -lmlx $(MLX_FLAGS)
# 	@echo "$(YELLOW)🐥 miniRT compiled! 🐥$(RESET)"
$(NAME): $(MLX) $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@ -I$(PARSE_INCS_DIR) -L$(MLX_DIR) -lmlx $(MLX_FLAGS)
	@echo "$(YELLOW)🐥 miniRT compiled! 🐥$(RESET)"

$(MLX):
	chmod 775 $(MLX_DIR)/configure
	make -C $(MLX_DIR)

clean:
	make clean -C $(LIBFT_DIR)
	@echo "$(YELLOW)🐥 deleted object files for libft 🐥$(RESET)"
	make clean -C $(MLX_DIR)
	@echo "$(YELLOW)🐥 deleted object files for mlx 🐥$(RESET)"
	$(RM) $(OBJS)
	@echo "$(YELLOW)🐥 deleted object files for miniRT 🐥$(RESET)"

fclean: clean
	make fclean -C $(LIBFT_DIR)
	@echo "$(YELLOW)🐥 deleted libft executable 🐥$(RESET)"
	$(RM) $(NAME)
	@echo "$(YELLOW)🐥 deleted miniRT executable 🐥$(RESET)"

re: fclean all

.PHONY: all, clean, fclean, re
