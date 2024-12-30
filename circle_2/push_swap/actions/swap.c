/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:59:35 by cauffret          #+#    #+#             */
/*   Updated: 2024/12/30 16:32:08 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void swap_a (t_list *head)
{
    t_list *current_node= NULL;
    t_list *temp_node = NULL;

    temp_node = malloc(sizeof(t_list));
    current_node = head;
    while(current_node->index < 2)
    {
        current_node = current_node->next;
    }
    temp_node->data = current_node->data;
    ft_printf("First pass : Temp data : %d, Current data : %d, head data : %d\n", temp_node->data, current_node->data, head->data);
    current_node->data = head->data;
    ft_printf("Second pass :Temp data : %d, Current data : %d, head data : %d\n", temp_node->data, current_node->data, head->data);
    head->data = temp_node->data;
    ft_printf("Third pass : Temp data : %d, Current data : %d, head data : %d\n", temp_node->data, current_node->data, head->data);
    ft_printf("sa\n");
}

void swap_b (t_list *head)
{
    t_list *current_node= NULL;
    t_list *temp_node = NULL;

    temp_node = malloc(sizeof(t_list));
    current_node = head;
    while(current_node->index < 2)
    {
        current_node = current_node->next;
    }
    temp_node->data = current_node->data;
    ft_printf("First pass : Temp data : %d, Current data : %d, head data : %d\n", temp_node->data, current_node->data, head->data);
    current_node->data = head->data;
    ft_printf("Second pass :Temp data : %d, Current data : %d, head data : %d\n", temp_node->data, current_node->data, head->data);
    head->data = temp_node->data;
    ft_printf("Third pass : Temp data : %d, Current data : %d, head data : %d\n", temp_node->data, current_node->data, head->data);
    ft_printf("sb\n");
}