/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 01:33:21 by mrio              #+#    #+#             */
/*   Updated: 2025/09/05 14:49:17 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	validate_map(t_game *game)
{
	int	player_count;
	int	exit_count;
	int	collectible_count;

	if (!game->map)
		return (printf("game->map miss"), 0);
	if (!check_square(game))
		return (printf("square miss"), 0);
	if (!check_wall(game))
		return (printf("wall miss"), 0);
	if (!check_character(game))
		return (printf("character miss"), 0);
	count_elements(game, &player_count, &collectible_count, &exit_count);
	if (player_count != 1)
		return (printf("player miss\n"), 0);
	if (exit_count != 1)
		return (printf("exit miss"), 0);
	if (collectible_count < 1)
		return (printf("collectible miss"), 0);
	if (!check_path(game))
		return (printf("path miss"), 0);
	return (1);
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
