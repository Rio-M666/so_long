/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 13:38:22 by mrio              #+#    #+#             */
/*   Updated: 2024/08/18 16:32:36 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#define GRID_SIZE 4

int		*parse_input(char *input);
int		check_view(int *grid, int index, int expected, int is_row, int reverse);
int		solve(int *grid, int pos, int *views);
void	print_solution(int *grid);
int		is_valid_placement(int *grid, int pos, int value);

int	*parse_input(char *input) //コマンドライン引数で受け取った文字列の判別
{
	int *parsed_values;
	int i;
	int j;

	parsed_values = (int *)malloc(sizeof(int) * GRID_SIZE * 4); //動的にメモリーを確保！
	if (!parsed_values)
	{
		write(2, "Error\n", 6);
		return (NULL); //メモリ不足によるエラーのため
	}
	i = 0;
	j = 0;
	while (input[i] != '\0')
	{
		if (input[i] >= '1' && input[i] <= '4')
		{
			parsed_values[j++] = input[i] - '0';
		}
		else if (input[i] != ' ') //空白はおｋ
		{
			write(2, "Error\n", 6);
			free(parsed_values);
			return (NULL);
		}
		i++;
	}
	if (j != GRID_SIZE * 4) // 16個じゃないならエラーや
	{
		write(2, "Error\n", 6);
		free(parsed_values);
		return (NULL);
	}
	return (parsed_values); // mainにかえすよー
}

int	check_view(int *grid, int index, int expected, int is_row, int reverse)
{
	int	current_value;
	int	i;
	int	max_height;
	int	visible_count;

	max_height = 0;
	visible_count = 0;
	for (i = 0; i < GRID_SIZE; i++)
	{
		if (is_row)
			current_value = grid[index * GRID_SIZE + (reverse ? GRID_SIZE - 1
					- i : i)];
		else
			current_value = grid[(reverse ? GRID_SIZE - 1 - i : i) * GRID_SIZE
				+ index];
		if (current_value > max_height)
		{
			max_height = current_value;
			visible_count++;
		}
	}
	return (visible_count == expected);
}

int	is_valid_placement(int *grid, int pos, int value)
{
	int	row;
	int	col;
	int	i;

	row = pos / GRID_SIZE;
	col = pos % GRID_SIZE;
	i = 0;
	while (i < GRID_SIZE)
	{
		if (grid[row * GRID_SIZE + i] == value || grid[i * GRID_SIZE
			+ col] == value)
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_solution(int *grid, int *views)
{
	int	i;

	i = 0;
	while (i < GRID_SIZE)
	{
		if (!check_view(grid, i, views[i], 0, 0) || !check_view(grid, i,
				views[GRID_SIZE + i], 0, 1) || !check_view(grid, i, views[2
				* GRID_SIZE + i], 1, 0) || !check_view(grid, i, views[3
				* GRID_SIZE + i], 1, 1))
			return (0);
		i++;
	}
	return (1);
}

int	solve(int *grid, int pos, int *views) //深さ優先探索
{
	int i;

	if (pos == GRID_SIZE * GRID_SIZE)
		return (is_valid_solution(grid, views));
	i = 0;
	while (i <= GRID_SIZE)
	{
		if (is_valid_placement(grid, pos, i))
		{
			grid[pos] = i;
			if (solve(grid, pos + 1, views))
				return (1);
			grid[pos] = 0;
		}
		i++;
	}
	return (0);
}

void	print_solution(int *grid) //出力
{
	char c;
	int i;
	int j;

	i = 0;
	while (i < GRID_SIZE)
	{
		j = 0;
		while (j < GRID_SIZE)
		{
			c = grid[i * GRID_SIZE + j] + '0';
			write(1, &c, 1);
			if (j < GRID_SIZE - 1)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int *parsed_values;
	int grid[GRID_SIZE * GRID_SIZE] = {0};

	if (argc != 2) //エラー処理
	{
		write(2, "Error\n", 6);
		return (1);
	}
	parsed_values = parse_input(argv[1]);
	if (!parsed_values)
		return (1);
	if (solve(grid, 0, parsed_values))
		print_solution(grid);
	else
		write(2, "Error\n", 6);
	free(parsed_values);
	return (0);
}