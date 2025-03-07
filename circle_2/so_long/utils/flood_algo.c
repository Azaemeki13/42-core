/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:10:05 by cauffret          #+#    #+#             */
/*   Updated: 2025/03/07 17:09:04 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
I'm allowed to visit tiles as long as they're not blocked by a wall.
In order for function to return (1), all coin tiles must have the flag visited 
I can use basic directions to naviguate and should be able to backtrack if there is an issue
*/

#include "../so_long.h"

t_map *player_pos(g_game *game)
{
    t_map *nav = NULL;
    
    nav  = game->t_map;

    while(nav)
    {
        if(nav->type == 'P')
            return(nav); 
        nav = nav->next;
    }
    if (nav->type != 'P')
        ft_printf("couldnt find player tile \n");

    return (nav);
}

void algo_rec(t_map *pos, unsigned int *coin_count, unsigned int *exit_count)
{
    if(!pos) return ;
    if(pos->visited) return ; 
    if(pos-> type == '1') return ;
    pos->visited = 1;
    if (pos->type == 'C')
        (*coin_count)++;
    if (pos->type == 'E')
        (*exit_count)++;
    algo_rec(pos->up, coin_count, exit_count);
    algo_rec(pos->next, coin_count, exit_count);
    algo_rec(pos->down, coin_count, exit_count);
    algo_rec(pos->prev, coin_count, exit_count);
}

int flood_algo(g_game *game)
{
    unsigned int coin_count;
    unsigned int exit_count;
    
    t_map *start = NULL;
    start = player_pos(game);
    coin_count = 0;
    exit_count = 0;
    algo_rec(start, &coin_count, &exit_count);
    if (coin_count != game->map_components->collectible)
        return (0);
    if (exit_count != game->map_components->map_exit)
        return(0);
    return (1);
}
