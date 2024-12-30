/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:59:32 by cauffret          #+#    #+#             */
/*   Updated: 2024/12/30 19:28:54 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void rotate_a(t_list **head_a)
{
    t_list *temp_a = NULL;
    t_list *current_node = NULL;

    temp_a = *head_a;
    current_node =(*head_a)->next;
    *head_a =(*head_a)->next;
    ft_printf("Successfully cut first node\n");
    while(current_node)
    {
        current_node = current_node->next;
    }
    ft_printf("Browse to last node successfully.\n");
    current_node->next = temp_a;
        index_refresher(head_a);
    ft_printf("current node state : [i=%d, adress=%p, value =%d]\n", current_node->index, (void*)current_node, current_node->data);
}