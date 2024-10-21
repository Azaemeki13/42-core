/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:46:22 by cauffret          #+#    #+#             */
/*   Updated: 2024/10/21 15:40:44 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void ft_bzero(void *s, size_t n);
size_t ft_strlen(const char *str);

void *ft_memmove(void *dest, const void *src, size_t n)
{
    size_t i;
    char *convert;
    const char *convert1;
    char *temp;

    convert = (char *)dest;
    convert1 = (const char *)src;
    i = ft_strlen(convert1);
    temp = (char *)src;
    ft_bzero(temp, i);
    i = 0;
    while (i != n)
    {
        temp[i] = convert1[i];
        i++;
    }
    i = 0;
    while (i != n)
    {
        convert[i] = temp[i];
    }
    convert[i + 1] = 0; // same here
    return (dest);
}
int main(void)
{
    char ola[50] = "Hello, World";
    printf("Initial thing is: %s\nCopied is: %s", ola, (char *)ft_memmove(ola + 5, ola, 13));
    return 0;
}