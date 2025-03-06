/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:59:58 by cauffret          #+#    #+#             */
/*   Updated: 2025/03/06 18:34:57 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int scan_coins(g_game *game)
{
    t_map *nav = NULL;
    int i;

    i = 0;
    nav = game->t_map;
    while(nav)
    {
        if (nav->type == 'C')
            i++;
        nav = nav->next;
    }
    return (i);
}

void debug_exit(t_map *nav)
{
    t_map *tmp = nav;
    while(tmp)
    {
        if (tmp->type == 'E')
            printf("found E \n");
        tmp = tmp->next;
    }
}

void end_refresher(g_game *game)
{
    t_map *nav = NULL;

    nav = game->t_map;
    if (game->state == END)
    {
        while(nav)
        {
            if (nav->end)
                nav->type = 'E';
            nav = nav->next;
        }
    }
}

void game_state_watcher(g_game *game)
{
    if(!scan_coins(game))
        game->state = END;
    return ;
}