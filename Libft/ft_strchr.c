/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2024/10/23 10:11:03 by marvin            #+#    #+#             */
/*   Updated: 2024/10/23 10:11:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include "libft.h"


char	*ft_strchr(const char *s, int c)
{
	char *result;

	result = (char *)s;
	while (*result != '\0')
	{
		if (*result == (char)c)
			return ((char *)result);
		result++;
	}
	if (c == '\0')
		return ((char *)s);
}
/*
int main (void)
{
	const char test[] = "Hello";
	printf("The first occurence of this char e is here: %s",
		ft_strchr(test,'l'));
}
*/
