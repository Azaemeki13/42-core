/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:29:16 by cauffret          #+#    #+#             */
/*   Updated: 2024/10/25 11:24:38 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

int ft_findy(const void *s2, int c, size_t n)
{
    unsigned const char *s_two;
    unsigned char baite;
    size_t i;

    i = 0;
    baite = (unsigned char)c;
    s_two = (unsigned const char *)s2;
    while (n != 0)
    {
        if (s_two[i] == c)
            return 1;
        i++;
        n--;
    }
    return 0;
}

void *ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
    unsigned char baite;
    unsigned char *s_one;
    unsigned const char *s_two;

    int i;

    i = 0;
    s_one = (unsigned char *)s1;
    s_two = (unsigned const char *)s2;
    baite = (unsigned char)c;
    if (!findy(s2, c, n))
        return s_one = NULL;

    while (s_two[i] != baite && n > 0)
    {
        *s_one = s_two[i];
        s_one++;
        i++;
        n--;
    }
    *s_one = 0; // idk if i need to remove that one or not.
    return s_one + 1;
}
/*
int main (void)
{
    unsigned char sone[20];
    unsigned const char stwo[] = "Hellow";
    printf("Original : %s\n Copied: %s\n", stwo, (char*) ft_memccpy(sone, stwo,'',4));
    printf("The result is: %s ", sone);
    return 0;
}
*/