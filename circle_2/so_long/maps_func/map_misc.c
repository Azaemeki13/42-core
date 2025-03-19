/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_misc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:20:43 by cauffret          #+#    #+#             */
/*   Updated: 2025/03/18 12:31:12 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	filling_map(t_buffer *nav, t_map_c *mappy)
{
	int	i;

	while (nav)
	{
		i = 0;
		while (nav->content[i] != '\0')
		{
			if (nav->content[i] == 'E')
				mappy->map_exit++;
			else if (nav->content[i] == 'P')
				mappy->player_start++;
			else if (nav->content[i] == 'C')
				mappy->collectible++;
			else if (nav->content[i] == '0')
				mappy->empty_space++;
			else if (nav->content[i] == '1')
				mappy->walls++;
			else
				mappy->unallowed_char++;
			i++;
		}
		nav = nav->next;
	}
}
