/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:47:08 by mrio              #+#    #+#             */
/*   Updated: 2024/08/14 10:40:52 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcpy(char *dest, char *src)
{
	char	*tmp;

	tmp = dest;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (tmp);
}

// int	main(void)
// {
// 	char src[] = "Hello, World";
// 	char dest[50];
// 	ft_strcpy(dest, src);
// 	printf("%s\n", dest);
// 	return (0);
// }