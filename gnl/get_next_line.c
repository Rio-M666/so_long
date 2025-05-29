/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:37:54 by mrio              #+#    #+#             */
/*   Updated: 2025/05/29 17:07:28 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*save;
	char		*pos;
	char		*buff;
	int			bytes;
	char		*line;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!save)
		save = ft_strdup("");
	while (!(pos = ft_strchr(save, '\n')))
	{
		buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buff)
			return (NULL);
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		if (bytes == 0)
		{
			free(buff);
			if (save && *save)
				line = ft_strdup(save);
			free(save);
			save = NULL;
			return (line);
		}
		buff[bytes] = '\0';
		tmp = ft_strjoin(save, buff);
		free(save);
		free(buff);
		save = tmp;
		if (!save)
			return (NULL);
	}
	*pos = '\0';
	line = ft_strjoin(save, "\n");
	tmp = ft_strdup(pos + 1);
	free(save);
	save = tmp;
	return (line);
}

#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file\n");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	if (line)
		free(line);
	if (close(fd) == -1)
	{
		printf("Error closing file");
		return (1);
	}
	return (0);
}
