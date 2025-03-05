/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_clean.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:40:06 by ituriel           #+#    #+#             */
/*   Updated: 2025/03/05 12:10:21 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void clean_game(g_game **game)
{
    mlx_loop_end((*game)->mlx);
    if ((*game)->mlx_win)
        mlx_destroy_window((*game)->mlx, (*game)->mlx_win);
    free((*game)->mlx);
    free_buffer(game);
    free_char_sprite(game);
    free_coin_sprite(game);
    free_tiles_sprite(game);
    free_grid(game);
    free((*game)->map_components);
    (*game)->map_components = NULL;
    free(*game);
    *game = NULL;
}
