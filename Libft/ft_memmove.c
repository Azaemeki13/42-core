/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/10/21 14:46:22 by cauffret          #+#    #+#             */
/*   Updated: 2024/10/25 11:24:49 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*convert;
	const char	*convert1;
	char		temp[n + 1];

	convert = (char *)dest;
	convert1 = (const char *)src;
	i = 0;
	while (i != n)
	{
		temp[i] = convert1[i];
		i++;
	}
	i = 0;
	while (i != n)
	{
		convert[i] = temp[i];
		i++;
	}
	convert[i + 1] = 0; // same here
	return (convert);
}

// TO CHANGE: n+1 for null terminator must be gone,
// also I need to get rid of VLA,
// asking if i can malloc ?
/*
int	main(void)
{
	char	ola[50] = "Hello, World";

	printf("Initial thing is: %s \n Copied is %s ",
		ola,
(char*) ft_memmove(ola+6,ola,13));
	return (0);
}
*/