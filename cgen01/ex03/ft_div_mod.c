/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 13:34:41 by mrio              #+#    #+#             */
/*   Updated: 2024/08/13 14:29:30 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include <unistd.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

// int	main(void)
// {
// 	int a;
// 	int b;
// 	int div;
// 	int mod;
// 	a = 25;
// 	b = 11;
// 	ft_div_mod(a, b, &div, &mod);
// 	printf("%d,%d", div, mod);
// 	return (0);
// }