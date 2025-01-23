/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:14:41 by root              #+#    #+#             */
/*   Updated: 2025/01/23 12:14:58 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void list_cheapest (t_list *head_b)
{
    long    highest;
    t_list *node_result = NULL;
    if (!head_b)
        return ;
    while (head_b)
    {
        if (head_b->push_price < highest)
        {
            highest = head_b->push_price;
            node_result = head_b;
        }
        head_b = head_b->next;
    }
    node_result->cheapest = 1;
}

t_list *find_cheapest (t_list *head_b)
{
    while (head_b)
    {
        if (head_b->cheapest)
            return (head_b);
        head_b = head_b->next;
    }
    return NULL;
}