/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_refresher.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 18:58:29 by cauffret          #+#    #+#             */
/*   Updated: 2025/01/06 12:11:41 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void index_refresher(t_list **head)
{
    t_list *current_node;
    int index;

    index = 0;
    current_node =(*head);
    while (current_node && current_node->next)
    {
        current_node->index = index++;
        //ft_printf("Index : %d , Value : %d, Adress: %p\n", current_node->index, current_node->data, (void *) current_node);
        current_node = current_node->next;
    }
        current_node->index = index++;
    //ft_printf("Index : %d , Value : %d, Adress: %p\n", current_node->index, current_node->data, (void *) current_node);
}