/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:36:09 by ituriel           #+#    #+#             */
/*   Updated: 2025/03/09 19:24:24 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int key_press(int keycode, void *param)
{
    g_game *game;
    game = (g_game *) param; 
    move_press(keycode, game);
    if (keycode == 65307)
    {
        clean_game(&game);
        exit(0);
    }
    return(0);
}

int close_window(void *param)
{
    g_game *game;

    game = (g_game *) param;
    clean_game(&game);
    exit(0);
    return (0);
}