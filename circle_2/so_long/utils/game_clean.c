/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_clean.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:40:06 by ituriel           #+#    #+#             */
/*   Updated: 2025/03/06 22:43:32 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void clean_game(g_game **game)
{
    mlx_loop_end((*game)->mlx);
    ft_printf("Loop finished \n");
    if ((*game)->mlx_win)
        mlx_destroy_window((*game)->mlx, (*game)->mlx_win);
    free_buffer(game);
    free_char_sprite(game);
    free_coin_sprite(game);
    free_tiles_sprite(game);
    free_grid(game);
    free((*game)->map_components);
    (*game)->map_components = NULL;
    free((*game)->mlx);
    free(*game);
    *game = NULL;
}
