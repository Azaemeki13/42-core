/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:47:28 by cauffret          #+#    #+#             */
/*   Updated: 2025/02/27 17:20:50 by ituriel          ###   ########.fr       */
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

typedef struct buffer
{
	char *			content;
	int				index;
	struct buffer	*next;
	struct buffer	*prev;
}					b_buffer;

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

typedef struct map_components
{
    unsigned int collectible;
    unsigned int map_exit;
    unsigned int player_start;
    unsigned int empty_space;
    unsigned int height;
    unsigned int width;
} map_c;

// my game structure
struct game
{
    void *mlx;
    char **map_grid;
    
};


// map checker_1
int map_checker(char *arg, b_buffer **map_buffer, map_c **map); // REDO from here
int map_init(char *arg, b_buffer **map_buffer);
int map_closed2(char *arg);
int map_closed(char *arg, char *str);
void init_map_c(map_c **map);
int map_shape (b_buffer **map_buffer, map_c **map);
void error_print();

//map buffer
void	create_node(b_buffer **head, char *arguments);
void	add_node(b_buffer **head, b_buffer *new_node);
b_buffer	*arg_to_node(b_buffer *map_buffer, int fd);
void index_refresher (b_buffer *map_buffer);

// map checker_2
int cool_checker(char c);
void map_value_filler(char *arg, char *str, map_c *map);
int map_value_checker(char *arg, char *str, map_c *map);
int map_checker_basic(char *arg);

// server side

#endif