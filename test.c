/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 20:09:59 by ldick             #+#    #+#             */
/*   Updated: 2024/04/23 19:20:28 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int make_matric(char *map)
{
	char **mapp;

	mapp = ft_split(map, '\n');
	int x = 0;
	int y = 0;
while (mapp[y] != NULL) { // Check if the pointer mapp[y] is not NULL
        x = 0; // Reset x for each new line
        while (mapp[y][x] != '\0') { // Loop through each character until end of string
            printf("%c", mapp[y][x]);
            x++;
        }
        printf("\n"); // Print a newline after each line
        y++;
    }
printf("%d--%d", x, y);
	return (1);
}

int main(int argc, char *argv[])
{
	t_vars *vars;

	vars = malloc(sizeof(t_vars));
	read_map_file(vars, argv[1]);
	make_matric(vars->buffer);
	return (0);
}