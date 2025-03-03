/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_renderer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 20:01:21 by ituriel           #+#    #+#             */
/*   Updated: 2025/03/04 15:33:55 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void grid_type(g_game **game)
{
    g_game *nav;
    b_buffer *map;
    t_map *grid;
    int i;

    nav = NULL;
    map = NULL;
    grid = NULL;
    nav = (*game);
    map = nav->map_buffer;
    grid = nav->t_map;
    while(map)
    {
        i = 0;
        while(map->content[i])
        {
            grid->type = map->content[i];
            grid = grid->next;
            i++;
        }
        map = map->next;
    }
}

void grid_image(g_game **game)
{
    t_map *grid = NULL;

    grid = (*game)->t_map;
    while (grid)
    {
        if (grid->type == '1')
            grid->tiles_image = (*game)->s_til->wall;
        else if(grid->type == '0')
            grid->tiles_image = (*game)->s_til->nuthin;
        else if(grid->type == 'C')
            grid->tiles_image = (*game)->s_c->s_one;
        else if(grid->type == 'P')
            grid->tiles_image = (*game)->s_char->up;
        else if(grid->type == 'E')
            grid->tiles_image = (*game)->s_til->exit;
        grid = grid->next;
    }
}

void render_grid(g_game **game)
{
    t_map *grid = NULL;

    grid = (*game)->t_map;
    while(grid)
    {
        mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win, grid->tiles_image, 
        grid->pix_x, grid->pix_y);
        grid = grid->next;
    }
}
