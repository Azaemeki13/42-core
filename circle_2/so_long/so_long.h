/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:47:28 by cauffret          #+#    #+#             */
/*   Updated: 2025/03/18 12:31:22 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./get_next_line/get_next_line.h"
# include "./libft/ft_printf/ft_printf.h"
# include "./libft/libft.h"
# include "./mlx_linux/mlx.h"
# include <fcntl.h>
# include <string.h>

// FOR ANIM XD LEFT
typedef enum t_direction
{
	RIGHT,
	LEFT
}						t_direction;

typedef enum t_fstate
{
	GAME,
	END
}						t_final;

typedef enum t_gravity
{
	UP,
	DOWN
}						t_gravity;

// for map checking
typedef struct buffer
{
	char				*content;
	int					index;
	struct buffer		*next;
	struct buffer		*prev;
}						t_buffer;

typedef struct map_components
{
	unsigned int		collectible;
	unsigned int		map_exit;
	unsigned int		player_start;
	unsigned int		empty_space;
	unsigned int		unallowed_char;
	unsigned int		walls;
	unsigned int		height;
	unsigned int		width;
	unsigned int		win_height;
	unsigned int		win_width;
}						t_map_c;

typedef struct character_sprite
{
	void				*up;
	void				*down;
	void				*left;
	void				*right;
}						t_character;

typedef struct coin_sprite
{
	void				*s_one;
	void				*s_two;
	void				*s_three;
	void				*s_four;
}						t_coin;

typedef struct tiles_sprite
{
	void				*wall;
	void				*exit;
	void				*nuthin;
	void				*background;
}						t_tiles;

typedef struct tiles_map
{
	int					pix_x;
	int					pix_y;
	int					index_x;
	int					index_y;
	char				type;
	void				*tiles_image;
	int					end;
	int					visited;
	struct tiles_map	*next;
	struct tiles_map	*prev;
	struct tiles_map	*up;
	struct tiles_map	*down;
}						t_map;

// my game structure
typedef struct game
{
	void				*mlx;
	void				*mlx_win;
	t_direction			side;
	t_gravity			size;
	t_final				state;
	t_map_c				*map_components;
	t_buffer			*map_buffer;
	t_coin				*s_c;
	t_character			*s_char;
	t_tiles				*s_til;
	t_map				*t_map;
	int					cleared;
	int					mlx_loop;
}						t_game;

// map checker_1
int						map_checker(char *arg, t_buffer **map_buffer,
							t_map_c **map);
// REDO from here
int						map_init(char *arg, t_buffer **map_buffer);
void					error_print(void);

// map checker_2
void					init_map_c(t_map_c **map);
int						map_shape(t_buffer **map_buffer, t_map_c **map);
int						check_ns(t_buffer *map);
int						check_we(t_buffer *map);
int						filler_checker(t_buffer *map, t_map_c **map_compo);

// map buffer
void					create_node(t_buffer **head, char *arguments);
void					add_node(t_buffer **head, t_buffer *new_node);
t_buffer				*arg_to_node(t_buffer *map_buffer, int fd);
void					index_refresher(t_buffer *map_buffer);

// my game initialiser
t_game					*game_init(char *arg);
void					sprite_loader(t_game **game);
void					load_coin(t_game **game);
void					load_character(t_game **game);
void					load_tiles(t_game **game);
void					game_init_2(t_game *game_struct);

// grid list
void					init_tiles_m(t_map **tiles);
void					add_tile(t_map **tiles, t_map *nav);
void					fill_grid(t_game **game);
void					map_to_grid(t_game **game);
void					grid_type(t_game **game);
void					grid_image(t_game **game);
void					render_grid(t_game **game);
t_map					*pos_finder(t_game **game, int x, int y);
void					grid_directions(t_game **game);
void					precision_change(t_map *from, t_map *to, t_game *game);
void					filling_map(t_buffer *nav, t_map_c *mappy);

// movements
int						wall_up(t_map *nav);
void					move_up(t_game **game);
int						wall_down(t_map *nav);
void					move_down(t_game **game);
int						wall_left(t_map *nav);
void					move_left(t_game **game);
int						wall_right(t_map *nav);
void					move_right(t_game **game);

// movement hooks
void					move_press(int keycode, t_game *param);

// animations xd
void					case_right(t_game *nav);
void					left(t_game *nav);
void					animation_coin(t_game *nav);
int						animation_loop(void *param);
int						find_char(t_game *nav, t_map *tmp);

// coin scanner + tile appearance + end game
int						scan_coins(t_game *game);
void					game_state_watcher(t_game *game);
void					end_refresher(t_game *game);
void					debug_exit(t_map *nav);
void					my_func(t_game *game);
t_map					*exit_position(t_game *game);

// flood algo
t_map					*player_pos(t_game *game);
void					algo_rec(t_map *pos, unsigned int *coin_count,
							unsigned int *exit_count);
int						flood_algo(t_game *game);

// window gestion
int						key_press(int keycode, void *param);
int						close_window(void *param);

// free memory
void					free_buffer(t_game **game);
void					free_map_compo(t_game **game);
void					free_char_sprite(t_game **game);
void					free_coin_sprite(t_game **game);
void					free_tiles_sprite(t_game **game);
void					free_grid(t_game **game);
void					clean_game(t_game **game);

#endif