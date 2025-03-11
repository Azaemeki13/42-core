/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:36:09 by ituriel           #+#    #+#             */
/*   Updated: 2025/03/11 16:46:01 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key_press(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	move_press(keycode, game);
	if (keycode == 65307)
	{
		clean_game(&game);
		exit(0);
	}
	return (0);
}

int	close_window(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	clean_game(&game);
	exit(0);
	return (0);
}
