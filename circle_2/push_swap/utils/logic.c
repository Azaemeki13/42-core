/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:55:08 by root              #+#    #+#             */
/*   Updated: 2025/01/07 14:26:58 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void list_sorter( t_list **head_a, t_list **head_b)
{
    t_list *current_node = NULL;
    current_node = (*head_a);
    while (current_node && current_node->next)
    {
        if (!comparer&(head_a))
            push_b(&head_a, &head_b);
            ft_printf("Successfully push from a to b\n");
            current_node = current_node->next;
    }
    
}