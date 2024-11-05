/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:04:29 by ituriel           #+#    #+#             */
/*   Updated: 2024/11/05 14:33:39 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_d(const char *format, ...)
{
	int		d;
    int i;
	va_list	args;

	d = 0;
    i = 0;
	va_start(args, format);
	d = va_arg(args, int);
	ft_putnbr_fd(d, 1);
    i++;
	va_end(args);
    return (i);
}
