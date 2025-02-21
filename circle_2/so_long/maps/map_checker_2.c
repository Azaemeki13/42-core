/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:40:44 by ituriel           #+#    #+#             */
/*   Updated: 2025/02/21 16:10:57 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void init_map_c(struct map_c *map)
{
    map->collectible = 0;
    map->map_exit = 0;
    map->player_start = 0;
    map->empty_space = 0;
}

int cool_checker(char c)
{
    int i; 

    i = 1;
    if(c == '0')
        i = 0;
    else if(c == '1')
        i = 0;
    else if(c == 'C')
        i = 0;
    else if(c == 'E')
        i = 0;
    else if(c == 'P')
        i = 0;
    return(i);
}

void map_value_filler(char *arg, char *str, struct map_c *map)
{
    int fd;
    int i;

    fd = open(arg, O_RDONLY);
    i = 0;
    init_map_c(map);
    str = get_next_line(fd);
    while (str)
    {
        free(str);
        str = get_next_line(fd);
        while (str[++i] && str[i + 1])
        {
            if ((str[i]) == 'C')
                (*map).collectible++;
            if ((str[i]) == 'E')
                (*map).map_exit++;
            if ((str[i]) == 'P')
                (*map).player_start++;
        }
    }
    close(fd);
}

int map_value_checker(char *arg, char *str, struct map_c *map)
{
    int fd;
    int i;

    fd = open(arg, O_RDONLY);
    i = 0;
    init_map_c(map);
    str = get_next_line(fd);
    while (str)
    {
        free(str);
        str = get_next_line(fd);
        while (str[++i] && str[i + 1])
        {
            if ((str[i]) == '0')
                (*map).empty_space++;
            if (cool_checker(str[i]))
            {
                close(fd);
                return(0);
            }
        }
    }
    close(fd);
    return (1);
}

int map_checker_basic(char *arg)
{
    int i;
    char *str;
    struct map_c map;

    i = 1;
    if (!map_read(arg)) 
        i = 0;
    if (!map_shape(arg)) 
        i = 0;
    if (!map_closed(arg, str)) 
        i = 0;
    map_value_filler(arg, str, &map);
    map_value_checker(arg, str, &map);
    if (map.collectible < 1)
        i = 0;
    if (map.map_exit == 0 || map.map_exit > 1)
        i = 0;
    if (map.player_start == 0 || map.player_start > 1)
        i = 0;
    if (str)
        free(str);
    return(i);
}
