/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:10:21 by marvin            #+#    #+#             */
/*   Updated: 2024/10/23 14:10:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_calloc (size_t elementCount, size_t elementSize)
{
    void * final;
    size_t totalSize;

    totalSize = elementCount * elementSize;
    final = malloc(totalSize);
    if (final == NULL)
        return NULL;
    ft_memset(final, 0, totalSize);
    return final;
}
/*
int main(void)
{
    char *test = (char*)ft_calloc(5, sizeof(char));
    test ="abcd";
    printf("Test variable contains: %s", test);
    test = (char*)ft_calloc(5, sizeof(char));
    printf("Everything is set to 0 !: %s", test);

}
*/