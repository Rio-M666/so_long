/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:41:20 by mrio              #+#    #+#             */
/*   Updated: 2024/08/13 14:16:07 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include <unistd.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	x;

	x = *a;
	*a = *a / *b;
	*b = x % *b;
}

// int	main(void)
// {
// 	int a = 13;
// 	int b = 4;

// 	ft_ultimate_div_mod(&a, &b);

// 	printf("a = %d\n", a);
// 	printf("b = %d\n", b);

// 	return (0);
// }