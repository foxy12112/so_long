/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 22:15:29 by ldick             #+#    #+#             */
/*   Updated: 2024/04/22 05:56:46 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

char	make_copy(char *map)
{
	char	*map_copy;

	map_copy = ft_strdup(map);
	ft_printf("%s\n", map_copy);
	return (1);
}

int	turn_to_matrix(t_vars *vars, char *map)
{
	int		col;
	int		row;
	int		i;

	col = vars->y;
	row = vars->x1;
	printf("%d--%d", row, col);
}

void	flood(char **matrix_cp, int p_col, int p_row)
{
	if (matrix_cp[p_row][p_col] == '1' || matrix_cp[p_row][p_col] == '*')
		return ;
	matrix_cp[p_row][p_col] = '*';
	flood(matrix_cp, p_col + 1, p_row);
	flood(matrix_cp, p_col - 1, p_row);
	flood(matrix_cp, p_col, p_row - 1);
	flood(matrix_cp, p_col, p_row + 1);
}
int main(int argc, char *argv[])
{
	t_vars	*vars;
	int ROW = 3;
	int COL = 12;
	char array[ROW][COL];
	vars = malloc(sizeof(t_vars));
	read_map_file(vars, argv[1]);
	check_rectangle(vars, argv[1]);
	
	return 0;
}
