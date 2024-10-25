/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2024/10/22 12:15:07 by marvin            #+#    #+#             */
/*   Updated: 2024/10/22 12:15:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


// #include <stdio.h>

size_t	ft_strlen(const char *str);

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t i;
	size_t a;

	i = 0;
	a = ft_strlen(src);
	if (a == 0)
		return (a);
	if (n == 0)
		return (a);
	while (i != n - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i + 1] = '\0';
	return (a);
}
/*
int	main(void)
{
	char ola[] = "This is a test";
	char ola2[12];
	ft_strlcpy(ola2, ola, 7);
	printf("This is my first string: %s\nThis is my second string:
		%s\nThis is the return (of the function %ld",
		ola,ola2,ft_strlcpy(ola2,ola,7)));
	return (0);
	}
	*/