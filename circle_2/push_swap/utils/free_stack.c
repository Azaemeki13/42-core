/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:09:23 by cauffret          #+#    #+#             */
/*   Updated: 2024/12/30 17:23:03 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void free_stack(t_list *head)
{
    t_list *tmp_stack;
    
    while (head)
    {
        tmp_stack = head->next;
        free(head);
        head=tmp_stack;
    }   
}

void free_push(t_list *head)
{
    t_list *tmp_stack;
    while (head->index < 1)
    {
        tmp_stack = head->next;
        free(head);
        head=tmp_stack;
    }
}