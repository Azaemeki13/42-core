/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_renderer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 20:01:21 by ituriel           #+#    #+#             */
/*   Updated: 2025/02/25 17:05:10 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// import map into a grid 

char **ber_to_grid(char *name)
{
    int fd;
    int i;
    int height;
    char *length;

    length = NULL;
    i = 1;
    height = 1;
    fd = open(name, O_RDONLY);
    length = get_next_line(fd);
    i = ft_strlen(length);
    // i here represent my width
    while (get_next_line(fd))
        height++;
    i = 1920 / i;
    height = 1080 / height;

}