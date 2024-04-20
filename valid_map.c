/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:28:13 by ldick             #+#    #+#             */
/*   Updated: 2024/04/20 19:21:23 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

typedef struct s_vars
{
	double x;
	double y;
	double x1;
	int x2;
	int x3;
	char buffer[1024];
} t_vars;

int map_extension(char *name)
{
	int i;

	i = ft_strlen(name);
	if (name[i - 1] != 'r' || name[i - 2] != 'e' || name[i - 3] != 'b' 
		|| name[i - 4] != '.')
		perror("wrong extension");
	return(0);
}

int check_rectangle(t_vars * vars, char *map)
{
	char	*line;
	int		fd;
	
		
	vars->y = 0;
	vars->x = 0;
	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	vars->x1 = ft_strlen_no_nl(line);
	while(line != NULL)
	{
		vars->x += ft_strlen_no_nl(line);
		vars->y++;
		vars->x2 = ft_strlen_no_nl(line); 
		free(line);
		line = get_next_line(fd);
		if(vars->x1 != vars->x2)
			ERROR_AND_RETURN("lines differ in lenght", 1);
	}
	close(fd);
	if (vars->x1 == vars->y)
		ERROR_AND_RETURN("not a rectangle", 1);
	printf("x=%f----y=%f", vars->x1, vars->y);
	return (0);
}
void read_map_file(t_vars *vars, char *map)
{
	int file;
	ssize_t bytes_read;

	file = open(map, O_RDONLY);
	if (file == -1)
		ft_printf("error opening file");
	bytes_read = read(file, vars->buffer, 1024);
	if (bytes_read == -1)
	{
		close(file);
		ft_printf("error reading file");
	}
	vars->buffer[bytes_read] = '\0';
}


int check_characters(t_vars *vars, char *map)
{
	int i;

	i = 0;
	read_map_file(vars, map);
	while(vars->buffer[i] != '\0')
	{
		if(vars->buffer[i] != '1' && vars->buffer[i] != '0' && vars->buffer[i] != 'P' 
			&& vars->buffer[i] != 'C' && vars->buffer[i] != 'E' && vars->buffer[i] != '\n')
			{
				ft_printf("non-allowed character present at position %d in %s", i, map);
				return (1);
			}
		i++;
	}
	return (0);
}

int check_C_P_E(char *map)
{
    int i;
    int P;
    int C;
    int E;

    P = 0;
    C = 0;
    E = 0;
    i = 0;
    while (map[i])
    {
        if (map[i] == 'P')
            P++;
        if (map[i] == 'C')
            C++;
        if (map[i] == 'E')
            E++;
        i++;
    }
    if (E != 1 || C < 1 || P != 1)
        printf("wrong variables");
    return (0);
}

int	main(int argc, char *argv[])
{
	t_vars *vars = malloc(sizeof(t_vars));
	char		*line;
	int			fd;
	
	read_map_file(vars, argv[1]);
	printf("%s\n", vars->buffer);
	printf("%d\n", map_extension(argv[1]));
	printf("%d\n", check_rectangle(vars, argv[1]));
	check_C_P_E(vars->buffer);
	check_characters(vars, argv[1]);
	return (0);
}