/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:40:44 by ituriel           #+#    #+#             */
/*   Updated: 2025/03/04 14:30:41 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void init_map_c(map_c **map)
{
    (*map) = malloc(sizeof(map_c));
    (*map)->collectible = 0;
    (*map)->map_exit = 0;
    (*map)->player_start = 0;
    (*map)->empty_space = 0;
    (*map)->height = 0;
    (*map)->width = 0;
    (*map)->win_width = 0;
    (*map)->win_height = 0;

}
int map_shape (b_buffer **map_buffer,  map_c **map)
{
    b_buffer *nav = NULL;
    
    nav = (*map_buffer);
    init_map_c((map));
    (*map)->width = ft_strlen((nav)->content);
    (*map)->win_width = (*map)->width * 32;

    while (nav->next)
    {
        nav = nav->next;
    }
    (*map)->height = (nav->index) + 1;
    (*map)->win_height = (*map)->height * 32;
    nav = (*map_buffer);
    while (nav)
    {
        if (ft_strlen(nav->content) != (*map)->width)
            return (0);
        nav = nav->next;
    }
    ft_printf("Width = %d, height = %d \n", (*map)->win_width, (*map)->win_height);
    return (1);
}

int check_ns(b_buffer *map)
{
    char *test = map->content;
    int length;
    int i;

    i = 0;
    length = ft_strlen(test);
    while(i < length)
    {
        if (test[i] != '1')
            return (0);
        i++;
    }

    while (map->next)
        map = map->next;
    test = map->content;
    i = 1; 
    while(i < length)
    {
        if (test[i] != '1')
            return (0);
        i++;
    }
    return (1);
}

int check_we(b_buffer *map)
{
    b_buffer *test;
    int f;
    int l;

    test = map;
    f = 0;
    l = ft_strlen(test->content) - 1;
    while(test)
    {
        if (test->content[f] != '1' || test->content[l] != '1')
            return(0);
        test = test->next;
    }
    return (1);
}

int filler_checker(b_buffer *map, map_c **map_compo)
{
    // E P C 0
    map_c *mappy = NULL;
    b_buffer *nav = NULL;
    int i;
    
    nav = map;
    mappy = (*map_compo);
    while(nav)
    {
        i = 0;
        while(nav->content[i] != '\0')
        {
            if (nav->content[i] == 'E')
                mappy->map_exit++;
            else if (nav->content[i] == 'P')
                mappy->player_start++;
            else if (nav->content[i] == 'C')
                mappy->collectible++;
            else if (nav->content[i] == '0')
                mappy->empty_space++;
            i++;
        }
        nav = nav->next;
    }
    if (mappy->map_exit != 1 || mappy->player_start != 1 || mappy->collectible < 1)
        return(0);
    return(1);
}
