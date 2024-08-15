/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 23:07:21 by mrio              #+#    #+#             */
/*   Updated: 2024/08/15 20:00:13 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	is_alpha;
	int	is_lalpha;
	int	is_ualpha;

	i = 0;
	while (str[i] != '\0')
	{
		is_alpha = 48 <= str[i - 1] && str[i - 1] <= 57;
		is_lalpha = 65 <= str[i - 1] && str[i - 1] <= 90;
		is_ualpha = 97 <= str[i - 1] && str[i - 1] <= 122;
		if ((!is_alpha && !is_lalpha && !is_ualpha) || i == 0)
		{
			if (97 <= str[i] && str[i] <= 122)
			{
				str[i] -= 32;
			}
		}
		else
		{
			if (65 <= str[i] && str[i] <= 90)
			{
				str[i] += 32;
			}
		}
		i++;
	}
	return (str);
}

// int	main(void)
// {
// 	char str[] = "fEGlo, nobGIug ,awf83h,3 532";
// 	printf("%s\n", ft_strcapitalize(str));
// 	return (0);
// }