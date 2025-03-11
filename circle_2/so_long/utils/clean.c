/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:54:23 by ituriel           #+#    #+#             */
/*   Updated: 2025/03/11 16:46:01 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_buffer(t_game **game)
{
	t_buffer	*main;
	t_buffer	*tmp;

	main = NULL;
	tmp = NULL;
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

void	free_map_compo(t_game **game)
{
	free((*game)->map_components);
}

void	free_char_sprite(t_game **game)
{
	if ((*game)->s_char)
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

void	free_coin_sprite(t_game **game)
{
	if ((*game)->s_c != NULL)
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

void	free_grid(t_game **game)
{
	t_map	*nav;
	t_map	*tmp;

	nav = (*game)->t_map;
	while (nav)
	{
		tmp = nav;
		nav = nav->next;
		free(tmp);
	}
	(*game)->t_map = NULL;
}
