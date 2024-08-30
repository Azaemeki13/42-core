/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:30:50 by marvin            #+#    #+#             */
/*   Updated: 2024/08/30 16:30:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> 
#include <stddef.h> 
#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	if (str == NULL)
	{
		return (0);
	}
	while (*str != '\0')
	{
		str++;
		count++;
	}
	return (count);
}
/*
void *ft_memset ( void *ptr, int value, size_t num)
{
    char *base;
    size_t i;
    size_t j;

    i = 0;
    j = ft_strlen((char*)ptr);
    base = (char*) malloc (sizeof(char) * (j + num));
    while (i < num)
    {
        base[i] = (char) value;
        i++;
    }
    while ((char*)ptr)
    {
        base[i] = (char*)ptr;
        i++;
    }
    
return ptr;
}
*/
int main ()
{
  char str[] = "almost every programmer should know memset!";
  ft_memset (str,'-',6);
  puts (str);
  return 0;
}