/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:59:32 by cauffret          #+#    #+#             */
/*   Updated: 2025/01/21 11:53:04 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void rotate_a(t_list **head_a)
{
    t_list *temp_a = NULL;
    t_list *current_node = NULL;

    if (!head_a ||!(*head_a) || !(*head_a)->next)
    {
        print_error();
        return;
    }
    temp_a = *head_a;
    current_node =(*head_a)->next;
    *head_a =(*head_a)->next;
    (*head_a)->prev = NULL;
    while(current_node && current_node->next)
    {
        current_node = current_node->next;
    }
    current_node->next = temp_a;
    temp_a->prev = current_node;
    temp_a->next = NULL;
    index_refresher(*head_a);
    ft_printf("ra\n");
}

void rotate_b(t_list **head_b)
{
    t_list *temp_b = NULL;
    t_list *current_node = NULL;

    if (!head_b ||!(*head_b) || !(*head_b)->next)
    {
        print_error();
        return;
    }
    temp_b = *head_b;
    current_node =(*head_b)->next;
    *head_b =(*head_b)->next;
    (*head_b)->prev = NULL;
    while(current_node && current_node->next)
    {
        current_node = current_node->next;
    }
    current_node->next = temp_b;
    temp_b->prev = current_node;
    temp_b->next = NULL;
    index_refresher(*head_b);
    ft_printf("rb\n");
}

void rotate_all(t_list **head_a, t_list **head_b)
{
    rotate_a(head_a);
    rotate_b(head_b);
    index_refresher(*head_a);
    index_refresher(*head_b);
    printf("rr\n");
}