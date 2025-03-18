/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:09:32 by cauffret          #+#    #+#             */
/*   Updated: 2025/03/18 12:35:26 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	sprite_loader(t_game **game)
{
	load_coin(game);
	load_character(game);
	load_tiles(game);
}

void	init_tiles_m(t_map **tiles)
{
	t_map	*nav;

	nav = NULL;
	nav = malloc(sizeof(t_map));
	ft_memset(nav, 0, sizeof(t_map));
	nav->pix_x = 0;
	nav->pix_y = 0;
	nav->index_x = 0;
	nav->index_y = 0;
	nav->type = 'x';
	nav->visited = 0;
	nav->tiles_image = NULL;
	nav->next = NULL;
	nav->prev = NULL;
	nav->end = 0;
	nav->up = NULL;
	nav->down = NULL;
	if (*tiles == NULL)
		*tiles = nav;
	else
	{
		add_tile(tiles, nav);
	}
}

void	add_tile(t_map **tiles, t_map *nav)
{
	t_map	*current;

	current = (*tiles);
	while (current && current->next)
		current = current->next;
	current->next = nav;
	nav->prev = current;
}

void	fill_grid(t_game **game)
{
	t_map			*grid;
	t_game			*nav;
	unsigned int	x;
	unsigned int	y;

	nav = NULL;
	y = 0;
	nav = (*game);
	grid = nav->t_map;
	while (y < nav->map_components->height)
	{
		x = 0;
		while (x < nav->map_components->width)
		{
			grid->index_x = x;
			grid->index_y = y;
			grid->pix_x = 32 * grid->index_x;
			grid->pix_y = 32 * grid->index_y;
			grid = grid->next;
			x++;
		}
		y++;
	}
	grid_directions(game);
	grid_type(game);
}

void	map_to_grid(t_game **game)
{
	t_game			*nav;
	unsigned int	y;
	unsigned int	x;

	nav = NULL;
	y = 0;
	nav = (*game);
	while (y < nav->map_components->height)
	{
		x = 0;
		while (x < nav->map_components->width)
		{
			init_tiles_m(&nav->t_map);
			x++;
		}
		y++;
	}
	fill_grid(game);
}
