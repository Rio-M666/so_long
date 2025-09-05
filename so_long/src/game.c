/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 13:35:35 by mrio              #+#    #+#             */
/*   Updated: 2025/09/05 14:08:45 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_mlx(t_game *game)
{
	int	window_width;
	int	window_height;

	game->mlx = mlx_init();
	if (!game->mlx)
		exit(1);
	window_width = game->map_width * TILE_SIZE;
	window_height = game->map_height * TILE_SIZE;
	game->window = mlx_new_window(game->mlx, window_width, window_height,
			WINDOW_TITLE);
	if (!game->window)
		exit(1);
}

void	cleanup_game(t_game *game)
{
	if (game->img_player)
		mlx_destroy_image(game->mlx, game->img_player);
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
	if (game->img_collectible)
		mlx_destroy_image(game->mlx, game->img_collectible);
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
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
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
	find_player_position(game, &game->player_x, &game->player_y);
	count_elements(game, &player_count, &game->collectibles_total, &exit_count);
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
