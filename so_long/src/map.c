/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 12:13:48 by mrio              #+#    #+#             */
/*   Updated: 2025/09/16 10:22:44 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*check_line(char *line)
{
	int	len;

	len = 0;
	while (line[len] && line[len] != '\n')
		len++;
	line[len] = '\0';
	return (line);
}

char	**read_map(char *filename)
{
	int		fd;
	char	**map;
	int		i;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = malloc(sizeof(char *) * 1001);
	if (!map)
		return (close(fd), NULL);
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		map[i] = check_line(line);
		i++;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	close(fd);
	if (i == 0)
		return (free(map), NULL);
	return (map);
}

static char	*copy_line(char *original, int width)
{
	char	*line;
	int		j;

	line = malloc(sizeof(char) * width);
	if (!line)
		return (NULL);
	j = 0;
	while (original[j])
	{
		line[j] = original[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	**copy_map(t_game *game)
{
	char	**copy;
	int		width;
	int		height;
	int		i;

	height = game->map_height;
	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	width = game->map_width + 1;
	i = 0;
	while (game->map[i])
	{
		copy[i] = copy_line(game->map[i], width);
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
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
