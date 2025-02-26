/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:47:28 by cauffret          #+#    #+#             */
/*   Updated: 2025/02/25 17:26:54 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/ft_printf/ft_printf.h"
# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include "./mlx_linux/mlx.h"
# include <string.h>
# include <fcntl.h>

// for map checking

typedef struct background
{
    void *mlx;
    void *mlx_win;
    void *background_layer1;
    ssize_t width;
    ssize_t height;
} t_background;

struct tiles
{
    char *type;
    ssize_t size_x;
    ssize_t size_y;
};

struct map_c
{
    unsigned int collectible;
    unsigned int map_exit;
    unsigned int player_start;
    unsigned int empty_space;
    unsigned int height;
    unsigned int width;
};

// my game structure
struct game
{
    void *mlx;
    char **map_grid;
    
};


// map checker_1
int map_closed2(char *arg);
int map_closed(char *arg, char *str);
int map_read(char *arg);
int map_shape(char *arg, struct map_c *map);
void error_print();

// map checker_2
void init_map_c(struct map_c *map);
int cool_checker(char c);
void map_value_filler(char *arg, char *str, struct map_c *map);
int map_value_checker(char *arg, char *str, struct map_c *map);
int map_checker_basic(char *arg);

// server side

#endif