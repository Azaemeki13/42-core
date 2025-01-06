/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:59:32 by cauffret          #+#    #+#             */
/*   Updated: 2025/01/06 12:12:41 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void rotate_a(t_list **head_a)
{
    t_list *temp_a = NULL;
    t_list *current_node = NULL;

    if (!head_a ||!(*head_a) || !(*head_a)->next)
    {
        ft_printf("error not enough space for rotation");
        return;
    }
    temp_a = *head_a;
    current_node =(*head_a)->next;
    *head_a =(*head_a)->next;
    ft_printf("Successfully cut first node\n");
    while(current_node && current_node->next)
    {
        current_node = current_node->next;
    }
    ft_printf("Browse to last node successfully.\n");
    current_node->next = temp_a;
    temp_a->next = NULL;
    index_refresher(head_a);
}

void rotate_b(t_list **head_b)
{
    t_list *temp_b = NULL;
    t_list *current_node = NULL;

    if (!head_b ||!(*head_b) || !(*head_b)->next)
    {
        ft_printf("error not enough space for rotation");
        return;
    }
    temp_b = *head_b;
    current_node =(*head_b)->next;
    *head_b =(*head_b)->next;
    ft_printf("Successfully cut first node\n");
    while(current_node && current_node->next)
    {
        current_node = current_node->next;
    }
    ft_printf("Browse to last node successfully.\n");
    current_node->next = temp_b;
    temp_b->next = NULL;
    index_refresher(head_b);
}