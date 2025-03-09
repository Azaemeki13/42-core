/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:54:23 by ituriel           #+#    #+#             */
/*   Updated: 2025/03/09 19:12:23 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void free_buffer(g_game **game)
{
    b_buffer *main = NULL;
    b_buffer *tmp = NULL;

    main = (*game)->map_buffer;
    while (main)
    {
        tmp = main;
        main = main->next;
        if (tmp->content)
            free(tmp->content);
        free(tmp);
    }
    (*game)->map_buffer = NULL;
}

void free_map_compo(g_game **game)
{
    free((*game)->map_components);
}

void free_char_sprite(g_game **game)
{

    if((*game)->s_char)
    {
        if ((*game)->s_char->down)
            mlx_destroy_image((*game)->mlx, (*game)->s_char->down);
        if ((*game)->s_char->left)
            mlx_destroy_image((*game)->mlx, (*game)->s_char->left);
        if ((*game)->s_char->up)
            mlx_destroy_image((*game)->mlx, (*game)->s_char->up);
        if ((*game)->s_char->right)
            mlx_destroy_image((*game)->mlx, (*game)->s_char->right);
    }
    free((*game)->s_char);
    (*game)->s_char = NULL;
}

void free_coin_sprite(g_game **game)
{

    if((*game)->s_c != NULL)
    {
        if ((*game)->s_c->s_one)
            mlx_destroy_image((*game)->mlx, (*game)->s_c->s_one);
        if ((*game)->s_c->s_two)
            mlx_destroy_image((*game)->mlx, (*game)->s_c->s_two);
        if ((*game)->s_c->s_three)
            mlx_destroy_image((*game)->mlx, (*game)->s_c->s_three);
        if ((*game)->s_c->s_four)
            mlx_destroy_image((*game)->mlx, (*game)->s_c->s_four);
    }
    free((*game)->s_c);
    (*game)->s_c = NULL;
}

void free_tiles_sprite(g_game **game)
{
    s_tiles *sprite = NULL;

    sprite = (*game)->s_til;
    if(sprite)
    {
        if (sprite->wall)
            mlx_destroy_image((*game)->mlx, sprite->wall);
        if (sprite->exit)
            mlx_destroy_image((*game)->mlx, sprite->exit);
        if (sprite->nuthin)
            mlx_destroy_image((*game)->mlx, sprite->nuthin);
        if (sprite->background)
            mlx_destroy_image((*game)->mlx, sprite->background);
    }
    free((*game)->s_til);
    (*game)->s_til = NULL;
}

void free_grid(g_game **game)
{
    t_map *nav;
    t_map *tmp;

    nav = (*game)->t_map;
    while(nav)
    {
        tmp = nav;
        nav = nav->next;
        free(tmp);
    }
    (*game)->t_map = NULL;
}
