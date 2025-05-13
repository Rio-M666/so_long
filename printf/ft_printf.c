/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 19:26:24 by mrio              #+#    #+#             */
/*   Updated: 2025/05/13 15:55:45 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_check(va_list ap, char str)
{
	size_t	len;

	len = 0;
	if (str == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (str == 'd' || str == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	else if (str == 'c')
		return (ft_putchr(va_arg(ap, int)));
	else if (str == 'p')
		return (ft_pointer(va_arg(ap, void *)));
	else if (str == 'u')
		return (ft_putnbr_u(va_arg(ap, unsigned int)));
	else if (str == 'x' || str == 'X')
		return (ft_puthex(va_arg(ap, unsigned int), str));
	else if (str == '%')
		return (ft_putchr('%'));
	return (len);
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	size_t	len;
	va_list	ap;

	va_start(ap, str);
	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '%')
			len += ft_putchr(str[i]);
		else
		{
			i++;
			len += ft_check(ap, str[i]);
		}
		i++;
	}
	va_end(ap);
	return (len);
}

// int	main(void)
// {
// 	// char *str = "27389";
// 	// long i=12389789;

// 	// ft_printf("%",fcvt);
// 	int i;
// 	int j;
// 	i=0;
// 	j=0;
// 	i=printf("%",fcvt);
// 	j=ft_printf("%",fcvt);
// 	printf("%d",i);
// 	printf("%d",j);
// 	return (0);
// }