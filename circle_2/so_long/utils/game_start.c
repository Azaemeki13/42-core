/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:09:32 by cauffret          #+#    #+#             */
/*   Updated: 2025/03/03 15:47:19 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void sprite_loader(g_game **game)
{
    g_game *nav = NULL;
    int height;
    int width;

    height = 32;
    width = 32;
    nav = (*game);
    nav->s_c->s_one = mlx_xpm_file_to_image(nav->mlx, "./assets/sprites/coin_1.xpm", &width, &height);
    nav->s_c->s_two = mlx_xpm_file_to_image(nav->mlx, "./assets/sprites/coin_2.xpm", &width, &height);
    nav->s_c->s_three = mlx_xpm_file_to_image(nav->mlx, "./assets/sprites/coin_3.xpm", &width, &height);
    nav->s_c->s_four = mlx_xpm_file_to_image(nav->mlx, "./assets/sprites/coin_4.xpm", &width, &height);
    nav->s_char->up = mlx_xpm_file_to_image(nav->mlx,"./assets/sprites/char_1_up.xpm", &width, &height);
    nav->s_char->right = mlx_xpm_file_to_image(nav->mlx,"./assets/sprites/char_1_d.xpm", &width, &height);
    nav->s_char->down = mlx_xpm_file_to_image(nav->mlx,"./assets/sprites/char_2_d.xpm", &width, &height);
    nav->s_char->left = mlx_xpm_file_to_image(nav->mlx,"./assets/sprites/char_2_up.xpm", &width, &height);
    nav->s_til->wall = mlx_xpm_file_to_image(nav->mlx,"./assets/sprites/wall.xpm", &width, &height);
    nav->s_til->exit = mlx_xpm_file_to_image(nav->mlx,"./assets/sprites/waystone.xpm", &width, &height);
    nav->s_til->nuthin = mlx_xpm_file_to_image(nav->mlx,"./assets/sprites/none.xpm", &width, &height);
    nav->s_til->background = mlx_xpm_file_to_image(nav->mlx,"./assets/sprites/bkg.xpm", &width, &height);
}
void init_tiles_m(t_map **tiles)
{
    t_map *nav = NULL;

    nav = malloc(sizeof(t_map));
    nav->pix_x = 0;
    nav->pix_y = 0;
    nav->index_x = 0;
    nav->index_y = 0;
    nav->type = 'x';
    nav->tiles_image = NULL;
    nav->next = NULL;
    nav->prev = NULL;
    if (*tiles == NULL )
        *tiles = nav;
    else
    {
        add_tile(tiles, nav);
    } 
}

void add_tile (t_map **tiles, t_map *nav)
{
    t_map *current;

    current = (*tiles);
    while (current && current->next)
        current = current->next;
    current->next = nav;
    nav->prev = current;
}

void fill_grid (g_game **game)
{
    t_map *grid = NULL;
    g_game *nav = NULL;
    unsigned int x;
    unsigned int y;
    
    y = 0;
    nav = (*game);
    grid = nav->t_map;
    while (y < nav->map_components->height)
    {
        x = 0;
        while(x < nav->map_components->width)
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
    grid_type(game);
}

void map_to_grid(g_game **game)
{
    g_game *nav = NULL;
    unsigned int y;
    unsigned int x;
    
    y = 0;
    nav = (*game);
    while (y < nav->map_components->height)
    {
        x = 0;
        while (x < nav->map_components->width)
        {
            init_tiles_m(&nav->t_map);
            x ++;
        }
        y++;
    }
    fill_grid(game);
}