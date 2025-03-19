/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_loader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:59:31 by cauffret          #+#    #+#             */
/*   Updated: 2025/03/19 15:37:31 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	load_coin(t_game **game)
{
	t_game	*nav;
	int		height;
	int		width;

	nav = NULL;
	height = 32;
	width = 32;
	nav = (*game);
	nav->s_c->s_one = mlx_xpm_file_to_image(nav->mlx,
			"./assets/textures/coin_1.xpm", &width, &height);
	nav->s_c->s_two = mlx_xpm_file_to_image(nav->mlx,
			"./assets/textures/coin_2.xpm", &width, &height);
	nav->s_c->s_three = mlx_xpm_file_to_image(nav->mlx,
			"./assets/textures/coin_3.xpm", &width, &height);
	nav->s_c->s_four = mlx_xpm_file_to_image(nav->mlx,
			"./assets/textures/coin_4.xpm", &width, &height);
}

void	load_character(t_game **game)
{
	t_game	*nav;
	int		height;
	int		width;

	nav = NULL;
	height = 32;
	width = 32;
	nav = (*game);
	nav->s_char->up = mlx_xpm_file_to_image(nav->mlx,
			"./assets/textures/char_1_up.xpm", &width, &height);
	nav->s_char->right = mlx_xpm_file_to_image(nav->mlx,
			"./assets/textures/char_1_d.xpm", &width, &height);
	nav->s_char->down = mlx_xpm_file_to_image(nav->mlx,
			"./assets/textures/char_2_d.xpm", &width, &height);
	nav->s_char->left = mlx_xpm_file_to_image(nav->mlx,
			"./assets/textures/char_2_up.xpm", &width, &height);
}

void	load_tiles(t_game **game)
{
	t_game	*nav;
	int		height;
	int		width;

	nav = NULL;
	height = 32;
	width = 32;
	nav = (*game);
	nav->s_til->wall = mlx_xpm_file_to_image(nav->mlx,
			"./assets/textures/wall.xpm", &width, &height);
	nav->s_til->exit = mlx_xpm_file_to_image(nav->mlx,
			"./assets/textures/waystone.xpm", &width, &height);
	nav->s_til->nuthin = mlx_xpm_file_to_image(nav->mlx,
			"./assets/textures/none.xpm", &width, &height);
	nav->s_til->background = mlx_xpm_file_to_image(nav->mlx,
			"./assets/textures/bkg.xpm", &width, &height);
}

void	free_tiles_sprite(t_game **game)
{
	t_tiles	*sprite;

	sprite = NULL;
	sprite = (*game)->s_til;
	if (sprite)
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
