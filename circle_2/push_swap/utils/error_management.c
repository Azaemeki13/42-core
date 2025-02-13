/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:19:04 by root              #+#    #+#             */
/*   Updated: 2025/02/13 13:53:31 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

int	arg_checker(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '-')
			j++;
		if (!argv[i][j])
			return (0);
		if (argv[i][j] == '0' && argv[i][j + 1])
			return (0);
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	limits_checker(const char *nptr)
{
	long long	i;

	i = ft_atol(nptr);
	if (i < INT_MIN || i > INT_MAX)
	{
		return (0);
	}
	return (1);
}

int	flow_checker(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!limits_checker(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int	dup_checker(char **argv)
{
	int		i;
	int		j;
	long	num_i;
	long	num_j;

	i = 0;
	while (argv[i])
	{
		num_i = ft_atol(argv[i]);
		j = i + 1;
		while (argv[j])
		{
			num_j = ft_atol(argv[j]);
			if (num_i == num_j)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	error_checker(char **argv)
{
	if (!arg_checker(argv))
	{
		return (0);
	}
	if (!flow_checker(argv))
	{
		return (0);
	}
	if (!dup_checker(argv))
	{
		return (0);
	}
	return (1);
}
