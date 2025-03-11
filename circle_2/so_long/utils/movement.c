/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:57:07 by cauffret          #+#    #+#             */
/*   Updated: 2025/03/11 16:46:01 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	wall_up(t_map *nav)
{
	if (nav->type == 'P')
	{
		if (!nav->up)
			return (ft_printf("pointer not initialised \n"));
		if (nav->up->type == '1')
			return (0);
	}
	return (1);
}

void	move_up(t_game **game)
{
	t_map	*nav;

	nav = NULL;
	nav = (*game)->t_map;
	while (nav)
	{
		if (nav->type == 'P')
		{
			if (!wall_up(nav))
				return ;
			nav->type = '0';
			nav->up->type = 'P';
			precision_change(nav, nav->up, (*game));
			return ;
		}
		nav = nav->next;
	}
}

int	wall_down(t_map *nav)
{
	if (nav->type == 'P')
	{
		if (nav->down->type == '1')
			return (0);
	}
	return (1);
}

void	move_down(t_game **game)
{
	t_map	*nav;

	nav = NULL;
	nav = (*game)->t_map;
	while (nav)
	{
		if (nav->type == 'P')
		{
			if (!wall_down(nav))
				return ;
			nav->type = '0';
			nav->down->type = 'P';
			precision_change(nav, nav->down, (*game));
			return ;
		}
		nav = nav->next;
	}
}

void	precision_change(t_map *from, t_map *to, t_game *game)
{
	from->tiles_image = game->s_til->nuthin;
	if (game->side == RIGHT)
		to->tiles_image = game->s_char->right;
	else
	{
		to->tiles_image = game->s_char->left;
	}
}
