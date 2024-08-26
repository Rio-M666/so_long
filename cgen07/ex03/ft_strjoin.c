/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 11:59:55 by mrio              #+#    #+#             */
/*   Updated: 2024/08/26 14:16:49 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *c)
{
	int	i;

	while (c[i])
		i++;
	return (i);
}

void	ft_strcpy(char *dest, char *src)
{
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
}

int	calculate_total_len(int size, char **strs, int sep_len)
{
	int	total_len;
	int	i;

	total_len = 0;
	i = 0;
	while (i < size)
	{
		total_len += ft_strlen(strs[i]);
		if (i < size - 1)
			total_len += sep_len;
		i++;
	}
	return (total_len);
}

char	*join_strings(int size, char **strs, char *sep, char *result)
{
	int		sep_len;
	char	*ptr;
	int		i;

	sep_len = ft_strlen(sep);
	ptr = result;
	i = 0;
	while (i < size)
	{
		ft_strcpy(ptr, strs[i]);
		ptr += ft_strlen(strs[i]);
		if (i < size - 1)
		{
			ft_strcpy(ptr, sep);
			ptr += sep_len;
		}
		i++;
	}
	*ptr = '\0';
	return (result);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		sep_len;
	int		total_len;
	char	*result;

	if (size == 0)
	{
		result = (char *)malloc(1);
		if (result == NULL)
			return (NULL);
		result[0] = '\0';
		return (result);
	}
	sep_len = ft_strlen(sep);
	total_len = calculate_total_len(size, strs, sep_len);
	result = (char *)malloc(total_len + 1);
	if (result == NULL)
		return (NULL);
	return (join_strings(size, strs, sep, result));
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*strs1[] = {"Hello", "World", "yea", "you"};
// 	char	*sep1;
// 	char	*result1;

// 	sep1 = ":";
// 	result1 = ft_strjoin(4, strs1, sep1);
// 	printf("Result 1: %s\n", result1);
// 	free(result1);
// 	return (0);
// }
