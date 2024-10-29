/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/10/16 12:17:35 by cauffret          #+#    #+#             */
/*   Updated: 2024/10/25 11:24:28 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"

int	ft_isdigit(int argument1)
{
	char compare;

	compare = (char)argument1;
	if ((compare < '0' || compare > '9'))
		return (0);
	return (1);
}
/*
int	main(void)
{
	printf(" Result is : %d\n", ft_isdigit('b'));
}
*/