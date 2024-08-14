/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:49:49 by mrio              #+#    #+#             */
/*   Updated: 2024/08/14 15:11:32 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strupcase(char *str)
{
	char	*c;

	c = str;
	while (*str != '\0')
	{
		if (97 <= *str && *str <= 122)
		{
			*str -= 32;
		}
		str++;
	}
	return (c);
}

// int	main(void)
// {
// 	char str[] = "hello world!";
// 	printf("%s\n", ft_strupcase(str));
// 	return (0);
// }