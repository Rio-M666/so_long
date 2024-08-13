/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 20:08:10 by mrio              #+#    #+#             */
/*   Updated: 2024/08/13 11:08:49 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
	ft_putchar(*a);
	ft_putchar(*b);
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	x;
	int	y;

	x = 0;
	y = size - 1;
	while (x < size)
	{
		while (x < y)
		{
			if (&tab[y - 1] > &tab[y])
			{
				ft_swap(&tab[y], &tab[y - 1]);
			}
			y--;
		}
		x++;
	}
}

int	main(void)
{
	int	i[5];

	i[0] = 1;
	i[1] = 10;
	i[2] = 20;
	i[3] = 30;
	i[4] = 40;
	ft_sort_int_tab(i, 5);
}
