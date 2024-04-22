/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 20:09:59 by ldick             #+#    #+#             */
/*   Updated: 2024/04/22 20:41:26 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

char *map(t_vars *vars, char *map)
{
	char	*line;
	int		fd;
	char *milk;
	int x;
	int y;
	char map[x][y];
	int i;
	
	i = 0;
	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	milk = ft_strdup(line);
	while(milk != '\0')
	{
		map[x][y] == milk[i]
	}
	// while (line != NULL)
	// {
		
	// 	free(line);
	// 	line = get_next_line(fd);
	// }
	printf("%s", line); 
	close(fd);
	return (0);
}

int main(int argc, char *argv[])
{
	t_vars *vars;

	vars = malloc(sizeof(t_vars));
	map(vars, argv[1]);
	return (0);
}