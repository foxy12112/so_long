/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 22:15:29 by ldick             #+#    #+#             */
/*   Updated: 2024/04/26 04:39:55 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	flood(char **matrix_cp, int p_col, int p_row);
char	**make_matrix(char *map);
void	printMatrix(char **matrix_cp, int rows, int cols);

char	make_copy(char *map)
{
	char	*map_copy;

	map_copy = ft_strdup(map);
	return (map);
}

char	**make_matrix(char *map)
{
	char	**mapp;

	mapp = ft_split(map, '\n');
	return (mapp);
}

void	flood(char **matrix_cp, int x, int y)
{
	if (x < 0 || y < 0)
		return ;
	if (matrix_cp[y][x] == '1' || matrix_cp[y][x] == '2')
		return ;
	matrix_cp[y][x] = '2';
	flood(matrix_cp, x + 1, y);
	flood(matrix_cp, x - 1, y);
	flood(matrix_cp, x, y - 1);
	flood(matrix_cp, x, y + 1);
}

int	ft_content_check(char **matrix, int c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			if (matrix[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	ft_path_check(char **map, int x, int y)
{
	flood(map, x, y);
	if (ft_content_check(map, 'C')
		|| ft_content_check(map, 'E') == 1)
		return (0);
	return (1);
}
