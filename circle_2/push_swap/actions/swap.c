/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:59:35 by cauffret          #+#    #+#             */
/*   Updated: 2025/01/06 16:52:10 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void swap_a (t_list *head)
{
    t_list *current_node= NULL;
    int temp_data;

    if (!head || !head->next)
        return;
    temp_data = 0; 
    current_node = head->next;
    temp_data = current_node->data;
    current_node->data = head->data;
    head->data = temp_data;
    ft_printf("sa\n");
}

void swap_b (t_list *head)
{
    t_list *current_node= NULL;
    int temp_data;

    if (!head || !head->next)
        return;
    temp_data = 0; 
    current_node = head->next;
    temp_data = current_node->data;
    current_node->data = head->data;
    head->data = temp_data;
    ft_printf("sb\n");
}

void swap_all (t_list *head_a, t_list *head_b)
{
    swap_a(head_a);
    swap_b(head_b);
    ft_printf("ss\n");
}
