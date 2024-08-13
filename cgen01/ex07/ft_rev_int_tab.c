/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:44:38 by mrio              #+#    #+#             */
/*   Updated: 2024/08/13 15:05:57 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include <unistd.h>

void	ft_swap(int *a, int *b);

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	j = size - 1;
	while (i < j)
	{
		ft_swap(&tab[i], &tab[j]);
		i++;
		j--;
	}
}

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

// int	main(void)
// {
// 	int	c[5];
// 	int	i;

// 	c[0] = 1;
// 	c[1] = 3;
// 	c[2] = 5;
// 	c[3] = 7;
// 	c[4] = 9;
// 	ft_rev_int_tab(c, 5);
// 	i = 0;
// 	while (i < 5)
// 	{
// 		printf("%d ", c[i]);
// 		i++;
// 	}
// 	printf("\n");
// 	return (0);
// }
