/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 12:13:48 by mrio              #+#    #+#             */
/*   Updated: 2025/09/05 14:49:11 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
	line = get_next_line(fd);
	while (line != NULL)
	{
		len = 0;
		while (line[len] && line[len] != '\n')
			len++;
		line[len] = '\0';
		map[i] = line;
		i++;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	close(fd);
	if (i == 0)
		return (free(map), NULL);
	return (map);
}

char	**copy_map(t_game *game)
{
	char	**copy;
	int		width;
	int		height;
	int		i;
	int		j;

	height = game->map_height;
	copy = malloc(sizeof(char *) * (height + 1));
	i = 0;
	if (!copy)
		return (NULL);
	width = game->map_width + 1;
	while (game->map[i])
	{
		copy[i] = malloc(sizeof(char) * width);
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		j = 0;
		while (game->map[i][j])
		{
			copy[i][j] = game->map[i][j];
			j++;
		}
		copy[i][j] = '\0';
		i++;
	}
	copy[i] = NULL;
	return (copy);
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
