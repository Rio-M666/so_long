/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 19:26:24 by mrio              #+#    #+#             */
/*   Updated: 2025/05/13 17:24:46 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(va_list ap, char str)
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
	else if (str == '\0')
		return (-1);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	size_t	len;
	va_list	ap;
	int		result;

	va_start(ap, str);
	len = 0;
	while (*str != '\0')
	{
		if (*str != '%')
			len += ft_putchr(*str);
		else
		{
			str++;
			result = ft_check(ap, *str);
			if (result == -1)
			{
				va_end(ap);
				return (-1);
			}
			len += result;
		}
		str++;
	}
	va_end(ap);
	return (len);
}

// int	main(void)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	i = printf("%", fcvt);
// 	j = ft_printf("%", fcvt);
// 	printf("iはこれ%d\n", i);
// 	printf("jはこれ%d\n", j);
// 	return (0);
// }
