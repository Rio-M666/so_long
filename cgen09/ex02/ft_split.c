/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:11:29 by mrio              #+#    #+#             */
/*   Updated: 2024/08/29 10:25:31 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_chek(char str, char *c)
{
	while (*c)
	{
		if (str == *c)
			return (1);
		c++;
	}
	return (0);
}

int	word_count(char *str, char *charset)
{
	int	count;
	int	word;

	count = 0;
	word = 0;
	while (*str)
	{
		if (!(ft_chek(*str, charset)) && !word)
		{
			word = 1;
			count++;
		}
		else if (ft_chek(*str, charset))
			word = 0;
		str++;
	}
	return (count);
}

char	*copy_word(char *str, int start, int end)
{
	char	*word;
	int		i;

	word = (char *)malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
	{
		word[i++] = str[start++];
	}
	word[i] = '\0';
	return (word);
}

void	ft_sprit2(char *str, char *charset, char **result)
{
	int	start;
	int	i;
	int	j;

	i = 0;
	j = 0;
	start = -1;
	while (str[i])
	{
		if (!ft_chek(str[i], charset))
		{
			if (start == -1)
				start = i;
			if (str[i + 1] == '\0' || ft_chek(str[i + 1], charset))
			{
				result[j++] = copy_word(str, start, i + 1);
				start = -1;
			}
		}
		i++;
	}
	result[j] = NULL;
}

char	**ft_split(char *str, char *charset)
{
	int		total_words;
	char	**result;

	total_words = word_count(str, charset);
	result = (char **)malloc((total_words + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	ft_sprit2(str, charset, result);
	return (result);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char **result = ft_split("wjd;odwo;/?dwa//do;mcdk", ";/?");
// 	int i = 0;
// 	while (result[i])
// 	{
// 		printf("%s\n", result[i]);
// 		free(result[i]);
// 		i++;
// 	}
// 	free(result);
// 	return (0);
// }