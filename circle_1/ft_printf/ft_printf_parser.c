/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:39:42 by ituriel           #+#    #+#             */
/*   Updated: 2024/11/06 15:14:00 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_parser( char format, va_list args)
{
	int	d;

	d = 0;
	if (format == 'd' || format == 'i')
		d += ft_printf_d(args);
    if (format == 'c')
        d += ft_printf_char(args);
    if (format == 'p')
        d+= ft_printf_p(args);
    if (format == 's')
    {
        d += ft_printf_s(args);
    }
	return (d);
}
