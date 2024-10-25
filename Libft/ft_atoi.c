/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2024/10/23 12:03:23 by marvin            #+#    #+#             */
/*   Updated: 2024/10/25 11:24:04 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>


int	ft_atoi(const char *nptr)
{
	int i;
	int f;
	int current;
	int final;

	final = 0;
	i = 0;
	f = 1;
	while (nptr[i] != 0)
	{
		while (ft_isspace(nptr[i]))
			i++;
		while (nptr[i] == '+' || nptr[i] == '-')
		{
			if (nptr[i] == '-')
				f = -1;
			i++;
		}
		while (nptr[i] >= '0' && nptr[i] <= '9')
		{
			current = nptr[i] - '0';
			final = final * 10 + current;
			i++;
		}
		while (nptr[i] < '0' || nptr[i] > '9')
			return (final * f);
	}
	return (final * f);
}

// to encapsulate
/*
int main (void)
{
	char	test[] = "qsqsqsqs-++-+-++12345qsqs";
	int		i;

	i = ft_atoi(test);
	printf("The result is: %d ", i);
}
*/