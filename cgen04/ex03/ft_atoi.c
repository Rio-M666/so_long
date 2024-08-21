/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:06:23 by mrio              #+#    #+#             */
/*   Updated: 2024/08/21 10:01:58 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	mai;
	int	result;

	result = 0;
	mai = 1;
	while (*str == ' ')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			mai = -mai;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * mai);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%d", ft_atoi(" ---+--+1234ab567"));
// 	return (0);
// }