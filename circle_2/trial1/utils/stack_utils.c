/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:31:57 by cauffret          #+#    #+#             */
/*   Updated: 2025/01/13 09:52:00 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void    init_stacks(t_list **head,char *elements)
{
    t_list *current_node =   NULL;
    t_list *new_node =  NULL;
    
    new_node = malloc(sizeof(t_list));
    new_node->data = atol(elements);
    if (!new_node)
        return (NULL);
    if (*head == NULL)
        (*head) = new_node;
    else
    {
        current_node = (*head);
        while (current_node)
            current_node = current_node->next;
        current_node->next = new_node;    
    }
}