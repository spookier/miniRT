# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acostin <acostin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/09 14:13:22 by acostin           #+#    #+#              #
#    Updated: 2023/10/07 20:18:48 by acostin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

LIBFT = ft_atoi \
		ft_bzero \
		ft_calloc \
		ft_isalnum \
		ft_isalpha \
		ft_isascii \
		ft_isdigit \
		ft_isprint \
		ft_itoa \
		ft_memchr \
		ft_memcmp \
		ft_memcpy \
		ft_memmove \
		ft_memset \
		ft_putchar_fd \
		ft_putendl_fd \
		ft_putnbr_fd \
		ft_putstr_fd \
		ft_split \
		ft_strchr \
		ft_strcmp \
		ft_strdup \
		ft_striteri \
		ft_strjoin \
		ft_strlcat \
		ft_strlcpy \
		ft_strlen \
		ft_strmapi \
		ft_strncmp \
		ft_strnstr \
		ft_strrchr \
		ft_strtrim \
		ft_substr \
		ft_tolower \
		ft_toupper \
		ft_lstadd_back \
	  	ft_lstadd_front \
		ft_lstclear \
		ft_lstdelone \
		ft_lstiter \
	  	ft_lstlast \
		ft_lstmap \
	  	ft_lstnew \
		ft_lstsize \
		ft_strcpy \

GNL = get_next_line \
      		get_next_line_utils \

FT_PRINTF = ft_printf \
	    	count_flags \
	    	print_all \
	    	utils/utils_char \
	    	utils/utils_decimal \
	    	utils/utils_hexa \
	    	utils/utils_pointer \
	    	utils/utils_str \
	    	utils/utils_unsigned_int \

INCS_DIR = ./incs

LIBFT_DIR = ./srcs/libft
FT_PRINTF_DIR = ./srcs/ft_printf
GNL_DIR = ./srcs/get_next_line

LIBFT_SRCS = $(addprefix $(LIBFT_DIR)/, $(addsuffix .c, $(LIBFT)))
FT_PRINTF_SRCS = $(addprefix $(FT_PRINTF_DIR)/, $(addsuffix .c, $(FT_PRINTF)))
GNL_SRCS = $(addprefix $(GNL_DIR)/, $(addsuffix .c, $(GNL)))

LIBFT_OBJS = $(addprefix $(LIBFT_DIR)/, $(addsuffix .o, $(LIBFT)))
FT_PRINTF_OBJS = $(addprefix $(FT_PRINTF_DIR)/, $(addsuffix .o, $(FT_PRINTF)))
GNL_OBJS = $(addprefix $(GNL_DIR)/, $(addsuffix .o, $(GNL)))

.c.o: $(LIBFT_SRCS) $(FT_PRINTF_SRCS) $(GNL_SRCS) $(INCS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCS_DIR)

$(NAME): $(LIBFT_OBJS) $(FT_PRINTF_OBJS) $(GNL_OBJS)
	$(AR) $@ $^

all: $(NAME)

clean:
	$(RM) $(LIBFT_OBJS) $(FT_PRINTF_OBJS) $(GNL_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
