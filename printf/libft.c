/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:50:16 by mrio              #+#    #+#             */
/*   Updated: 2025/05/10 18:28:29 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_putchr(char c)
{
	write(1, &c, 1);
	return (0);
}

size_t ft_putstr(char *str)
{
    int i;
    i=0;
    while(str[i])
    {
        ft_putchr(str[i]);
        i++;
    }
    return i;
}

size_t ft_putnbr(int c)
{
    
}