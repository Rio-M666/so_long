#include <stdio.h>

void	ft_putchar(char c);

int	main(void)
{
	char	*str;
	int		i;

	str = "adio";
	i = 0;
	while (str[i] != 0)
	{
		ft_putchar(str[i]);
		i++;
	}
}
