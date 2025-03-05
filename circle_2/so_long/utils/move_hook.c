/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:28:37 by cauffret          #+#    #+#             */
/*   Updated: 2025/03/05 17:23:39 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void move_press(int keycode, g_game *param)
{
    g_game *game = NULL;

    game = param;
    if (keycode == 119 || keycode == 65362)
        move_up(&game);
    else if (keycode == 100 || keycode == 65363)
        move_right(&game);
    else if (keycode == 115 || keycode == 65364)
        move_down(&game);
    else if (keycode == 97 || keycode == 65361)
        move_left(&game);
}
