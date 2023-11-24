# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/20 15:15:26 by yhwang            #+#    #+#              #
#    Updated: 2023/11/23 16:45:26 by yhwang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RESET		:= $(shell tput -Txterm sgr0)
YELLOW		:= $(shell tput -Txterm setaf 3)

NAME = parse
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -f

LIBFT_DIR = ./libft
LIBFT_NAME = libft.a
LIBFT = $(addprefix $(LIBFT_DIR)/, $(LIBFT_NAME))

SRCS_DIR = ./srcs/
INCS_DIR = ./incs/

FILES = $(SRCS_DIR)main \
	$(SRCS_DIR)init \
	$(SRCS_DIR)parse_map \
	$(SRCS_DIR)parse_check_id \
	$(SRCS_DIR)parse_ambient \
	$(SRCS_DIR)parse_camera \
	$(SRCS_DIR)parse_light \
	$(SRCS_DIR)parse_sphere \
	$(SRCS_DIR)parse_plane \
	$(SRCS_DIR)parse_cylinder \
	$(SRCS_DIR)print_scene \
	$(SRCS_DIR)utils_lib \
	$(SRCS_DIR)utils_range \
	$(SRCS_DIR)utils

SRCS = $(addsuffix .c, $(FILES))
OBJS = $(addsuffix .o, $(FILES))

%.o: %.c $(INCS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -lm -I$(INCS_DIR)

all: $(LIBFT_NAME) $(NAME)

$(LIBFT_NAME):
	@make -C $(LIBFT_DIR)
	@echo "$(YELLOW)🐥 libft compiled! 🐥$(RESET)"

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@ -lm -I$(INCS_DIR)
	@echo "$(YELLOW)🐥 miniRT_parse compiled! 🐥$(RESET)"

clean:
	make clean -C $(LIBFT_DIR)
	@echo "$(YELLOW)🐥 deleted object files for libft 🐥$(RESET)"
	$(RM) $(OBJS)
	@echo "$(YELLOW)🐥 deleted object files for miniRT_parse 🐥$(RESET)"

fclean: clean
	make fclean -C $(LIBFT_DIR)
	@echo "$(YELLOW)🐥 deleted libft executable 🐥$(RESET)"
	$(RM) $(NAME)
	@echo "$(YELLOW)🐥 deleted miniRT_parse executable 🐥$(RESET)"

re: fclean all

.PHONY: all, clean, fclean, re
