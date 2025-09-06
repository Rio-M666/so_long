#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define TILE_SIZE 32

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

typedef struct s_checkdata
{
	int		collectibles_found;
	int		exit_found;
	int		total_colectibles;
	int		player_x;
	int		player_y;
	char	**map_copy;
	int		player_count;
	int		exit_count;
	int		collectible_count;
	int		x;
	int		y;
}			t_checkdata;

int			check_filename(char *filename);
int			check_square(t_game *game);
int			check_wall(t_game *game);
int			check_character(t_game *game);
int			check_path(t_game *game);
int			count_elements(t_game *game, t_checkdata *data);
int			find_player_position(t_game *game, t_checkdata *data);
void		flood_fill(char **map_copy, int x, int y, t_checkdata *data);

void		init_mlx(t_game *game);
void		cleanup_game(t_game *game);
void		init_game_data(t_game *game, char **map);
int			check_move(t_game *game, int x, int y);
void		move_player(t_game *game, int x, int y);
int			handle_key(int keycode, t_game *game);
int			handle_close(t_game *game);
void		load_assets(t_game *game);
void		render_tile(t_game *game, char tile, int x, int y);
void		render_map(t_game *game);
int			validate_map(t_game *game);
char		**read_map(char *filename);
char		**copy_map(t_game *game);
void		free_map(char **map);
int			map_width(char **map);
int			map_height(char **map);
#endif