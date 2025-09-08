/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 13:35:07 by mrio              #+#    #+#             */
/*   Updated: 2025/09/08 13:46:42 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	load_assets(t_game *game)
{
	int	w;
	int	h;

	game->img_collectible = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible.xpm", &w, &h);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &w,
			&h);
	game->img_player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm",
			&w, &h);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", &w,
			&h);
}

void	render_tile(t_game *game, char tile, int x, int y)
{
	int	pixel_x;
	int	pixel_y;

	pixel_x = x * TILE_SIZE;
	pixel_y = y * TILE_SIZE;
	if (tile == WALL && game->img_wall)
		mlx_put_image_to_window(game->mlx, game->window, game->img_wall,
			pixel_x, pixel_y);
	else if (tile == COLLECTIBLE && game->img_collectible)
		mlx_put_image_to_window(game->mlx, game->window, game->img_collectible,
			pixel_x, pixel_y);
	else if (tile == EXIT && game->img_exit)
		mlx_put_image_to_window(game->mlx, game->window, game->img_exit,
			pixel_x, pixel_y);
	if (game->player_x == x && game->player_y == y && game->img_player)
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
