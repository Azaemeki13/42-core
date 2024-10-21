/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 10:00:06 by azaemeki13        #+#    #+#             */
/*   Updated: 2024/10/21 15:38:32 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

#include <stdio.h>
typedef long long unsigned int size_t;
#define NULL 0

void ft_bzero(void *s, size_t n);
size_t ft_strlen(const char *str);

size_t ft_strlen(const char *str)
{
    char *nav;
    size_t i;

    i = 0;
    nav = (char *)str;
    while (nav[i] != 0)
    {
        i++;
    }
    return i;
}

void ft_bzero(void *s, size_t n)
{
    char *base;
    size_t i;

    i = 0;
    base = (char *)s;
    while (i < n)
    {
        base[i] = '\0';
        i++;
    }
}

#endif