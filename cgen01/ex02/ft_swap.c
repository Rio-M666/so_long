/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 13:19:26 by mrio              #+#    #+#             */
/*   Updated: 2024/08/13 14:34:50 by mrio             ###   ########.fr       */
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

// int	main(void)
// {
// 	int a;
// 	int b;
// 	a = 3;
// 	b = 4;
// 	printf("before  a=%d , b=%d\n", a, b);
// 	ft_swap(&a, &b);
// 	printf("after  a=%d , b=%d", a, b);
// 	return (0);
// }