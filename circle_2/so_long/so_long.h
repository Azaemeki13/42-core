/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:47:28 by cauffret          #+#    #+#             */
/*   Updated: 2025/03/02 18:40:50 by ituriel          ###   ########.fr       */
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


typedef struct map_components
{
    unsigned int collectible;
    unsigned int map_exit;
    unsigned int player_start;
    unsigned int empty_space;
    unsigned int height;
    unsigned int width;
} map_c;

typedef struct character_sprite
{
    void *up;
    void *down;
    void *left;
    void *right;
} s_character;

typedef struct coin_sprite
{
    void *s_one;
    void *s_two;
    void *s_three;
    void *s_four;
} s_coin;

typedef struct tiles_sprite
{
    void *wall;
    void *exit;
    void *nuthin;
    void *background;
} s_tiles;

// my game structure
typedef struct game
{
    void *mlx;
    void *mlx_win;
    map_c *map_components;
    b_buffer *map_buffer;
    s_coin *s_c;
    s_character *s_char;
    s_tiles *s_til;
    int mlx_loop;
} g_game;


// map checker_1
int map_checker(char *arg, b_buffer **map_buffer, map_c **map); // REDO from here
int map_init(char *arg, b_buffer **map_buffer);
void error_print();

// map checker_2
void init_map_c(map_c **map);
int map_shape (b_buffer **map_buffer, map_c **map);
int check_ns(b_buffer *map);
int check_we(b_buffer *map);
int filler_checker(b_buffer *map, map_c **map_compo);

//map buffer
void	create_node(b_buffer **head, char *arguments);
void	add_node(b_buffer **head, b_buffer *new_node);
b_buffer	*arg_to_node(b_buffer *map_buffer, int fd);
void index_refresher (b_buffer *map_buffer);

// server side

#endif