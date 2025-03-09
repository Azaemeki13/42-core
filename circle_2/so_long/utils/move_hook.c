/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:28:37 by cauffret          #+#    #+#             */
/*   Updated: 2025/03/09 12:50:15 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void move_press(int keycode, g_game *param)
{
    g_game *game = NULL;
    static unsigned int count = 0;

    game = param;
    debug_exit(game->t_map);
    ft_printf("You did %d moves.\n", count);
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
