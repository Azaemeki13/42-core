/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:46:49 by cauffret          #+#    #+#             */
/*   Updated: 2025/02/21 15:59:42 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void error_print()
{
    write(2, "Error\n", 6);
}

int map_read(char *arg)
{
    char *dot;
    int bytes_read;
// looking for .ber file
    dot = ft_strchr(arg, '.');
    if (!dot)
        return (0);
    if (ft_strcmp(dot, ".ber") != 0)
        return (0);
// checking if file works
    bytes_read = open(arg, O_RDONLY);
    if (bytes_read < 1)
    {
        close(bytes_read);
        return(0);
    }
    return (1);
}

int map_shape(char *arg)
{
    int fd;
    int small_l;
    char *str;

    fd = open(arg, O_RDONLY);
    str = get_next_line(fd);
    small_l = ft_strlen(str);
    while (str)
    {
        free(str);
        str = get_next_line(fd);
        if (ft_strlen(str) != small_l)
        {
            close(fd);
            return (0);
        }
    }
    free(str);
    close(fd);
    return (1);
}

int map_closed2(char *arg)
{
    int fd;
    char *str;
    int i;

    i = 1;
    fd = open(arg, O_RDONLY);
    str = get_next_line(fd);
    while (*str++)
    {
        if (*str != '1')
            i = 0;
    }
    while (str)
    {
        free(str);
        str = get_next_line(fd);
    }
    while (*str++)
    {
        if (*str != '1')
            i = 0;
    }
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
    fd = open(arg, O_RDONLY);
    while (i-- > 1)
    {
        free(str);
        str = get_next_line(fd);
        if (str[0] != '1' || str[size] != '1')
            i = 0;
    }
    if (!map_closed2(arg))
        i = 0;
    close(fd);
    return (i);
}
