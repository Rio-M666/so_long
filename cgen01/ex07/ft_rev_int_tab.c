/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:44:38 by mrio              #+#    #+#             */
/*   Updated: 2024/08/12 20:06:44 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap(int *a, int *b);

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	j = size - 1;
	while (i < j - 1)
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

int	main(void)
{
	int	c[5];

	c[0] = 1;
	c[1] = 10;
	c[2] = 20;
	c[3] = 30;
	c[4] = 40;
	ft_rev_int_tab(c, 5);
}
