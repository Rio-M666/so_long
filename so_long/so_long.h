#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define TILE_SIZE 64

# define WINDOW_TITLE "SO_LONG"

# define WALL '1'
# define SPACE '0'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define PLAYER 'P'

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363

typedef struct s_game
{
	void	*mlx;
	void	*window;
	char	**map;
	int		map_width;
	int		map_height;
	int		player_x;
	int		player_y;
	int		collectibles_total;
	int		collectibles_collected;
	int		moves;
	int		game_won;
	int		player_on_exit;
	void	*img_wall;
	void	*img_player;
	void	*img_exit;
	void	*img_collectible;
	void	*img_space;
	void	*img_background;

}			t_game;

#endif