/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:20:27 by root              #+#    #+#             */
/*   Updated: 2025/02/07 13:40:16 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void perform_rot_rr2(t_list **head_a, t_list **head_b, t_list *from)
{
    while (from->index > 0 && from->target_node->index > 0)
        rotate_all(head_a, head_b);
    while(from->index > 0)
        rotate_b(head_b);
    while(from->target_node->index > 0)
    {
        rotate_a(head_a);
    }
}

void perform_rot_rrr2(t_list **head_a, t_list **head_b, t_list *from)
{
  
    while ((from->index) > 0 && (from->target_node->index) > 0)
    {
        reverse_rotate_all(head_a, head_b);
    }
    while ((from->index) > 0)
    {
        reverse_rotate_b(head_b);
    }
    while ((from->target_node->index) > 0)
    {
        reverse_rotate_a(head_a);
    }
}

void perform_rot_rra_rb2(t_list **head_a, t_list **head_b, t_list *from)
{
    while (from->index > 0)
        rotate_b(head_b);
    while((from->target_node->index) > 0)
    {
        reverse_rotate_a(head_a);
    }
}

void perform_rot_ra_rrb2(t_list **head_a, t_list **head_b, t_list *from)
{
    while((from->index) > 0)
    {
        reverse_rotate_b(head_b);
    }
    while (from->target_node->index > 0)
    {
        rotate_a(head_a);
    }
}

