# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/23 16:05:09 by yhwang            #+#    #+#              #
#    Updated: 2023/12/20 21:53:01 by yhwang           ###   ########.fr        #
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
EXECUTE_DIR = ./execute/srcs/

PARSE_INCS_DIR = ./parse/incs/
EXECUTE_INCS_DIR = ./execute/incs/

FILES = 	./main \
			$(PARSE_DIR)parse_main \
			$(PARSE_DIR)parse_init \
			$(PARSE_DIR)parse_map \
			$(PARSE_DIR)parse_check_id \
			$(PARSE_DIR)parse_ambient \
			$(PARSE_DIR)parse_camera \
			$(PARSE_DIR)parse_light \
			$(PARSE_DIR)parse_sphere \
			$(PARSE_DIR)parse_plane \
			$(PARSE_DIR)parse_cylinder \
			$(PARSE_DIR)utils_lib \
			$(PARSE_DIR)utils_range \
			$(PARSE_DIR)utils\
			$(EXECUTE_DIR)alloc_mem \
			$(EXECUTE_DIR)free_mem \
			$(EXECUTE_DIR)set_cam_vec \
			$(EXECUTE_DIR)start_draw \
			$(EXECUTE_DIR)key_hooks \
			$(EXECUTE_DIR)exit_prog \
			$(EXECUTE_DIR)init_prog \
			$(EXECUTE_DIR)init_scene \
			$(EXECUTE_DIR)init_vars \
			$(EXECUTE_DIR)vec3_1 \
			$(EXECUTE_DIR)vec3_2 \
			$(EXECUTE_DIR)matrix \
			$(EXECUTE_DIR)viewport \
			$(EXECUTE_DIR)ray \
			$(EXECUTE_DIR)ray_sp_pl \
			$(EXECUTE_DIR)ray_cy_body \
			$(EXECUTE_DIR)ray_cy_circle \
			$(EXECUTE_DIR)light \
			$(EXECUTE_DIR)rgb

SRCS = $(addsuffix .c, $(FILES))
OBJS = $(addsuffix .o, $(FILES))

%.o: %.c $(PARSE_INCS_DIR) $(EXECUTE_INCS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(PARSE_INCS_DIR) -I$(EXECUTE_INCS_DIR)

all: $(LIBFT_NAME) $(NAME)

$(LIBFT_NAME):
	@make -C $(LIBFT_DIR)
	@echo "$(YELLOW)🐥 libft compiled! 🐥$(RESET)"

$(NAME): $(MLX) $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@ -I$(PARSE_INCS_DIR) -I$(EXECUTE_INCS_DIR) -L$(MLX_DIR) -lmlx $(MLX_FLAGS)
	@echo "$(YELLOW)🐥 miniRT compiled! 🐥$(RESET)"

$(MLX):
	chmod 775 $(MLX_DIR)/configure
	@make -C $(MLX_DIR)
	@echo "$(YELLOW)🐥 mlx compiled! 🐥$(RESET)"

clean:
	@make clean -C $(LIBFT_DIR)
	@echo "$(YELLOW)🐥 deleted object files for libft 🐥$(RESET)"
	@make clean -C $(MLX_DIR)
	@echo "$(YELLOW)🐥 deleted object files for mlx 🐥$(RESET)"
	@$(RM) $(OBJS)
	@echo "$(YELLOW)🐥 deleted object files for miniRT 🐥$(RESET)"

fclean: clean
	make fclean -C $(LIBFT_DIR)
	@echo "$(YELLOW)🐥 deleted libft executable 🐥$(RESET)"
	$(RM) $(NAME)
	@echo "$(YELLOW)🐥 deleted miniRT executable 🐥$(RESET)"

re: fclean all

.PHONY: all, clean, fclean, re
