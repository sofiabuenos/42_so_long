# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/22 16:08:06 by sofiabueno        #+#    #+#              #
#    Updated: 2024/04/25 15:18:24 by sofiabueno       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#COLORS
RESET	= \033[0m
BLACK 	= \033[1;30m
RED 	= \033[1;31m
GREEN 	= \033[1;32m
YELLOW 	= \033[1;33m
BLUE	= \033[1;34m
MAGENTA	= \033[1;35m
CYAN 	= \033[1;36m
WHITE 	= \033[1;37m

#COMMANDS
RM = rm- fr
AR = ar -rcs
UNAME = $(shell uname) # $(shell ...) executa um comando shell e guarda a saída como variável

#PATHS
LIBFT = libft
FTPRINTF = ft_printf
GNL = get_next_line
INC = include
ifeq ($(UNAME), Darwin)
	MLX_PATH = ./minilibx-mac
else
	MLX_PATH = ./minilibx-linux
endif
OBJ_PATH = objs

#FILES
NAME = so_long
SRC = teste
OBJS = $(SRC_FILES:%=%.o)

#FLAGS
CFLAGS = -Wall -Wextra -Werror -g 
LFLAGS = -L ./$(LIBFT) -lft -L ./$(FTPRINTF) -lftprintf -I $(INC)
ifeq ($(UNAME), Darwin) 
	CC = cc
	LFLAGS += -framework OpenGL -framework AppKit -L ./minilibx-mac -lmlx
else ifeq ($(UNAME), FreeBSD) 
	CC = clang
else 
	CC = cc
	LFLAGS += -L ./minilibx-linux -lmlx -Ilmlx -lXext -lX11 -lm
endif

#RULES

all: $(NAME)

$(NAME): $(OBJ_PATH) 

