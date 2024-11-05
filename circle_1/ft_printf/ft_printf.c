/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:24:41 by ituriel           #+#    #+#             */
/*   Updated: 2024/11/05 14:34:01 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_printf( const char *format, ...)
{
    int i;
    int count;
    va_list args;

    i = 0;
    count = 0;
    va_start (args, format);
    while (format[i] != '\0')
    {
        if (format[i] == '%')
        {
            i++;
            count += ft_printf_parser(&format[i], args);
        }
        else
        {
            ft_putchar_fd(format[i], 1);
            count++;
        }
        i++;
    }
    va_end(args);
    return (count);
}
int main (void)
{
    int a = 5;
    int b;
    b = ft_printf(" This is a really nice first result : %d\n", a);
    ft_printf (" and this is my count : %d ", b);
}