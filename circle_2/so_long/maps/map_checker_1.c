/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:46:49 by cauffret          #+#    #+#             */
/*   Updated: 2025/03/03 15:34:59 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void error_print()
{
    if(write(2, "Error\n", 6) < 0)
    {
    }
}

int map_checker(char *arg, b_buffer **map_buffer, map_c **map)
{
    if ((map_init(arg, map_buffer)) == 0)
        return(0);
    if (!map_shape(map_buffer, map))
        return(0);
    if (!check_ns(*map_buffer))
        return(0);
    if(!check_we(*map_buffer))
        return(0);
    if(!filler_checker(*map_buffer, map))
        return(0);
    return (1);
}

int map_init(char *arg, b_buffer **map_buffer)
{
    char *dot;
    int fd;
    dot = ft_strchr(arg, '.');
    if (!dot)
        return (0);
    if (ft_strcmp(dot, ".ber") != 0)
        return (0);
    fd = open(arg, O_RDONLY);
    if (fd < 1)
    {
        close (fd);
        return(0);
    }
    (*map_buffer) = arg_to_node((*map_buffer), fd);
    close (fd);
    return (1);
}
