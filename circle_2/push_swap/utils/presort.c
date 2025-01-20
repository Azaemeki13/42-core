/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:25:40 by root              #+#    #+#             */
/*   Updated: 2025/01/20 10:26:02 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void presort (t_list **head_a, t_list **head_b, char **arguments)
{
    if (presort_checker(arguments) == 2)
    {
        sort_two(head_a);
        return;
    }
    if (presort_checker(arguments) == 3)
    {
        sort_three(head_a);
        return;
    }
    else if (presort_checker(arguments) > 3)
    {
        push_until_three(head_a, head_b);
        sort_three(head_a);
        return;
    }
}