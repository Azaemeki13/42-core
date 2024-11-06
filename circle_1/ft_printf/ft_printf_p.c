/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:30:44 by ituriel           #+#    #+#             */
/*   Updated: 2024/11/06 15:53:31 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_p(va_list args)
{
	int			d;
	uintptr_t	p;

	p = (va_arg(args, uintptr_t));
	write(1, "0x", 2);
	d = (ft_putptr_fd(p, 1) + 2);
	return (d);
}
