/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:13:46 by cauffret          #+#    #+#             */
/*   Updated: 2025/03/11 16:46:01 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	wall_left(t_map *nav)
{
	if (nav->type == 'P')
	{
		if (nav->prev->type == '1')
			return (0);
	}
	return (1);
}

void	move_left(t_game **game)
{
	t_map	*nav;

	nav = NULL;
	(*game)->side = LEFT;
	nav = (*game)->t_map;
	while (nav)
	{
		if (nav->type == 'P')
		{
			if (!wall_left(nav))
				return ;
			nav->type = '0';
			nav->prev->type = 'P';
			precision_change(nav, nav->prev, (*game));
			return ;
		}
		nav = nav->next;
	}
}

int	wall_right(t_map *nav)
{
	if (nav->type == 'P')
	{
		if (nav->next->type == '1')
			return (0);
	}
	return (1);
}

void	move_right(t_game **game)
{
	t_map	*nav;

	nav = NULL;
	(*game)->side = RIGHT;
	nav = (*game)->t_map;
	while (nav)
	{
		if (nav->type == 'P')
		{
			if (!wall_right(nav))
				return ;
			nav->type = '0';
			nav->next->type = 'P';
			precision_change(nav, nav->next, (*game));
			return ;
		}
		nav = nav->next;
	}
}
