/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/10/16 14:51:41 by cauffret          #+#    #+#             */
/*   Updated: 2024/10/25 11:28:23 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_toupper(int argument1)
{
	char	convert;

	convert = (char)argument1;
	if (convert > 'a' || convert < 'z')
		return (convert -= 32);
	return (0);
}
/*
int	main(void)
{
	char	a;

	a = 'b';
	printf("To upper result from %c is : %c ", a, ft_toupper(a));
}
*/