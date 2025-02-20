/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uti_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:15:02 by root              #+#    #+#             */
/*   Updated: 2025/02/17 13:41:18 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_talk.h"

int	error_checker(int argc, char **argv)
{
	int		i;
	int		j;
	long	checker;

	checker = 0;
	i = 1;
	j = 0;
	if (argc != 3)
		return (0);
	while (argv[i][j])
	{
		if (!ft_isdigit(argv[i][j]))
			return (0);
		j++;
	}
	checker = ft_atol(argv[i]);
	if (checker <= 0 || checker > LONG_MAX)
		return (0);
	return (1);
}
