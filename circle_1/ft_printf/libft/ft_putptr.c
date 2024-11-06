/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:19:01 by ituriel           #+#    #+#             */
/*   Updated: 2024/11/06 14:35:18 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_putptr_fd(uintptr_t ptr, int fd)
{
    if (ptr >= 16)
    {
        ft_putptr_fd((ptr / 16), fd);
        ft_putchar_fd("0123456789abcdef"[ptr % 16], 1);
    }
}

int main(void)
{
    uintptr_t p;
    ft_putptr_fd(p, 1);
}