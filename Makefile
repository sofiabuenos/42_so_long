# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/22 16:08:06 by sofiabueno        #+#    #+#              #
#    Updated: 2024/04/26 15:47:36 by sbueno-s         ###   ########.fr        #
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
LIBFTD = libft
FTPRINTFD = ft_printf
GNLD = get_next_line
INC = include
ifeq ($(UNAME), Darwin)
	MLXD = ./minilibx-mac
else
	MLXD = ./minilibx-linux
endif
OBJD = objs

#FILES
NAME = so_long
SRC = teste
OBJS = $(SRC_FILES:%=%.o)
OBJ_TARGET = $(addprefix $(OBJD)/, $(OBJS))

#FLAGS
CFLAGS = -Wall -Wextra -Werror -g 
LFLAGS = -L ./$(LIBFTD) -lft -L ./$(FTPRINTFD) -lftprintf -I $(INC)
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

$(NAME): $(OBJD) 
	echo "$(MAGENTA)Compiling: $(RESET) $(GREEN)libft/*$(RESET)"
	make -C $(LIBFTD)

	echo "$(MAGENTA)Compiling: $(RESET) $(GREEN)ft_printf/*$(RESET)"
	make -C $(FTPRINTFD)

	echo "$(MAGENTA)Compiling: $(RESET) $(GREEN)minilibx/*$(RESET)"
	make -C $(MLXD)

	echo "$(YELLOW)Linking: $(RESET) $(CFLAGS) $(GREEN)*$(RESET)"
	$(CC) $(CFLAGS) $(OBJ_TARGET) $(LFLAGS) -I$(INC)

	echo "$(GREEN)Done!$(RESET)"

$(OBJD)/%.o : $(SRC)/%.c
	$(CC) $(CFLAGS) -c $^ -o $@ -I $(INC)

$(OBJD):
	mkdir -p $(OBJD)

clean:
	make clean -c $(LIBFTD)
	make clean -c $(FTPRINTFD)
	make clean -c $(MLXD)

	

