/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 22:15:29 by ldick             #+#    #+#             */
/*   Updated: 2024/04/20 19:41:56 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	walk_the_way(char **matrix_cp, int p_col, int p_row)
{
	if (matrix_cp[p_row][p_col] == '1' || matrix_cp[p_row][p_col] == '*')
		return ;
	matrix_cp[p_row][p_col] = '*';
	walk_the_way(matrix_cp, p_col + 1, p_row);
	walk_the_way(matrix_cp, p_col - 1, p_row);
	walk_the_way(matrix_cp, p_col, p_row - 1);
	walk_the_way(matrix_cp, p_col, p_row + 1);
}