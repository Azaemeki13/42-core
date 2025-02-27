/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:59:22 by cauffret          #+#    #+#             */
/*   Updated: 2025/02/27 17:31:18 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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