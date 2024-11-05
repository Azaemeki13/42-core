/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:39:42 by ituriel           #+#    #+#             */
/*   Updated: 2024/11/05 14:34:00 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_printf_parser(const char* format, ...)
{
    va_list args;
    int i;
    int d;

    d = 0;
    va_start (args, format);
    while (format[i] != '\0')
    {
        if (format[i] == 'd')
            d += ft_printf_d(args);
        i++;
    }
    va_end(args);
    return (d);
}