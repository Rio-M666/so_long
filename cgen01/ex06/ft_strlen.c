/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:42:48 by mrio              #+#    #+#             */
/*   Updated: 2024/08/13 15:08:21 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include <unistd.h>

// int	ft_strlen(char *str);

// int	main(void)
// {
// 	char	str1[] = "Hello, World!";
// 	char	str2[] = "";
// 	char	str3[] = "C programming";

// 	printf(" '%s': %d\n", str1, ft_strlen(str1));
// 	printf(" '%s': %d\n", str2, ft_strlen(str2));
// 	printf(" '%s': %d\n", str3, ft_strlen(str3));
// 	return (0);
// }

int	ft_strlen(char *str)
{
	int	a;

	a = 0;
	while (str[a] != '\0')
	{
		a++;
	}
	return (a);
}
