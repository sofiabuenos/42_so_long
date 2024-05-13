# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/22 16:08:06 by sofiabueno        #+#    #+#              #
#    Updated: 2024/05/09 15:23:25 by sofiabueno       ###   ########.fr        #
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
RM = rm -fr
AR = ar -rcs
UNAME = $(shell uname)

#PATHS
LIBFTD = libft
FTPRINTFD = ft_printf
INC = inc
SRCD = src
OBJD = objs

ifeq ($(UNAME), Darwin)
	MLXD = ./minilibx-mac
else
	MLXD = ./minilibx-linux
endif

#FILES
NAME = so_long
SRC_FILES = main checks init exit_and_free utils

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

$(NAME): $(OBJD) $(OBJ_TARGET) 
	echo "$(MAGENTA)Compiling: $(RESET) $(GREEN)libft/*$(RESET)"
	make -s -C $(LIBFTD)
	make bonus -s -C $(LIBFTD)

	echo "$(MAGENTA)Compiling: $(RESET) $(GREEN)ft_printf/*$(RESET)"
	make -s -C $(FTPRINTFD)

	echo "$(MAGENTA)Compiling: $(RESET) $(GREEN)minilibx/*$(RESET)"
	make -s -C $(MLXD) 2>/dev/null

	echo "$(YELLOW)Linking: $(RESET) $(CFLAGS) $(GREEN)*$(RESET)"
	$(CC) $(CFLAGS) $(OBJ_TARGET) $(LFLAGS) -I$(INC) -o $(NAME)

	echo "$(GREEN)Done!$(RESET)"

$(OBJD)/%.o : $(SRCD)/%.c
	$(CC) $(CFLAGS) -c $^ -o $@ -I $(INC)

$(OBJD):
	mkdir -p $(OBJD)

clean:
	make clean -s -C $(LIBFTD)
	make clean -s -C $(FTPRINTFD)
	make clean -s -C $(MLXD) 2>/dev/null

	echo "$(RED)Deleted: $(RESET) $(GREEN)$(OBJD)$(RESET)"
	$(RM) $(OBJD)

fclean: clean
	make fclean -s -C $(LIBFTD)
	make fclean -s -C $(FTPRINTFD)

	echo "$(RED)Deleted: $(RESET) $(GREEN)$(NAME)$(RESET)"
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

.SILENT: