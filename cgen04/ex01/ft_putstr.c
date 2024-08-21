/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:19:09 by mrio              #+#    #+#             */
/*   Updated: 2024/08/21 09:59:46 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

// int	main(void)
// {
// 	ft_putstr("hogehoge\n");
// 	ft_putstr("a\n");
// 	ft_putstr("abcabcabcabcabcabcabcabcabcabcabcabcabc\n");
// }