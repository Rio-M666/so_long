/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 11:51:46 by mrio              #+#    #+#             */
/*   Updated: 2025/05/13 17:32:26 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
size_t	ft_putchr(char c);
size_t	ft_putstr(char *str);
size_t	ft_putnbr(int c);
size_t	ft_putnbr_u(unsigned int c);
size_t	ft_pointer(void *ptr);
size_t	ft_puthex(unsigned long i, const char str);
int		ft_check(va_list ap, char str);

#endif