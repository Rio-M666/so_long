/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 01:33:21 by mrio              #+#    #+#             */
/*   Updated: 2025/09/07 06:38:01 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

int	validate_map(t_game *game)
{
	t_element_count	counts;

	if (!game->map)
		return (printf("game->map miss"), 0);
	if (!check_square(game))
		return (printf("square miss"), 0);
	if (!check_wall(game))
		return (printf("wall miss"), 0);
	if (!check_character(game))
		return (printf("character miss"), 0);
	counts = count_elements(game);
	if (counts.player_count != 1)
		return (printf("player miss\n"), 0);
	if (counts.exit_count != 1)
		return (printf("exit miss"), 0);
	if (counts.collectible_count < 1)
		return (printf("collectible miss"), 0);
	if (!check_path(game))
		return (printf("path miss"), 0);
	return (1);
}

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

int	main(int argc, char *argv[])
{
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
	game.map = read_map(argv[1]);
	if (!game.map)
		return (1);
	init_game_data(&game, game.map);
	if (!validate_map(&game))
		return (free_map(game.map), 1);
	init_mlx(&game);
	load_assets(&game);
	render_map(&game);
	mlx_key_hook(game.window, handle_key, &game);
	mlx_hook(game.window, 17, 0, handle_close, &game);
	mlx_loop(game.mlx);
	return (0);
}
