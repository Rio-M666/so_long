/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:33:11 by mrio              #+#    #+#             */
/*   Updated: 2024/08/13 21:48:54 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	while (*str != '\0')
	{
		if (0 <= *str && *str <= 31 || *str == 127)
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
// 	a = "em";
// 	ft_str_is_numeric(a);
// 	result = ft_str_is_numeric(a);
// 	printf("%d", result);
// 	return (0);
// }