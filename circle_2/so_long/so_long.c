/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:59:22 by cauffret          #+#    #+#             */
/*   Updated: 2025/02/20 17:43:28 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;
    
    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int main (void)
{
    void *mlx;
    void *mlx_win;
    t_data image;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1920, 1080, "Case test");
    image.img = mlx_new_image(mlx, 1920, 1080);
    image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian);
    my_mlx_pixel_put(&image, 10, 10, 0xFF3498DB);
    mlx_put_image_to_window(mlx, mlx_win, image.img, 0, 0);
    mlx_loop(mlx);
}