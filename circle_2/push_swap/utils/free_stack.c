/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:09:23 by cauffret          #+#    #+#             */
/*   Updated: 2025/01/17 17:47:59 by cauffret         ###   ########.fr       */
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
    free(head);
}

void free_push(t_list *head)
{
    t_list *tmp_stack;
    while (head->next)
    {
        tmp_stack = head->next;
        free(head);
        head=tmp_stack;
    }
}

void free_arguments(char **arguments)
{
    int i;

    i = 0;
    if (!arguments)
        return;
    while(arguments[i])
    {
        free(arguments[i]);
        i++;
    }
    free(arguments);
}