/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 23:04:14 by mrio              #+#    #+#             */
/*   Updated: 2024/08/15 09:28:02 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	char	*c;

	c = str;
	while (*str != '\0')
	{
		if (65 <= *str && *str <= 90)
		{
			*str += 32;
		}
		str++;
	}
	return (c);
}

// int	main(void)
// {
// 	char str[] = "HELLO WORLD!";
// 	printf("%s\n", *ft_strlowcase(str));
// 	return (0);
// }