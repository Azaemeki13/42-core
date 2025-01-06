/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:59:28 by cauffret          #+#    #+#             */
/*   Updated: 2025/01/06 13:17:36 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void reverse_rotate_a(t_list **head_a)
{
t_list *current_node;
t_list *temp_a;
t_list *before_last;

current_node = (*head_a);
before_last = (*head_a);
// we love pairwise :DDDDDDDDD IM NOT DOUBLE ITERATING
while (current_node->next)
{
    before_last = current_node;
    current_node = current_node->next;
}
temp_a = current_node;
before_last->next = NULL;
temp_a->next = (*head_a);
(*head_a)= temp_a;
index_refresher(head_a);
ft_printf("rra");
}

void reverse_rotate_b(t_list **head_b)
{
t_list *current_node;
t_list *temp_b;
t_list *before_last;

current_node = (*head_b);
before_last = (*head_b);
// we love pairwise :DDDDDDDDD IM NOT DOUBLE ITERATING
while (current_node->next)
{
    before_last = current_node;
    current_node = current_node->next;
}
temp_b = current_node;
before_last->next = NULL;
temp_b->next = (*head_b);
(*head_b)= temp_b;
index_refresher(head_b);
ft_printf("rrb");
}

void reverse_rotate_b(t_list **head_a, t_list **head_b)
{
    reverse_rotate_a(head_a);
    reverse_rotate(head_b);
    ft_printf("rrr");
}
