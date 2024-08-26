/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 19:26:32 by mrio              #+#    #+#             */
/*   Updated: 2024/08/26 11:45:09 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*dest;
	char	*src_copy;

	len = 0;
	src_copy = src;
	while (*src)
	{
		len++;
		src++;
	}
	dest = (char *)malloc((len + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dest[i] = src_copy[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char str1[] = "Hello, World!";
// 	char *dup1 = ft_strdup(str1);
// 	printf("Original: %s, Duplicated: %s\n", str1, dup1);
// 	free(dup1);

// 	char str2[] = "";
// 	char *dup2 = ft_strdup(str2);
// 	printf("Original: \"%s\", Duplicated: \"%s\"\n", str2, dup2);
// 	free(dup2);

// 	char str3[] = "A";
// 	char *dup3 = ft_strdup(str3);
// 	printf("Original: %s, Duplicated: %s\n", str3, dup3);
// 	free(dup3);

// 	char str4[] = "  Leading and trailing spaces  ";
// 	char *dup4 = ft_strdup(str4);
// 	printf("Original: \"%s\", Duplicated: \"%s\"\n", str4, dup4);
// 	free(dup4);

// 	char str5[] = "!@#$%^&*()_+";
// 	char *dup5 = ft_strdup(str5);
// 	printf("Original: %s, Duplicated: %s\n", str5, dup5);
// 	free(dup5);

// 	char str6[] = "This is a very long string to test the strdup function.";
// 	char *dup6 = ft_strdup(str6);
// 	printf("Original: %s\nDuplicated: %s\n", str6, dup6);
// 	free(dup6);

// 	return (0);
// }