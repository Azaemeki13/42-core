/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:40:44 by ituriel           #+#    #+#             */
/*   Updated: 2025/03/18 12:39:09 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_map_c(t_map_c **map)
{
	(*map) = malloc(sizeof(t_map_c));
	(*map)->collectible = 0;
	(*map)->map_exit = 0;
	(*map)->player_start = 0;
	(*map)->empty_space = 0;
	(*map)->unallowed_char = 0;
	(*map)->walls = 0;
	(*map)->height = 0;
	(*map)->width = 0;
	(*map)->win_width = 0;
	(*map)->win_height = 0;
}

int	map_shape(t_buffer **map_buffer, t_map_c **map)
{
	t_buffer	*nav;

	nav = NULL;
	(*map) = NULL;
	nav = (*map_buffer);
	init_map_c((map));
	(*map)->width = ft_strlen((nav)->content);
	(*map)->win_width = (*map)->width * 32;
	while (nav->next)
	{
		nav = nav->next;
	}
	(*map)->height = (nav->index) + 1;
	(*map)->win_height = (*map)->height * 32;
	nav = (*map_buffer);
	while (nav)
	{
		if (ft_strlen(nav->content) != (*map)->width)
			return (0);
		nav = nav->next;
	}
	return (1);
}

int	check_ns(t_buffer *map)
{
	char	*test;
	int		length;
	int		i;

	test = map->content;
	i = 0;
	length = ft_strlen(test);
	while (i < length)
	{
		if (test[i] != '1')
			return (0);
		i++;
	}
	while (map->next)
		map = map->next;
	test = map->content;
	i = 1;
	while (i < length)
	{
		if (test[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_we(t_buffer *map)
{
	t_buffer	*test;
	int			f;
	int			l;

	test = map;
	f = 0;
	l = ft_strlen(test->content) - 1;
	while (test)
	{
		if (test->content[f] != '1' || test->content[l] != '1')
			return (0);
		test = test->next;
	}
	return (1);
}

int	filler_checker(t_buffer *map, t_map_c **map_compo)
{
	t_map_c		*mappy;
	t_buffer	*nav;

	mappy = NULL;
	nav = NULL;
	nav = map;
	mappy = (*map_compo);
	filling_map(nav, mappy);
	if (mappy->map_exit != 1 || mappy->player_start != 1
		|| mappy->collectible < 1 || mappy->unallowed_char != 0)
		return (0);
	return (1);
}
