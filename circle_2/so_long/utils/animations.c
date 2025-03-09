/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:33:39 by ituriel           #+#    #+#             */
/*   Updated: 2025/03/09 21:26:23 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int find_char(g_game *nav, t_map *tmp)
{
    if (tmp->tiles_image == nav->s_char->up)
        return(1);
    if (tmp->tiles_image == nav->s_char->right)
        return(1);
    if (tmp->tiles_image == nav->s_char->down)
        return(1);
    if (tmp->tiles_image == nav->s_char->left)
        return(1);
    return(0);
}

void case_right(g_game *nav)
{
    t_map *tmp;
    static int counter = 0;
    
    counter++;
    if (counter % 2 == 0)
    {
        tmp = nav->t_map;
        while(tmp)
        {
            if(find_char(nav, tmp) == 1)
            {
                if (nav->size == UP)
                {
                    tmp->tiles_image = nav->s_char->right;
                    nav->size = DOWN;
                }
                else 
                {
                    tmp->tiles_image = nav->s_char->up;
                    nav->size = UP;
                }
            }    
            tmp = tmp->next;
        }
    }
}

void case_left(g_game *nav)
{
    t_map *tmp;
    static int counter = 0;
    
    counter++;
    if (counter % 2 == 0)
    {
        tmp = nav->t_map;
        while(tmp)
        {
            if(find_char(nav, tmp) == 1)
            {
                if (nav->size == UP)
                {
                    tmp->tiles_image = nav->s_char->left;
                    nav->size = DOWN;
                }
                else 
                {
                    tmp->tiles_image = nav->s_char->down;
                    nav->size = UP;
                }
            }    
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
    g_game *tmp = NULL;

    nav = (g_game *)param;
    tmp = nav;
    frame++;
    if (frame >= 500)
    {
        frame = 0;
        if (nav->side == RIGHT)
            case_right(nav);
        else if (nav->side == LEFT)
            case_left(nav);
        animation_coin(nav);
    }
    end_refresher(tmp);
    render_grid(&nav);
    return(0);
}
