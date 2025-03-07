/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_clean.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:40:06 by ituriel           #+#    #+#             */
/*   Updated: 2025/03/07 17:12:47 by cauffret         ###   ########.fr       */
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
    free_map_compo(game);
    free_char_sprite(game);
    free_coin_sprite(game);
    free_tiles_sprite(game);
    ft_printf("sprites good \n");
    free_grid(game);
    ft_printf("grid good \n");
    free((*game)->mlx);
    free(*game);
    *game = NULL;
}
