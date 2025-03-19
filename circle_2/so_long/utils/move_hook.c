/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:28:37 by cauffret          #+#    #+#             */
/*   Updated: 2025/03/19 15:30:53 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_counter(unsigned int count, t_game *game)
{
	if (player_pos(game))
	{
		ft_printf("You did %d moves.\n", count);
	}
	return ;
}

void	move_press(int keycode, t_game *param)
{
	t_game				*game;
	static unsigned int	count = 0;

	game = param;
	move_counter(count, game);
	if (keycode == 119 || keycode == 65362)
	{
		move_up(&game);
		count++;
	}
	else if (keycode == 100 || keycode == 65363)
	{
		move_right(&game);
		count++;
	}
	else if (keycode == 115 || keycode == 65364)
	{
		move_down(&game);
		count++;
	}
	else if (keycode == 97 || keycode == 65361)
	{
		move_left(&game);
		count++;
	}
}

void	my_func(t_game *game)
{
	if (game->cleared == 0)
	{
		mlx_clear_window(game->mlx, game->mlx_win);
		game->cleared = 1;
	}
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->s_til->background,
		0, 0);
	mlx_string_put(game->mlx, game->mlx_win, (game->map_components->win_width)
		/ 2, (game->map_components->win_height) / 2, 0xFFFFFF,
		"## You won ! ##");
}

t_map	*exit_position(t_game *game)
{
	t_map	*nav;

	nav = NULL;
	nav = game->t_map;
	while (nav->type != 'E' || nav->end != 1)
	{
		nav = nav->next;
	}
	return (nav);
}
