/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprintable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:40:12 by cauffret          #+#    #+#             */
/*   Updated: 2024/10/16 14:52:01 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
int ft_isprintable(int argument1)
{
    char convert;

    convert = (char)argument1;

    if ((convert < 33 || convert > 126))
        return 0;
    return 1;
}
/*
int main(void)
{
    int a = 125;
    printf("The result is: %d", ft_isprintable(a));
    return 0;
}
*/