/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:28:37 by cauffret          #+#    #+#             */
/*   Updated: 2025/03/09 20:56:22 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void move_press(int keycode, g_game *param)
{
    g_game *game = NULL;
    static unsigned int count = 0;

    game = param;
    ft_printf("You did %d moves.\n", count);
    if (keycode == 119 || keycode == 65362)
    {
        end_game(keycode, game);
        move_up(&game);
        count++;
    }
    else if (keycode == 100 || keycode == 65363)
    {
        end_game(keycode, game);
        move_right(&game);
        count++;
    }
    else if (keycode == 115 || keycode == 65364)
    {
        end_game(keycode, game);
        move_down(&game);
        count++;
    }
    else if (keycode == 97 || keycode == 65361)
    {
        end_game(keycode, game);
        move_left(&game);
        count++;
    }
}
void end_game(int keycode, g_game *game)
{
    t_map *player = NULL;
    t_map *exit = NULL;

    player = player_pos(game);
    exit = exit_position(game);
    end_game_exec(player, exit, keycode, game);
}
void end_game_exec(t_map *player, t_map *exit, int keycode, g_game* game)
{
    if (keycode == 119 || keycode == 65362)
    {
        if (exit == player->next)
            my_func(game);
    }
    else if (keycode == 100 || keycode == 65363)
    {
        if (exit == player->down)
            my_func(game);
    }
    else if (keycode == 115 || keycode == 65364)
    {
        if (exit == player->up)
            my_func(game);
    }
    else if (keycode == 97 || keycode == 65361)
    {
        if (exit == player->prev)
            my_func(game);
    }
}

void my_func(g_game *game)
{
    ft_printf("mlx: %p, mlx_win: %p\n", game->mlx, game->mlx_win);
    mlx_clear_window(game->mlx, game->mlx_win);
    mlx_put_image_to_window(game->mlx, game->mlx_win,game->s_til->background, 0, 0);
}


t_map *exit_position (g_game *game)
{
    t_map *nav = NULL;

    nav = game->t_map;
    while(nav->type != 'E')
    {
        nav = nav->next;
    }
    return (nav);
}
