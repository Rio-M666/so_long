/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:48:21 by mrio              #+#    #+#             */
/*   Updated: 2025/05/13 16:27:51 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_puthex(unsigned long i, const char str)
{
	char	*hex;
	int		len;

	len = 0;
	if (str == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (i >= 16)
		len += ft_puthex(i / 16, str);
	len += ft_putchr(hex[i % 16]);
	return (len);
}

size_t	ft_pointer(void *ptr)
{
	int			len;
	uintptr_t	num;

	len = 0;
	if (ptr == NULL)
		return (ft_putstr("(nil)"));
	num = (uintptr_t)ptr;
	len += write(1, "0x", 2);
	len += ft_puthex(num, 'x');
	return (len);
}
