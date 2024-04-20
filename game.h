/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:15:56 by ldick             #+#    #+#             */
/*   Updated: 2024/04/20 02:48:53 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

#define ERROR_AND_RETURN(msg, ret) do { \
    ft_printf("%s\n", msg); \
    return ret; \
} while (0)

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <errno.h>
# include "./MLX42/include/MLX42/MLX42.h"
# include "./libs/libs.h"

#endif