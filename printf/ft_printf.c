/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 19:26:24 by mrio              #+#    #+#             */
/*   Updated: 2025/05/10 18:28:31 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"



void ft_check(va_list ap,char str)
{
    if(str=='s')
        {
            ft_putstr(va_arg(ap,char *));
            
        }
    else if(str=='d')
        ft_putnbr(va_arg(ap,int));
    // else if(str=='i')
    // else if(str=='c')
    // else if(str=='p')
    
        
    // else if(str=='%')

    
    
    
        
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
    size_t len;
	va_list	ap;


	va_start(ap, str);
    i=0;
	while (str[i] != '\0')
	{
		if (str[i] != '%')
			ft_putchr(str[i]);
		else
		{
            i++;
			ft_check(ap,str[i]);
		}
		i++;
	}
    va_end(ap);
	return len;
}

int	main(void)
{
    char *str="adsd";
	ft_printf("%s",str);
	return (0);
}