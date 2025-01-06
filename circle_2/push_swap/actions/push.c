/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:59:23 by cauffret          #+#    #+#             */
/*   Updated: 2025/01/06 16:31:19 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void push_b(t_list **head_a, t_list **head_b)
{
    t_list *new_node = NULL;
    
    if (!*head_a)
        return;
    new_node = *head_a;
    *head_a = (*head_a)->next;
    ft_printf("New node at address %p has data %d.\n", (void*) new_node, new_node->data);
    if (!head_b)
    {
        ft_printf("No stack b found.\n");
        *head_b = new_node;
        (*head_b)->next = NULL;
    }
    else
    {
        new_node->next = *head_b;
        *head_b = new_node;        
    }
    ft_printf("pb\n");
}

void push_a(t_list **head_a, t_list **head_b)
{
    t_list *new_node = NULL;
    
    if (!*head_b)
    {
        ft_printf("Error, returning...");
        return;
    }
    new_node = *head_b;
    *head_b = (*head_b)->next;
    ft_printf("New node at address %p has data %d.\n", (void*) new_node, new_node->data);
    if (!head_a)
    {
        ft_printf("No stack a found.\n");
        *head_a = new_node;
        (*head_a)->next = NULL;
    }
    else
    {
        new_node->next = *head_a;
        *head_a = new_node;        
    }
    ft_printf("pa\n");
}