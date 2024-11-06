/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:09:54 by ituriel           #+#    #+#             */
/*   Updated: 2024/11/06 16:16:27 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_x(va_list args)
{
	int	count;

	count = ft_puthexl_fd(va_arg(args, int), 1);
	return (count);
}
