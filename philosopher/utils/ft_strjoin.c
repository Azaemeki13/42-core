/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:56:57 by cauffret          #+#    #+#             */
/*   Updated: 2025/04/01 11:14:06 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		i;

	i = 0;
	if (!src)
		return (NULL);
	dest = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!dest)
		return (NULL);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

size_t	ft_strlen(const char *str)
{
	char	*nav = '\0';
	size_t	i;

	i = 0;
	nav = (char *)str;
	while (nav[i] != 0)
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t			total_size;
	unsigned int	i;
	unsigned int	j;
	char			*final;

	i = 0;
	j = 0;
	total_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	final = malloc(total_size * sizeof(char));
	while (s1[i] != 0)
	{
		final[j] = s1[i];
		j++;
		i++;
	}
	i = 0;
	while (s2[i] != 0)
	{
		final[j] = s2[i];
		j++;
		i++;
	}
	final[j] = '\0';
	return (final);
}
