/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_renderer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 20:01:21 by ituriel           #+#    #+#             */
/*   Updated: 2025/03/11 16:46:01 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	grid_type(t_game **game)
{
	t_game		*nav;
	t_buffer	*map;
	t_map		*grid;
	int			i;

	nav = NULL;
	map = NULL;
	grid = NULL;
	nav = (*game);
	map = nav->map_buffer;
	grid = nav->t_map;
	while (map)
	{
		i = 0;
		while (map->content[i])
		{
			grid->type = map->content[i];
			grid = grid->next;
			i++;
		}
		map = map->next;
	}
}

void	grid_image(t_game **game)
{
	t_map	*grid;

	grid = (*game)->t_map;
	while (grid)
	{
		if (grid->type == '1')
			grid->tiles_image = (*game)->s_til->wall;
		else if (grid->type == '0')
			grid->tiles_image = (*game)->s_til->nuthin;
		else if (grid->type == 'C')
			grid->tiles_image = (*game)->s_c->s_one;
		else if (grid->type == 'P')
			grid->tiles_image = (*game)->s_char->up;
		else if (grid->type == 'E' && (*game)->state == GAME)
		{
			grid->tiles_image = (*game)->s_til->nuthin;
			grid->end = 1;
		}
		else if (grid->end == 1 && (*game)->state == END)
		{
			grid->type = 'E';
			grid->tiles_image = (*game)->s_til->exit;
		}
		grid = grid->next;
	}
}

t_map	*pos_finder(t_game **game, int x, int y)
{
	t_map	*grid;

	grid = NULL;
	grid = (*game)->t_map;
	while (grid)
	{
		if (grid->index_x == x && grid->index_y == y)
			return (grid);
		grid = grid->next;
	}
	return (grid);
}

void	grid_directions(t_game **game)
{
	t_map	*grid;

	grid = NULL;
	grid = (*game)->t_map;
	while (grid)
	{
		grid->down = pos_finder(game, grid->index_x, (grid->index_y) + 1);
		grid->up = pos_finder(game, grid->index_x, (grid->index_y) - 1);
		grid = grid->next;
	}
}

void	render_grid(t_game **game)
{
	t_map	*grid;

	grid = NULL;
	grid = (*game)->t_map;
	while (grid)
	{
		mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win,
			grid->tiles_image, grid->pix_x, grid->pix_y);
		grid = grid->next;
	}
}
