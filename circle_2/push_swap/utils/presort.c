/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:30:36 by root              #+#    #+#             */
/*   Updated: 2025/01/17 15:57:21 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

//FYI dummy, bottom means first that was in the list, you cannot push it ;)

void sort_three(t_list **head_a)
{
    if (is_sorted(*head_a))
        return;
    if ((*head_a)->data > (*head_a)->next->data)
        swap_a(*head_a);
    rotate_a(head_a);
    if ((*head_a)->data > (*head_a)->next->data)
        swap_a(*head_a);
    reverse_rotate_a(head_a);
    if((*head_a)->data > (*head_a)->next->data)
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

int is_sorted(t_list *head_a)
{
    long data2;
    long data3;
    
    data2 = head_a->next->data;
    if (!head_a->next->next)
    {
        if (head_a->data > data2)
            return (1);
        else
            return (0);
    }
    else
    {
        data3 = head_a->next->next->data;
        if (head_a->data > data2 && data2 > data3)
            return(1);
        else
            return(0);
    }
}