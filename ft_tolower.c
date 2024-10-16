/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:01:33 by cauffret          #+#    #+#             */
/*   Updated: 2024/10/16 15:02:00 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_tolower(int argument1)
{
    char convert;

    convert = (char)argument1;
    if (convert > 'A' || convert < 'Z')
        return convert += 32;
    return 0;
}

int main(void)
{
    char a = 'b';
    printf("To upper result from %c is : %c ", a, ft_toupper(a));
}