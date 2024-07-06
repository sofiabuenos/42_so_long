# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/22 16:08:06 by sofiabueno        #+#    #+#              #
#    Updated: 2024/07/06 18:43:15 by sbueno-s         ###   ########.fr        #
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
	MLXD = ../minilibx-mac
else
	MLXD = ../minilibx-linux
endif

#FILES
NAME = so_long
SRC_FILES = main set_graphics load_game check_errors end_game utils moves

OBJS = $(SRC_FILES:%=%.o)
OBJ_TARGET = $(addprefix $(OBJD)/, $(OBJS))

#FLAGS
CFLAGS = -Wall -Wextra -Werror -g 
LFLAGS = -L ./$(LIBFTD) -lft -L ./$(FTPRINTFD) -lftprintf -I $(INC)
ifeq ($(UNAME), Darwin) 
	CC = cc
	LFLAGS += -framework OpenGL -framework AppKit -L $(MLXD) -lmlx
else ifeq ($(UNAME), FreeBSD) 
	CC = clang
else 
	CC = cc
	LFLAGS += -L $(MLXD) -lmlx -Ilmlx -lXext -lX11 -lm
endif

#RULES

all: $(NAME)


$(NAME): $(OBJD) $(OBJ_TARGET) libft ft_printf minilibx
	echo "$(YELLOW)Linking: $(RESET) $(CFLAGS) $(GREEN)*$(RESET)"
	$(CC) $(CFLAGS) $(OBJ_TARGET) $(LFLAGS) -I$(INC) -o $(NAME)
	echo "$(GREEN)Done!$(RESET)"

libft: $(LIBFTD)/libft.a
$(LIBFTD)/libft.a:
	echo "$(MAGENTA)Compiling: $(RESET) $(GREEN)libft/*$(RESET)"
	make -s -C $(LIBFTD)
	make bonus -s -C $(LIBFTD)

ft_printf: $(FTPRINTFD)/libftprintf.a
$(FTPRINTFD)/libftprintf.a:
	echo "$(MAGENTA)Compiling: $(RESET) $(GREEN)ft_printf/*$(RESET)"
	make -s -C $(FTPRINTFD)

minilibx: $(MLXD)/libmlx.a
$(MLXD)/libmlx.a:
	echo "$(MAGENTA)Compiling: $(RESET) $(GREEN)minilibx/*$(RESET)"
	make -s -C $(MLXD) 2>/dev/null

$(OBJD)/%.o : $(SRCD)/%.c
	$(CC) $(CFLAGS) -c $^ -o $@ -I $(INC)

$(OBJD):
	mkdir -p $(OBJD)

clean:
	make -s -C $(LIBFTD) clean
	make -s -C $(FTPRINTFD) clean
	make -s -C $(MLXD) 2>/dev/null clean

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