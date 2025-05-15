/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:37:54 by mrio              #+#    #+#             */
/*   Updated: 2025/05/15 17:02:01 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*tmp;
	int		num;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
    
	num = read(fd, tmp, BUFFER_SIZE);
	if (num == -1)
		return (NULL);
	return (0);
}

#include <fcntl.h>

int	main(void)
{
	int fd;
	char *line;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file\n");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		// free(line);
	}
	// if (line)
	// 	free(line);
	if (close(fd) == -1)
	{
		printf("Error closing file");
		return (1);
	}
	return (0);
}