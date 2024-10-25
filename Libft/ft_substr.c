/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2024/10/23 15:09:10 by marvin            #+#    #+#             */
/*   Updated: 2024/10/23 15:09:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *substring;
	size_t i;

	i = 0;
	substring = calloc(len, sizeof(const char));
	if (substring == NULL)
		return (NULL);
	while (start != len)
	{
		substring[i] = s[start];
		i++;
		start++;
	}
	return (substring);
}
/*
int main (void)
{
	const char test[] = "That's my house !";
	char *test1;
	printf("The result is : %s", ft_substr(test,7,17));

}
*/