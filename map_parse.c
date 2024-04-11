/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:18:56 by ldick             #+#    #+#             */
/*   Updated: 2024/04/12 00:29:49 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <stdio.h>

int file_validity(int argc, char *argv[])
{
	int		i;

    i = ft_strlen(argv[1]);
	if((argv[1] [i-1] != 'r') || (argv[1] [i-2] != 'e') || (argv[1] [i-3] != 'b') || (argv[1] [i-4] != '.'))
		return (1);
	else
		return (0);
	return (0);
}

char read_file(char *map)
{
	int file;
	char buffer[1024];
	ssize_t bytes_read;

	file = open(&map[1], O_RDONLY);
	if (file == -1)
			return (1);
	bytes_read = read(file, buffer, 1024);
	if (bytes_read == -1)
	{
		close(file);
		return (1);
	}
	buffer[bytes_read] = '\0';
	close(file);
	return (*buffer);
}

int main(int argc, char *argv[])
{
	int	i;
	int x;
	int y;
	int x2;
	char *buffer;
	
	i = 0;
	y = 0;
	x = 0;
	x2 = 0;
	*buffer = read_file(argv[1]);
	while(buffer[i] && buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
			y++;
		if (buffer[i] == '1' && y == 0)
			x2++;
		if (buffer[i] == '1' || buffer[i] == '0' || buffer[i] == 'P' || buffer[i] == 'E' || buffer[i] == 'C')
			x++;
		i++;
	}
	y++;
	if (x / y != x2)
		return(1);
	write(1, "no", 2);
	return (0);
}
