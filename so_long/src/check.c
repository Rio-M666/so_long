/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 13:29:46 by mrio              #+#    #+#             */
/*   Updated: 2025/09/06 16:23:30 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

int	check_square(t_game *game)
{
	int	width;
	int	i;
	int	current_width;

	if (!game->map || !game->map[0])
		return (0);
	width = game->map_width;
	i = 1;
	while (game->map[i])
	{
		current_width = 0;
		while (game->map[i][current_width])
			current_width++;
		if (current_width != width)
		{
			printf("❌ square error at line %d: expected %d, got %d |%s|\n", i,
				width, current_width, game->map[i]);
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_wall(t_game *game)
{
	int	width;
	int	height;
	int	i;
	int	j;

	width = game->map_width;
	height = game->map_height;
	i = 0;
	while (i < width)
	{
		if ((game->map[0][i] != WALL) || (game->map[height - 1][i] != WALL))
			return (0);
		i++;
	}
	j = 0;
	while (j < height)
	{
		if ((game->map[j][0] != WALL) || (game->map[j][width - 1] != WALL))
			return (0);
		j++;
	}
	return (1);
}

int	check_character(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if ((game->map[i][j] != WALL) && (game->map[i][j] != SPACE)
				&& (game->map[i][j] != EXIT) && (game->map[i][j] != COLLECTIBLE)
				&& (game->map[i][j] != PLAYER))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_path(t_game *game)
{
	t_checkdata	data;

	data.collectibles_found = 0;
	data.exit_found = 0;
	data.total_colectibles = 0;
	if (!find_player_position(game, &data))
		return (0);
	count_elements(game, &data);
	data.map_copy = copy_map(game);
	if (!data.map_copy)
		return (0);
	flood_fill(data.map_copy, data.player_x, data.player_y, &data);
	free_map(data.map_copy);
	return (data.collectibles_found == data.total_colectibles
		&& data.exit_found == 1);
}
