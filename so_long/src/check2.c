/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 13:37:17 by mrio              #+#    #+#             */
/*   Updated: 2025/09/05 14:49:42 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	count_elements(t_game *game, int *player_count, int *collectible_count,
		int *exit_count)
{
	int	i;
	int	j;

	*player_count = 0;
	*collectible_count = 0;
	*exit_count = 0;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == PLAYER)
				(*player_count)++;
			else if (game->map[i][j] == COLLECTIBLE)
				(*collectible_count)++;
			else if (game->map[i][j] == EXIT)
				(*exit_count)++;
			j++;
		}
		i++;
	}
	return (1);
}

int	find_player_position(t_game *game, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == PLAYER)
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

void	flood_fill(t_game *game, char **map_copy, int x, int y,
		int *collectibles_found, int *exit_found)
{
	int	width;
	int	height;

	width = game->map_width;
	height = game->map_height;
	if (x < 0 || x >= width || y < 0 || y >= height)
		return ;
	if (map_copy[y][x] == WALL || map_copy[y][x] == 'F')
		return ;
	if (map_copy[y][x] == COLLECTIBLE)
		(*collectibles_found)++;
	else if (map_copy[y][x] == EXIT)
		(*exit_found) = 1;
	map_copy[y][x] = 'F';
	flood_fill(game, map_copy, x + 1, y, collectibles_found, exit_found);
	flood_fill(game, map_copy, x - 1, y, collectibles_found, exit_found);
	flood_fill(game, map_copy, x, y + 1, collectibles_found, exit_found);
	flood_fill(game, map_copy, x, y - 1, collectibles_found, exit_found);
}
