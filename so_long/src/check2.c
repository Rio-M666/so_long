/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 13:37:17 by mrio              #+#    #+#             */
/*   Updated: 2025/09/07 06:13:27 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_element_count	count_elements(t_game *game)
{
	t_element_count	counts;
	int				i;
	int				j;

	counts.player_count = 0;
	counts.collectible_count = 0;
	counts.exit_count = 0;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == PLAYER)
				counts.player_count++;
			else if (game->map[i][j] == COLLECTIBLE)
				counts.collectible_count++;
			else if (game->map[i][j] == EXIT)
				counts.exit_count++;
			j++;
		}
		i++;
	}
	return (counts);
}

int	find_player_position(t_game *game)
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
				game->player_x = j;
				game->player_y = i;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	flood_fill(char **map_copy, int x, int y, t_flood_data *data)
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
