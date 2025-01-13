/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:41:33 by cauffret          #+#    #+#             */
/*   Updated: 2025/01/09 15:47:10 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

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

long	ft_atol(const char *nptr)
{
	int	i;
	int	f;
	long	current;
	long	final;

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
