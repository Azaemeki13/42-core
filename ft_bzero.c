/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaemeki13 <azaemeki13@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 10:27:12 by azaemeki13        #+#    #+#             */
/*   Updated: 2024/09/02 10:59:12 by azaemeki13       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

void ft_bzero (void *s, size_t n)
{
    char *base;
    size_t i;

    i = 0; 
    base = (char*) s;
    while (i < n)
    {
        base[i] = '\0';
        i++;
    }
}
/* 
int main() {
    char str[] = "almost every programmer should know memset!";
    
    ft_bzero(str, 6);

    // Display each character explicitly
    printf("After ft_bzero:\n");
    for (size_t i = 0; i < sizeof(str); i++) {
        if (str[i] == '\0') {
            printf("\\0");  // Print \0 for null characters
        } else {
            printf("%c", str[i]);
        }
    }
    printf("\n");

    return 0;
}
*/