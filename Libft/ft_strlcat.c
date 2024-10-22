/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:44:59 by marvin            #+#    #+#             */
/*   Updated: 2024/10/22 12:44:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlen(const char *str);

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	int i;
    size_t dst_len;
    size_t src_len;
    size_t remaining;

	i = 0;
	dst_len = ft_strlen(dst);
    src_len = ft_strlen(src);
	if (n <= (dst_len - 1))
        return ( src_len + n);
    remaining = (n - src_len - 1);

	while (i != remaining && src[i] != 0)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (src_len + n);
}
int main (void)
{
    char test1[] = "Hello World";
    char test2[10] = "abc";
    ft_strlcat(test1,test2,10);
    printf("This is test1: %s\nThis is test2 after operation %s\n This is my return from the function %ld", test1,test2,ft_strlcat(test1,test2,10));
    return 0;
}