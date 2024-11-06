/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexu_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:07:37 by ituriel           #+#    #+#             */
/*   Updated: 2024/11/06 16:33:58 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthexu_fd(int nbr, int fd)
{
	int	count;

	count = 0;
	if (nbr >= 16)
	{
		count += ft_puthexu_fd((nbr / 16), fd);
	}
	ft_putchar_fd("0123456789ABCDEF"[nbr % 16], 1);
	count++;
	return (count);
}
