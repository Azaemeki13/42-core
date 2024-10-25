/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2024/10/24 14:55:14 by marvin            #+#    #+#             */
/*   Updated: 2024/10/25 11:27:04 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


char	*ft_strncpy(char *destination, const char *source, size_t num)
{
	size_t i;

	i = 0;
	if (destination == NULL)
		return (NULL);
	while (i != num && source[i] != 0)
	{
		destination[i] = source[i];
		i++;
	}
	while (i != num)
	{
		destination[i] = 0;
		i++;
	}
	return (destination);
}