/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2024/10/25 11:34:02 by cauffret          #+#    #+#             */
/*   Updated: 2024/10/25 14:46:01 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


int	ft_count_digits(int n);

int	ultimate_converter(int n, long int *num, char *dest)
{
	if (n == 0)
	{
		dest[0] = '0';
		dest[1] = '\0';
		return (1);
	}
	if (n < 0)
	{
		dest[0] = '-';
		*num = -(*num);
		return (0);
	}
	return (0);
}

void	alloc_cases(int n, char **convert, int *length)
{
	if (n < 0)
	{
		*length = ft_count_digits(n) + 1;
		*convert = (char *)malloc((*length + 1) * sizeof(char));
	}
	else if (n > 0)
	{
		*length = ft_count_digits(n);
		*convert = (char *)malloc((*length + 1) * sizeof(char));
	}
	else
	{
		*length = 1;
		*convert = (char *)malloc((*length + 1) * sizeof(char));
	}
}

char	*ft_itoa(int n)
{
	char *convert;
	int length;
	long num;
	int i;

	num = n;
	alloc_cases(n, &convert, &length);
	i = length - 1;
	if (!convert)
		return (convert = NULL);
	if (ultimate_converter(n, &num, convert))
		return (convert);
	convert[length] = '\0';
	while (i >= 0 && num > 0)
	{
		if (convert[i] == '-')
			break ;
		convert[i] = (num % 10) + '0';
		num /= 10;
		i--;
	}
	return (convert);
}

int	main(void)
{
	int testi = -85642;
	char *dream;
	dream = ft_itoa(testi);
	printf("Will it work ? :) %s", dream);
}