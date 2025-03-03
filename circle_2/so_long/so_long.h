/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:47:28 by cauffret          #+#    #+#             */
/*   Updated: 2025/03/03 16:02:11 by cauffret         ###   ########.fr       */
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

typedef struct tiles_map
{
    int pix_x;
    int pix_y;
    int index_x;
    int index_y;
    char type;
    void *tiles_image;
    struct tiles_map *next;
    struct tiles_map *prev;
    
} t_map;
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
    t_map *t_map;
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

// my game initialiser
g_game *game_init(char *arg);
void sprite_loader(g_game **game);

// grid list 
void init_tiles_m(t_map **tiles);
void add_tile (t_map **tiles, t_map *nav);
void fill_grid (g_game **game);
void map_to_grid(g_game **game);
void grid_type(g_game **game);
void grid_image(g_game **game);
void render_grid(g_game **game);

#endif