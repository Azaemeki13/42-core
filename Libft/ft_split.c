/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/10/24 15:36:04 by marvin            #+#    #+#             */
/*   Updated: 2024/10/25 11:24:55 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_dup_word(const char **s, char c)
{
	const char	*start;
	size_t		len;

	while (**s == c)
		(*s)++;
	start = *s;
	while (**s && **s != c)
		(*s)++;
	len = *s - start;
	return (strndup(start, len));
}

char	**ft_split(char const *s, char c)
{
	size_t	num_words;
	size_t	i;
	char	**result;

	num_words = 0;
	i = 0;
	num_words = ft_count_words(s, c);
	result = (char **)malloc((num_words + 1) * sizeof(char *));
	while (*s)
	{
		if (*s != c)
		{
			result[i] = ft_dup_word(&s, c);
			i++;
		}
		else
			s++;
	}
	result[i] = NULL;
	return (result);
}
