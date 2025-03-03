/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:59:22 by cauffret          #+#    #+#             */
/*   Updated: 2025/03/03 16:20:41 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

g_game *game_init(char *arg)
{
    g_game *game_struct = NULL;

    game_struct = malloc(sizeof(g_game));
    if ((map_checker(arg, &game_struct->map_buffer, &game_struct->map_components)) == 0)
    {
        free(game_struct);
        return(game_struct);
    }
    game_struct->s_c = malloc(sizeof(s_coin));
    game_struct->s_char = malloc(sizeof(s_character));
    game_struct->s_til = malloc(sizeof(s_tiles));
    game_struct->mlx = mlx_init();
    sprite_loader(&game_struct);
    map_to_grid(&game_struct);
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
    if (game == NULL)
        ft_printf("Failed to init \n");
    game->mlx_win = mlx_new_window(game->mlx, 800, 800, "so_long");
    render_grid(&game);
    mlx_loop(game->mlx);
    return (0);
}
