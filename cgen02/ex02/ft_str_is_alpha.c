/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:16:33 by mrio              #+#    #+#             */
/*   Updated: 2024/08/13 21:17:09 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include <unistd.h>

int	ft_str_is_alpha(char *str)
{
	while (*str != '\0')
	{
		if ((65 <= *str && *str <= 90) || (97 <= *str && *str <= 122))
		{
			str++;
		}
		else
		{
			return (0);
		}
	}
	return (1);
}

// int	main(void)
// {
// 	char *a;
// 	int result;
// 	a = "pihfieguv";
// 	ft_str_is_alpha(a);
// 	result = ft_str_is_alpha(a);
// 	printf("%d", result);
// 	return (0);
// }