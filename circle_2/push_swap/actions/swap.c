/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:59:35 by cauffret          #+#    #+#             */
/*   Updated: 2024/12/30 16:55:17 by cauffret         ###   ########.fr       */
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
    //ft_printf("First pass : Temp data : %d, Current data : %d, head data : %d\n", temp_data, current_node->data, head->data);
    current_node->data = head->data;
    //ft_printf("Second pass :Temp data : %d, Current data : %d, head data : %d\n", temp_data, current_node->data, head->data);
    head->data = temp_data;
    //ft_printf("Third pass : Temp data : %d, Current data : %d, head data : %d\n", temp_data, current_node->data, head->data);
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
    //ft_printf("First pass : Temp data : %d, Current data : %d, head data : %d\n", temp_data, current_node->data, head->data);
    current_node->data = head->data;
    //ft_printf("Second pass :Temp data : %d, Current data : %d, head data : %d\n", temp_data, current_node->data, head->data);
    head->data = temp_data;
    //ft_printf("Third pass : Temp data : %d, Current data : %d, head data : %d\n", temp_data, current_node->data, head->data);
    ft_printf("sb\n");
}