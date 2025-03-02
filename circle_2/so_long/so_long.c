/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:59:22 by cauffret          #+#    #+#             */
/*   Updated: 2025/03/02 18:43:31 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void sprite_loader(g_game **game)
{
    g_game *nav = NULL;
    
    nav = (*game);
    nav->s_c->s_one = mlx_xpm_file_to_image(nav->mlx, "coin_1.xpm", 32 , 32);
    nav->s_c->s_two = mlx_xpm_file_to_image(nav->mlx, "coin_2.xpm", 32 , 32);
    nav->s_c->s_three = mlx_xpm_file_to_image(nav->mlx, "coin_3.xpm", 32 , 32);
    nav->s_c->s_four = mlx_xpm_file_to_image(nav->mlx, "coin_4.xpm", 32 , 32);
    nav->s_char->up = mlx_xpm_file_to_image(nav->mlx,"char_1.xpm", 32, 32);
    nav->s_char->right = mlx_xpm_file_to_image(nav->mlx,"char_2.xpm", 32, 32);
    nav->s_char->down = mlx_xpm_file_to_image(nav->mlx,"char_3.xpm", 32, 32);
    nav->s_char->left = mlx_xpm_file_to_image(nav->mlx,"char_4.xpm", 32, 32);
    nav->s_til->wall = mlx_xpm_file_to_image(nav->mlx,"wall.xpm", 32, 32);
    nav->s_til->exit = mlx_xpm_file_to_image(nav->mlx,"exit.xpm", 32, 32);
    nav->s_til->nuthin = mlx_xpm_file_to_image(nav->mlx,"none.xpm", 32, 32);
    nav->s_til->background = mlx_xpm_file_to_image(nav->mlx,"bkg.xpm", 32, 32);
}
g_game *game_init(char *arg)
{
    g_game *game_struct = NULL;
    unsigned int x;
    unsigned int y;

    game_struct = malloc(sizeof(game_struct));
    if ((map_checker(arg, game_struct->map_buffer, game_struct->map_components)) == 0)
    {
        free(game_struct);
        return(game_struct);
    }
    x = 32 * (game_struct->map_components->width);
    y = 32 * (game_struct->map_components->height);
    game_struct->mlx = mlx_init();
    game_struct->mlx_win = mlx_new_window(game_struct->mlx, x, y, "so_long");
    game_struct->mlx_loop = mlx_loop(game_struct->mlx);
    sprite_loader(&game_struct);
}

int main (int argc, char **argv)
{
    //t_background background;
    //struct map_c *map;
    b_buffer *map_buffer = NULL;
    map_c *map = NULL;
    if (argc != 2)
    {
        error_print();
        return(0);
    }
    if ((map_checker(argv[1], &map_buffer, &map)) == 0)
    {
        error_print();
        return(0);
    }
    while (map_buffer)
    {
        ft_printf ("map [content %s, index %d]\n", map_buffer->content, map_buffer->index);
        map_buffer = map_buffer->next;

    }
        //background.mlx = mlx_init();
    //background.mlx_win = mlx_new_window(background.mlx, 1920, 1080, "My game !");
    //background.background_layer1 = mlx_xpm_file_to_image(background.mlx, "./assets/background/background.xpm", &width, &height);

    //if (!background.mlx)
        //error_print();
    //mlx_put_image_to_window(background.mlx, background.mlx_win, background.background_layer1, 0, 0);
    //mlx_loop(background.mlx);
    return (0);
}