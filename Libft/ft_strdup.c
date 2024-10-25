/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2024/10/23 14:42:47 by marvin            #+#    #+#             */
/*   Updated: 2024/10/23 14:42:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


char	*ft_strdup(const char *src)
{
	char *dest;
	int i;

	dest = malloc(sizeof(src));
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
/*
int main (void)
{
	char test1[] = " Mon p'tit test";
	char *test2;
	test2 = ft_strdup(test1);
	printf("Vous voyez le résultat de '%s'", test2);
}
*/