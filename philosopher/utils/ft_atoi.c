/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:46:54 by cauffret          #+#    #+#             */
/*   Updated: 2025/03/25 13:47:12 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r')
		return (1);
	return (0);
}

static void	ft_right_place(int *i, const char *nptr, int *f)
{
	while (ft_isspace(nptr[*i]))
		(*i)++;
	if (nptr[*i] == '+' || nptr[*i] == '-')
	{
		if (nptr[*i] == '-')
			*f = -1;
		(*i)++;
	}
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	f;
	int	current;
	int	final;

	final = 0;
	i = 0;
	f = 1;
	ft_right_place(&i, nptr, &f);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		current = nptr[i] - '0';
		final = final * 10 + current;
		i++;
	}
	return (final * f);
}
