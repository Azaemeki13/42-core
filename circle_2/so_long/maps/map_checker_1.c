/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:46:49 by cauffret          #+#    #+#             */
/*   Updated: 2025/02/27 17:27:15 by ituriel          ###   ########.fr       */
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
    if (!map_init(arg, map_buffer))
        return(0);
    ft_printf("content %s \n", (*map_buffer)->content);
    if (!map_shape(map_buffer, map))
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
int map_shape (b_buffer **map_buffer,  map_c **map)
{
    b_buffer *nav = NULL;
    init_map_c((map));
    (*map)->width = ft_strlen((*map_buffer)->content);
    nav = (*map_buffer);
    while (nav->next)
    {
        nav = nav->next;
    }
    (*map)->height = (nav->index) + 1;
    nav = (*map_buffer);
    while (nav)
    {
        if (ft_strlen(nav->content) != (*map)->width)
            return (0);
        nav = nav->next;
    }
    ft_printf("Width = %d, height = %d \n", (*map)->width, (*map)->height);
    return (1);
}

void init_map_c(map_c **map)
{
    (*map) = malloc(sizeof(map_c));
    (*map)->collectible = 0;
    (*map)->map_exit = 0;
    (*map)->player_start = 0;
    (*map)->empty_space = 0;
    (*map)->height = 0;
    (*map)->width = 0;
}

/*
int map_shape(char *arg, struct map_c *map)
{
    int fd;
    char *str;

    fd = open(arg, O_RDONLY);
    str = get_next_line(fd);
    map->width = ft_strlen(str);
    map->height = 1;
    while (str)
    {
        free(str);
        str = get_next_line(fd);
        if (!str)
            break;
        if (ft_strlen(str) != map->width)
        {
            close(fd);
            return (0);
        }
        map->height++;
    }
    free(str);
    close(fd);
    return (1);
}

int map_closed2(char *arg)
{
    int fd;
    char *str;
    char *last_line;
    int i;

        last_line = NULL;
    i = 0;
    fd = open(arg, O_RDONLY);
    str = get_next_line(fd);
    ft_printf("string value %s\n",str);
    while (str[i] != '\0')
    {
        ft_printf("str[i] value %c\n", str[i]);
        if (str[i] != '1' )
        {
            return(0);
        }
        i++;
    }
    while (str)
    {
        ft_printf ("str %s\n", str);
        if (last_line)
            free(last_line);
        last_line = str;
        str = get_next_line(fd);
    }
    while (*last_line++)
    {
        if (*last_line != '1')
            i = 0;
    }
    ft_printf ("Map shape ? %p\n", str);
    free(str);
    close(fd);
    return (i);
}

int map_closed(char *arg, char *str)
{
    // please free str in error function :D 
    int fd;
    int i;
    int size;
    
    i = 0;
    fd = open(arg, O_RDONLY);
    size = ft_strlen(get_next_line(fd));
    while (get_next_line(fd) != NULL)
        i++;
    close(fd);
    fd = open(arg, O_RDONLY);
    while (i-- > 1)
    {
        str = get_next_line(fd);
        if (str[0] != '1' || str[size] != '1')
            i = 0;
        free(str);

    }
    if (!map_closed2(arg))
        i = 0;
    close(fd);
    return (i);
}
    */
