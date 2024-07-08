/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:20:00 by sbueno-s          #+#    #+#             */
/*   Updated: 2024/07/06 19:06:48 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-mac/mlx.h"

# define RESET	 "\033[0m"
# define RED 	 "\033[1;31m"
# define GREEN 	 "\033[1;32m"
# define YELLOW 	 "\033[1;33m"
# define BLUE	"\033[1;34m"
# define MAGENTA	 "\033[1;35m"
# define CYAN 	"\033[1;36m"
# define WHITE 	 "\033[1;37m"

/* MACROS */
# define SIZE 32
# define IMG_NUM 8

# define IBACK "./images/sand.xpm"
# define IOBST "./images/grass.xpm"
# define IPLAY "./images/bunny.xpm"
# define IEXI "./images/closed_door.xpm"
# define ILPLAY "./images/player_closed_door.xpm"
# define IOPDOOR "./images/open_door.xpm"
# define IFINISH "./images/finish.xpm"
# define ICOLL "./images/carrot.xpm"

# ifdef __APPLE__

typedef enum e_key
{
	ESC = 53,
	A = 0,
	S = 1,
	D = 2,
	W = 13,
	Q = 12,
	UP = 126,
	DOWN = 125,
	RIGHT = 124,
	LEFT = 123
}		t_key;

typedef enum e_mask
{
	KEY_MASK = 0,
	CLOSE_MASK = 0
}	t_mask;

# elif defined(__linux__)

typedef enum e_key
{
	ESC = 65307,
	A = 97,
	S = 115,
	D = 100,
	W = 119,
	Q = 113,
	UP = 65362,
	DOWN = 65364,
	RIGHT = 65363,
	LEFT = 65361
}		t_key;

typedef enum e_mask
{
	KEY_MASK = (1L << 0),
	CLOSE_MASK = (1L << 17)
}	t_mask;

# endif

typedef enum e_map_chars
{
	FLOOR = '0',
	WALL = '1',
	COLLECT = 'C',
	PLAYER = 'P',
	EXIT = 'E',
	LOCKP = 'L',
	WOUT = 'O',
	FIN = 'F'
}			t_map_chars;

typedef enum e_img_index
{
	BACK,
	OBST,
	PLAY,
	COLL,
	EXI,
	OPDOOR,
	LOCKPL,
	FINISH
}			t_img_index;

/* STRUCTS */

typedef struct s_point
{
	unsigned int	x;
	unsigned int	y;
}					t_point;

typedef struct s_images
{
	void	*img;
	int		height;
	int		width;
}			t_images;

typedef struct s_map
{
	char			**map_bytes;
	unsigned int	rows;
	unsigned int	columns;
	unsigned int	players;
	unsigned int	exits;
	unsigned int	collect;
	unsigned int	height;
	unsigned int	width;
}					t_map;

typedef struct s_game
{
	t_map			*map;
	t_images		*images;
	void			*mlx;
	void			*window;
	unsigned int	collected;
	unsigned int	moves;
	bool			path;
	t_point			current;
	t_point			next;
	t_point			finish;
}					t_game;

/* FUNCTIONS */

int			extension_check(char *map_name);
int			finish_game(void *data);
void		error_msg(t_game *game, char *msg);
void		kill_game(t_game *game);
void		load_game(char *map_name);
void		check_errors(t_game *game);
void		coord_init(t_game *game);
void		map_dup_free(char **map_dup);
void		floodfill( t_game *game, t_map *map, char **map_dup, t_point pos);
void		set_graphics(t_game *game);
void		place_images(t_game *game, t_point coord);
int			player_moved(t_game *game, t_point next);
void		move_player(t_game *game);
t_map_chars	element(t_game *game, t_point pos);
#endif