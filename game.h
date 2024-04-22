/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:15:56 by ldick             #+#    #+#             */
/*   Updated: 2024/04/22 05:52:16 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <errno.h>
# include "./MLX42/include/MLX42/MLX42.h"
# include "./libs/libs.h"

typedef struct s_vars
{
	int		x;
	int		y;
	int		x1;
	int		x2;
	char	buffer[1024];
}	t_vars;

char		make_copy(char *map);
int		check_c_p_e(char *map);
int		check_characters(t_vars *vars, char *map);
void	read_map_file(t_vars *vars, char *map);
int		check_rectangle(t_vars *vars, char *map);
int		map_extension(char *name);

#endif