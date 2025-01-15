/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:30:36 by root              #+#    #+#             */
/*   Updated: 2025/01/15 13:23:43 by root             ###   ########.fr       */
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
            rotate_a(head_a); // not reverse rotate :D
        else
        {
            swap_a(*head_a);
        }
    }
} 

t_list *find_highest_node(t_list *head)
{
    t_list *result = NULL;

    result = head->next;
    // if first one is bigger 
    if (result->data < result->prev->data && result->data > result->next->data)
        return (result->prev);
    // if last one is bigger
    else if (result->data > result->prev->data && result->data < result->next->data)
    {
        return (result->next);
    }
    return (result);
    
}