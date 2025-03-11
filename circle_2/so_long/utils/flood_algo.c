/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:10:05 by cauffret          #+#    #+#             */
/*   Updated: 2025/03/11 16:46:01 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_map	*player_pos(t_game *game)
{
	t_map	*nav;

	nav = NULL;
	nav = game->t_map;
	while (nav)
	{
		if (nav->type == 'P')
			return (nav);
		nav = nav->next;
	}
	return (NULL);
}

void	algo_rec(t_map *pos, unsigned int *coin_count, unsigned int *exit_count)
{
	if (!pos)
		return ;
	if (pos->visited)
		return ;
	if (pos->type == '1')
		return ;
	pos->visited = 1;
	if (pos->type == 'C')
		(*coin_count)++;
	if (pos->type == 'E')
		(*exit_count)++;
	algo_rec(pos->up, coin_count, exit_count);
	algo_rec(pos->next, coin_count, exit_count);
	algo_rec(pos->down, coin_count, exit_count);
	algo_rec(pos->prev, coin_count, exit_count);
}

int	flood_algo(t_game *game)
{
	unsigned int	coin_count;
	unsigned int	exit_count;
	t_map			*start;

	start = NULL;
	start = player_pos(game);
	coin_count = 0;
	exit_count = 0;
	algo_rec(start, &coin_count, &exit_count);
	if (coin_count != game->map_components->collectible)
		return (0);
	if (exit_count != game->map_components->map_exit)
		return (0);
	return (1);
}
