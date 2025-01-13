/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:31:49 by cauffret          #+#    #+#             */
/*   Updated: 2025/01/09 15:29:47 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_push_swap.h"

int main (int argc, char **argv)
{
    char **arguments;
    int n;

    n = 0;

    arguments = NULL;
    if (argc == 1 || (argc == 2 && argv[1][0] == 0))
        return (1);
    if (argc == 2)
    {
        arguments = ft_split(argv[1], ' ');
    }
    
    return 0;
}