/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 20:08:10 by mrio              #+#    #+#             */
/*   Updated: 2024/08/13 15:03:15 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include <unistd.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	x;
	int	y;

	x = 0;
	while (x < size - 1)
	{
		y = size - 1;
		while (x < y)
		{
			if (tab[y - 1] > tab[y])
			{
				ft_swap(&tab[y], &tab[y - 1]);
			}
			y--;
		}
		x++;
	}
}

// int	main(void)
// {
// 	int	i[5];
// 	int	j;

// 	i[0] = 2;
// 	i[1] = 10;
// 	i[2] = 1;
// 	i[3] = 5;
// 	i[4] = 4;
// 	ft_sort_int_tab(i, 5);
// 	j = 0;
// 	while (j < 5)
// 	{
// 		printf("%d\n", i[j]);
// 		j++;
// 	}
// }
