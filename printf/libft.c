/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyachirio <miyachirio@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:50:16 by mrio              #+#    #+#             */
/*   Updated: 2025/05/11 02:32:16 by miyachirio       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_putchr(char c)
{
	return (write(1, &c, 1));
}

size_t	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchr(str[i]);
		i++;
	}
	return (i);
}

size_t	ft_putnbr(int c)
{
	long num;
}