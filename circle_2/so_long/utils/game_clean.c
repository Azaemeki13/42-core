/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_clean.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:40:06 by ituriel           #+#    #+#             */
/*   Updated: 2025/03/11 16:46:01 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	clean_game(t_game **game)
{
	mlx_loop_end((*game)->mlx);
	if ((*game)->mlx_win)
		mlx_destroy_window((*game)->mlx, (*game)->mlx_win);
	free_buffer(game);
	free_map_compo(game);
	free_char_sprite(game);
	free_coin_sprite(game);
	free_tiles_sprite(game);
	free_grid(game);
	mlx_destroy_display((*game)->mlx);
	free((*game)->mlx);
	free(*game);
	*game = NULL;
}
