/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/10/23 15:09:10 by marvin            #+#    #+#             */
/*   Updated: 2024/10/25 11:28:10 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	i;
	size_t s_len;

	i = 0;
	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		substring = malloc(sizeof(char) * 1);
		if(substring)
		{
			substring[i] = '\0';
		}
		return (substring);
	}
	if (start + len  > s_len)
		len = s_len - start;
	substring =(char *) malloc(len + 1);
	if (substring == NULL)
		return (NULL);
	while (i < len)
	{
		substring[i] = s[start + i];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}
/*
int main (void)
{
	const char	test[] = "That's my house !";
	char		*test1;

	printf("The result is : %s", ft_substr(test,7,17));
}
*/