/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:59:22 by cauffret          #+#    #+#             */
/*   Updated: 2025/03/09 13:13:20 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

g_game *game_init(char *arg)
{
    g_game *game_struct = NULL;

    game_struct = malloc(sizeof(g_game));
    ft_memset(game_struct, 0, sizeof(g_game));
    game_struct->map_buffer = NULL;
    game_struct->map_components = NULL;
    if ((map_checker(arg, &game_struct->map_buffer, &game_struct->map_components)) == 0)
    {
        free_buffer(&game_struct);
        free_map_compo(&game_struct);
        free(game_struct);
        return(NULL);
    }
    game_struct->s_c = malloc(sizeof(s_coin));
    game_struct->s_char = malloc(sizeof(s_character));
    game_struct->s_til = malloc(sizeof(s_tiles));
    game_struct->mlx = mlx_init();
    game_struct->side = RIGHT;
    game_struct->size = DOWN;
    game_struct->state = GAME;
    sprite_loader(&game_struct);
    map_to_grid(&game_struct);
    if (!flood_algo(game_struct))
    { 
        ft_printf("flood not good. \n");
        clean_game(&game_struct);
        return NULL;
    }
    grid_image(&game_struct);
    return (game_struct);
}

int main (int argc, char **argv)
{
    //t_background background;
    //struct map_c *map;
    g_game *game = NULL;
    if (argc != 2)
    {
        error_print();
        return(0);
    }
    game = game_init(argv[1]);
    if (!game)
    {
        ft_printf("Failed to init \n");
        return (0);
    }
    game->mlx_win = mlx_new_window(game->mlx, game->map_components->win_width, game->map_components->win_height, "so_long");
    mlx_loop_hook(game->mlx, animation_loop, game);
    mlx_hook(game->mlx_win, 2, (1L << 0), key_press, game);
    mlx_hook(game->mlx_win, 17, (1L << 0), close_window, game);
    mlx_loop(game->mlx);
    return (0);
}
