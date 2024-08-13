/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:42:48 by mrio              #+#    #+#             */
/*   Updated: 2024/08/13 14:05:55 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// #include<stdio.h>

// int	ft_strlen(char *str);

// int	main(void)
// {
// 	char	test_str1[] = "Hello, World!";
// 	char	test_str2[] = "";
// 	char	test_str3[] = "C programming";

// 	printf("Length of '%s': %d\n", test_str1, ft_strlen(test_str1));
// 	printf("Length of '%s': %d\n", test_str2, ft_strlen(test_str2));
// 	printf("Length of '%s': %d\n", test_str3, ft_strlen(test_str3));
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
