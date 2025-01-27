/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:34:06 by root              #+#    #+#             */
/*   Updated: 2025/01/23 14:16:23 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void rotate_above(t_list **head_a, t_list **head_b, t_list *target_node)
{
    if (!head_a || !head_b)
        return ;
    while (target_node->index != 0 && target_node->target_node->index != 0)
        rotate_all(head_a, head_b);
    overall_refresher(*head_a, *head_b);
    while (target_node->target_node->index != 0)
        reverse_rotate_a(head_a);
    while(target_node->index != 0)
    {
        reverse_rotate_b(head_b);
    }
    overall_refresher(*head_a, *head_b);
}

void rotate_before(t_list **head_a, t_list **head_b, t_list *target_node)
{
    if (!head_a || !head_b)
        return ;
    while (target_node->index != 0 && target_node->target_node->index != 0)
        reverse_rotate_all(head_a, head_b);
    overall_refresher(*head_a, *head_b);
    while (target_node->target_node->index != 0)
        reverse_rotate_a(head_a);
    while(target_node->index != 0)
    {
        reverse_rotate_b(head_b);
    }
    overall_refresher(*head_a, *head_b);
} 
