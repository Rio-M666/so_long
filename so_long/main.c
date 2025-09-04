/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 01:33:21 by mrio              #+#    #+#             */
/*   Updated: 2025/09/04 22:43:32 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	check_filename(char *filename)
{
	int	len;

	if (!filename)
		return (printf("filename is NULL\n"), 0);
	len = 0;
	while (filename[len])
		len++;
	if (len < 4)
		return (printf("file name isn't correct\n"), 0);
	if (filename[len - 4] != '.' || filename[len - 3] != 'b' || filename[len
		- 2] != 'e' || filename[len - 1] != 'r')
	{
		return (printf("file name isn't correct\n"), 0);
	}
	printf("File's lastname is correct!!!!\n");
	return (1);
}
char	**read_map(char *filename)
{
	int		fd;
	char	**map;
	int		i;
	char	*line;
	int		len;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = malloc(sizeof(char *) * 1001);
	if (!map)
	{
		close(fd);
		return (NULL);
	}
	i = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		len = 0;
		while (line[len] && line[len] != '\n')
			len++;
		line[len] = '\0';
		map[i] = line;
		i++;
	}
	map[i] = NULL;
	close(fd);
	if (i == 0)
		return (free(map), NULL);
	return (map);
}

int	map_width(char **map)
{
	int	width;

	if (!map || !map[0])
		return (0);
	width = 0;
	while (map[0][width])
		width++;
	return (width);
}

int	map_height(char **map)
{
	int	height;

	if (!map)
		return (0);
	height = 0;
	while (map[height])
		height++;
	return (height);
}

int	check_square(char **map)
{
	int	width;
	int	i;
	int	current_width;

	if (!map || !map[0])
		return (0);
	width = map_width(map);
	i = 1;
	while (map[i])
	{
		current_width = 0;
		while (map[i][current_width])
			current_width++;
		if (current_width != width)
			return (0);
		i++;
	}
	return (1);
}
int	check_wall(char **map)
{
	int	width;
	int	height;
	int	i;
	int	j;

	width = map_width(map);
	height = map_height(map);
	i = 0;
	while (i < width)
	{
		if ((map[0][i] != WALL) || (map[height - 1][i] != WALL))
			return (0);
		i++;
	}
	j = 0;
	while (j < height)
	{
		if ((map[j][0] != WALL) || (map[j][width - 1] != WALL))
			return (0);
		j++;
	}
	return (1);
}
int	check_character(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((map[i][j] != WALL) && (map[i][j] != SPACE)
				&& (map[i][j] != EXIT) && (map[i][j] != COLLECTIBLE)
				&& (map[i][j] != PLAYER))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
int	count_elements(char **map, int *player_count, int *collectible_count,
		int *exit_count)
{
	int	i;
	int	j;

	*player_count = 0;
	*collectible_count = 0;
	*exit_count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == PLAYER)
				(*player_count)++;
			else if (map[i][j] == COLLECTIBLE)
				(*collectible_count)++;
			else if (map[i][j] == EXIT)
				(*exit_count)++;
			j++;
		}
		i++;
	}
	return (1);
}

int	find_player_position(char **map, int *x, int *y)
{
	int i, j;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == PLAYER)
			{
				*x = j;
				*y = i;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
char	**copy_map(char **map)
{
	char	**copy;
	int		width;
	int		height;
	int		i;
	int		j;

	height = map_height(map);
	copy = malloc(sizeof(char *) * (height + 1));
	i = 0;
	if (!copy)
		return (NULL);
	while (map[i])
	{
		width = map_width(map) + 1;
		copy[i] = malloc(sizeof(char) * width);
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		j = 0;
		while (map[i][j])
		{
			copy[i][j] = map[i][j];
			j++;
		}
		copy[i][j] = '\0';
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	flood_fill(char **map_copy, int x, int y, int *collectibles_found,
		int *exit_found)
{
	int	width;
	int	height;

	width = map_width(map_copy);
	height = map_height(map_copy);
	if (x < 0 || x >= width || y < 0 || y >= height)
		return ;
	if (map_copy[y][x] == WALL || map_copy[y][x] == 'F')
		return ;
	if (map_copy[y][x] == COLLECTIBLE)
		(*collectibles_found)++;
	else if (map_copy[y][x] == EXIT)
		(*exit_found) = 1;
	map_copy[y][x] = 'F';
	flood_fill(map_copy, x + 1, y, collectibles_found, exit_found);
	flood_fill(map_copy, x - 1, y, collectibles_found, exit_found);
	flood_fill(map_copy, x, y + 1, collectibles_found, exit_found);
	flood_fill(map_copy, x, y - 1, collectibles_found, exit_found);
}

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	check_path(char **map)
{
	char	**map_copy;
	int		collectibles_found;
	int		exit_found;
	int		total_colectables;
	int		result;
	int		player_x;
	int		player_y;
	int		player_count;
	int		exit_count;

	collectibles_found = 0;
	exit_found = 0;
	total_colectables = 0;
	if (!find_player_position(map, &player_x, &player_y))
		return (0);
	count_elements(map, &player_count, &total_colectables, &exit_count);
	map_copy = copy_map(map);
	if (!map_copy)
		return (0);
	flood_fill(map_copy, player_x, player_y, &collectibles_found, &exit_found);
	result = (collectibles_found == total_colectables && exit_found == 1);
	free_map(map_copy);
	return (result);
}

int	validate_map(char **map)
{
	int	player_count;
	int	exit_count;
	int	collectible_count;

	if (!map)
		return (printf("map miss"), 0);
	if (!check_square(map))
		return (printf("sqare miss"), 0);
	if (!check_wall(map))
		return (printf("wall miss"), 0);
	if (!check_character(map))
		return (printf("character miss"), 0);
	count_elements(map, &player_count, &collectible_count, &exit_count);
	if (player_count != 1)
		return (printf("player miss\n"), 0);
	if (exit_count != 1)
		return (printf("exit miss"), 0);
	if (collectible_count < 1)
		return (printf("collectible miss"), 0);
	if (!check_path(map))
		return (printf("path miss"), 0);
	return (1);
}
int	init_mlx(t_game *game)
{
	int	window_width;
	int	window_height;

	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	window_width = game->map_width * TILE_SIZE;
	window_height = game->map_height * TILE_SIZE;
	game->window = mlx_new_window(game->mlx, window_width, window_height,
			WINDOW_TITLE);
	if (!game->window)
		return (0);
	return (1);
}
void	load_assets(t_game *game)
{
	int	w;
	int	h;

	game->img_background = mlx_xpm_file_to_image(game->mlx,
			"assets/background.xpm", &w, &h);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx,
			"assets/collectible.xpm", &w, &h);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "assets/wall.xpm", &w,
			&h);
	game->img_player = mlx_xpm_file_to_image(game->mlx, "assets/player.xpm", &w,
			&h);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "assets/exit.xpm", &w,
			&h);
	game->img_space = mlx_xpm_file_to_image(game->mlx, "assets/space.xpm", &w,
			&h);
}
void	render_tile(t_game *game, char tile, int x, int y)
{
	int	pixel_x;
	int	pixel_y;

	pixel_x = x * TILE_SIZE;
	pixel_y = y * TILE_SIZE;
	mlx_put_image_to_window(game->mlx, game->window, game->img_background,
		pixel_x, pixel_y);
	if (tile == WALL)
		mlx_put_image_to_window(game->mlx, game->window, game->img_wall,
			pixel_x, pixel_y);
	else if (tile == COLLECTIBLE)
		mlx_put_image_to_window(game->mlx, game->window, game->img_collectible,
			pixel_x, pixel_y);
	else if (tile == EXIT)
		mlx_put_image_to_window(game->mlx, game->window, game->img_exit,
			pixel_x, pixel_y);
	else
		mlx_put_image_to_window(game->mlx, game->window, game->img_space,
			pixel_x, pixel_y);
	if (game->player_x == x && game->player_y == y)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->img_player,
			pixel_x, pixel_y);
	}
}
void	render_map(t_game *game)
{
	int	x;
	int	y;

	mlx_clear_window(game->mlx, game->window);
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			render_tile(game, game->map[y][x], x, y);
			x++;
		}
		y++;
	}
}
void	cleanup_game(t_game *game)
{
	if (game->window)
	{
		mlx_destroy_window(game->mlx, game->window);
		game->window = NULL;
	}
	if (game->map)
	{
		free_map(game->map);
		game->map = NULL;
	}
}
void	init_game_data(t_game *game, char **map)
{
	int	player_count;
	int	exit_count;

	game->map = map;
	game->map_width = map_width(map);
	game->map_height = map_height(map);
	game->moves = 0;
	game->collectibles_collected = 0;
	game->game_won = 0;
	game->player_on_exit = 0;
	find_player_position(map, &game->player_x, &game->player_y);
	count_elements(map, &player_count, &game->collectibles_total, &exit_count);
}

int	check_move(t_game *game, int x, int y)
{
	int		width;
	int		height;
	char	tile;

	width = game->map_width;
	height = game->map_height;
	if (x < 0 || x >= width || y < 0 || y >= height)
		return (0);
	tile = game->map[y][x];
	if (tile == WALL)
		return (0);
	return (1);
}
void	move_player(t_game *game, int x, int y)
{
	int		new_x;
	int		new_y;
	char	current;
	char	target;

	new_x = game->player_x + x;
	new_y = game->player_y + y;
	if (!check_move(game, new_x, new_y))
		return ;
	if (game->player_on_exit)
		current = EXIT;
	else
		current = SPACE;
	target = game->map[new_y][new_x];
	game->map[game->player_y][game->player_x] = current;
	game->player_on_exit = 0;
	if (target == COLLECTIBLE)
	{
		game->map[new_y][new_x] = SPACE;
		game->collectibles_collected++;
	}
	else if (target == EXIT)
	{
		game->player_on_exit = 1;
		if (game->collectibles_collected == game->collectibles_total)
		{
			game->moves++;
			cleanup_game(game);
			exit(0);
		}
	}
	game->player_x = new_x;
	game->player_y = new_y;
	game->moves++;
	render_map(game);
}
int	handle_key(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
	{
		cleanup_game(game);
		exit(0);
	}
	else if (keycode == KEY_W || keycode == KEY_UP)
		move_player(game, 0, -1);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		move_player(game, -1, 0);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_player(game, 0, 1);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_player(game, 1, 0);
	return (0);
}
int	handle_close(t_game *game)
{
	cleanup_game(game);
	exit(0);
	return (0);
}
int	main(int argc, char *argv[])
{
	char	**map;
	t_game	game;

	if (argc != 2)
	{
		printf("File Not Found\n");
		return (1);
	}
	if (!check_filename(argv[1]))
	{
		return (1);
	}
	map = read_map(argv[1]);
	if (!map)
		return (1);
	if (!validate_map(map))
	{
		free_map(map);
		return (1);
	}
	init_game_data(&game, map);
	if (!init_mlx(&game))
		return (1);
	load_assets(&game);
	render_map(&game);
	mlx_key_hook(game.window, handle_key, &game);
	mlx_hook(game.window, 17, 0, handle_close, &game);
	mlx_loop(game.mlx);
	return (0);
}
