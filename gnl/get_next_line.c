/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:37:54 by mrio              #+#    #+#             */
/*   Updated: 2025/05/30 02:03:04 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_check(int fd, char **save)
{
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!*save)
	{
		*save = ft_strdup("");
		if (!*save)
			return (0);
	}
	return (1);
}

static int	read_and_append(int fd, char **save)
{
	char	*buff;
	char	*tmp;
	int		bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (-1);
	bytes = read(fd, buff, BUFFER_SIZE);
	if (bytes == -1)
		return (free(buff), free(*save), *save = NULL, -1);
	if (bytes == 0)
		return (free(buff), 0);
	buff[bytes] = '\0';
	tmp = ft_strjoin(*save, buff);
	free(*save);
	free(buff);
	*save = tmp;
	if (!*save)
		return (-1);
	return (1);
}

static char	*handle_eof(char **save)
{
	char	*line;

	if (*save && **save)
	{
		line = ft_strdup(*save);
		free(*save);
		*save = NULL;
		return (line);
	}
	free(*save);
	*save = NULL;
	return (NULL);
}

static char	*extract_line(char **save, char *pos)
{
	char	*line;
	char	*tmp;

	*pos = '\0';
	line = ft_strjoin(*save, "\n");
	if (!line)
	{
		free(*save);
		*save = NULL;
		return (NULL);
	}
	tmp = ft_strdup(pos + 1);
	free(*save);
	*save = tmp;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*pos;
	int			result;

	if (!(ft_check(fd, &save)))
		return (NULL);
	pos = ft_strchr(save, '\n');
	while (!pos)
	{
		result = read_and_append(fd, &save);
		if (result == -1)
			return (NULL);
		if (result == 0)
			return (handle_eof(&save));
		pos = ft_strchr(save, '\n');
	}
	return (extract_line(&save, pos));
}

// #include <fcntl.h>

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("test.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		printf("Error opening file\n");
// 		return (1);
// 	}
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	if (line)
// 		free(line);
// 	if (close(fd) == -1)
// 	{
// 		printf("Error closing file");
// 		return (1);
// 	}
// 	return (0);
// }
