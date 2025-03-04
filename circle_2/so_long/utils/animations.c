/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:33:39 by ituriel           #+#    #+#             */
/*   Updated: 2025/03/04 15:35:13 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void animation_char(g_game *nav)
{
    static int counter = 0;
    t_map *tmp;

        counter++;
    if (counter % 2 == 0)
    {
        tmp = nav->t_map;
        while(tmp)
        {
            if (tmp->tiles_image == nav->s_char->up)
                tmp->tiles_image = nav->s_char->right;
            else if (tmp->tiles_image == nav->s_char->right)
                tmp->tiles_image = nav->s_char->up;
            tmp = tmp->next;
        }
    }
}

void animation_coin(g_game *nav)
{
    t_map *tmp;

    tmp = nav->t_map;
    while(tmp)
        {
            if (tmp->tiles_image == nav->s_c->s_one)
                tmp->tiles_image = nav->s_c->s_two;
            else if (tmp->tiles_image == nav->s_c->s_two)
                tmp->tiles_image = nav->s_c->s_three;
            else if (tmp->tiles_image == nav->s_c->s_three)
                tmp->tiles_image = nav->s_c->s_four;
            else if (tmp->tiles_image == nav->s_c->s_four)
                tmp->tiles_image = nav->s_c->s_one;
            tmp = tmp->next;
        }
}

int animation_loop(void *param)
{
    static int frame = 0;
    g_game *nav = NULL;

    nav = (g_game *)param;
    frame++;
    if (frame >= 450)
    {
        frame = 0;
        animation_char(nav);
        animation_coin(nav);
    }
    render_grid(&nav);
    return(0);
}
