/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 20:39:16 by mrio              #+#    #+#             */
/*   Updated: 2024/08/26 14:17:07 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	i;

	if (min >= max)
	{
		return (NULL);
	}
	range = (int *)malloc((max - min) * 4);
	if (range == NULL)
		return (NULL);
	i = 0;
	while (i < (max - min))
	{
		range[i] = min + i;
		i++;
	}
	return (range);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int *range;
// 	int i;
// 	int min = 2;
// 	int max = 8;

// 	range = ft_range(min, max);
// 	if (range != NULL)
// 	{
// 		for (i = 0; i < (max - min); i++)
// 		{
// 			printf("%d ", range[i]);
// 		}
// 		printf("\n");
// 		free(range);
// 	}
// 	return (0);
// }