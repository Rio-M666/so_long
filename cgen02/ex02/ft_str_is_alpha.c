/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 10:50:10 by mrio              #+#    #+#             */
/*   Updated: 2024/08/14 13:33:33 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_str_is_numeric(char *str)
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
// 	a = "jozgbnvs";
// 	ft_str_is_numeric(a);
// 	result = ft_str_is_numeric(a);
// 	printf("%d", result);
// 	return (0);
// }