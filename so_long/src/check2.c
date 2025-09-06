/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 13:37:17 by mrio              #+#    #+#             */
/*   Updated: 2025/09/06 16:18:05 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	count_elements(t_game *game, t_checkdata *data)
{
	int	i;
	int	j;

	data->player_count = 0;
	data->collectible_count = 0;
	data->exit_count = 0;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == PLAYER)
				(data->player_count)++;
			else if (game->map[i][j] == COLLECTIBLE)
				(data->collectible_count)++;
			else if (game->map[i][j] == EXIT)
				(data->exit_count)++;
			j++;
		}
		i++;
	}
	return (1);
}

int	find_player_position(t_game *game, t_checkdata *data)
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
				data->x = j;
				data->y = i;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	flood_fill(char **map_copy, int x, int y, t_checkdata *data)
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
		data->collectibles_found++;
	else if (map_copy[y][x] == EXIT)
		data->exit_found = 1;
	map_copy[y][x] = 'F';
	flood_fill(map_copy, x + 1, y, data);
	flood_fill(map_copy, x - 1, y, data);
	flood_fill(map_copy, x, y + 1, data);
	flood_fill(map_copy, x, y - 1, data);
}
