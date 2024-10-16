/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:03:08 by azaemeki13        #+#    #+#             */
/*   Updated: 2024/10/16 11:50:41 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memccpy(void *dest, const void *src, int c, size_t count)
{
    unsigned char *destination;
    unsigned const char *source;
    size_t i;

    i = 0;
    destination = (unsigned char *)dest;
    source = (unsigned const char *)src;
    while (i < count)
    {
        if (source[i] == (char)c)
        {
            destination[i] = source[i];
            return dest;
        }
        destination[i] = source[i];
        i++;
    }
    return dest;
}