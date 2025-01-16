/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:30:36 by root              #+#    #+#             */
/*   Updated: 2025/01/16 13:44:58 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

//FYI dummy, bottom means first that was in the list, you cannot push it ;)

void sort_three(t_list **head_a)
{
    t_list *current_node =   NULL;
    t_list *highest_node =  NULL;

    highest_node = find_highest_node((*head_a));
    current_node = (*head_a);
    // CASE 1 ALLES GUT
    if (current_node->data < current_node->next->data && current_node->next->data < current_node->next->
        next->data)
        return;
    // CASE N PUT ON BOTTOM
    if (current_node->next->next->data != highest_node->data)
    {
        if (current_node->data == highest_node->data)
            reverse_rotate_a(head_a);
        else
        {
            swap_a(*head_a);
            reverse_rotate_a(head_a);
        }
    }
    if (current_node->data > current_node->next->data)
    {
        swap_a(*head_a);
    }
} 

t_list *find_highest_node(t_list *head)
{
    t_list *result = NULL;
    t_list *current = NULL;

    result = head;
    current = head;
    while (current && current->next)
    {
        if (current->data > result->data)
            result = current;
        current = current->next;
    }
    if (current->data > result->data)
    {
        result = current;
    }
    return (result);
}