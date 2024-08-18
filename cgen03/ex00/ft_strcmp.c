/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:00:09 by mrio              #+#    #+#             */
/*   Updated: 2024/08/18 16:09:27 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 < *s2)
		{
			return (-1);
		}
		else if (*s1 > *s2)
		{
			return (1);
		}
		s1++;
		s2++;
	}
	if (*s1 < *s2)
	{
		return (-1);
	}
	else if (*s1 > *s2)
	{
		return (1);
	}
	return (0);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char a[] = "BBBB";
// 	char b[] = "AAAA";

// 	int result = ft_strcmp(a, b);
// 	printf("%d", result);
// 	return (0);
// }