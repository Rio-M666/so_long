/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyachirio <miyachirio@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 19:26:24 by mrio              #+#    #+#             */
/*   Updated: 2025/05/11 02:31:10 by miyachirio       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
		return ();
	else if (str == '%')
		return (ft_putchr('%'));
	return (0);
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

int	main(void)
{
	char *str = "adsd";
	ft_printf("%s", str);
	return (0);
}