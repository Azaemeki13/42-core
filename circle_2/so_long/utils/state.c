/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:59:58 by cauffret          #+#    #+#             */
/*   Updated: 2025/03/11 16:46:01 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	scan_coins(t_game *game)
{
	t_map	*nav;
	int		i;

	nav = NULL;
	i = 0;
	nav = game->t_map;
	while (nav)
	{
		if (nav->type == 'C')
			i++;
		nav = nav->next;
	}
	return (i);
}

void	end_refresher(t_game *game)
{
	t_map	*nav;

	nav = NULL;
	game_state_watcher(game);
	nav = game->t_map;
	if (game->state == END)
	{
		while (nav)
		{
			if (nav->end)
			{
				nav->type = 'E';
				nav->tiles_image = game->s_til->exit;
			}
			nav = nav->next;
		}
	}
}

void	game_state_watcher(t_game *game)
{
	if (!scan_coins(game))
		game->state = END;
	return ;
}
