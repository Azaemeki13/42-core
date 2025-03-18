/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:46:49 by cauffret          #+#    #+#             */
/*   Updated: 2025/03/18 12:21:52 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 45 a 50 53
#include "../so_long.h"

void	error_print(void)
{
	if (ft_printf(" Error\n") < 0)
	{
	}
}

int	map_checker(char *arg, t_buffer **map_buffer, t_map_c **map)
{
	if (((map_init(arg, map_buffer)) == 0) || ((map_shape(map_buffer,
					map)) == 0) || (check_ns(*map_buffer) == 0)
		|| (check_we(*map_buffer) == 0) || (filler_checker(*map_buffer,
				map) == 0))
	{
		return (0);
	}
	return (1);
}

int	map_init(char *arg, t_buffer **map_buffer)
{
	char	*dot;
	int		fd;

	(*map_buffer) = NULL;
	dot = ft_strchr(arg, '.');
	if (!dot)
		return (0);
	if (ft_strcmp(dot, ".ber") != 0)
		return (0);
	fd = open(arg, O_RDONLY);
	if (fd < 1)
	{
		close(fd);
		return (0);
	}
	(*map_buffer) = arg_to_node((*map_buffer), fd);
	close(fd);
	return (1);
}
