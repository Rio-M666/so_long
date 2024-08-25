/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:59:42 by mrio              #+#    #+#             */
/*   Updated: 2024/08/22 12:36:43 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int		i;
	int		j;
	char	*name;

	if (argc < 2)
		return (0);
	i = 1;
	while (i < argc)
	{
		name = argv[i];
		j = 0;
		while (name[j] != '\0')
		{
			write(1, &name[j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
