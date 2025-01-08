/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:55:08 by root              #+#    #+#             */
/*   Updated: 2025/01/08 15:35:21 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void list_sorter(t_list **head_a, t_list **head_b)
{
    t_list *current_node = *head_a; // Temporary pointer for traversal
    t_list *prev_node = NULL;       // To track the node before the current one

    while (current_node) {
        if (!comparer(current_node)) {
            // If comparer fails, push the current node to stack_b
            if (prev_node) {
                prev_node->next = current_node->next; // Skip the current node in stack_a
            } else {
                *head_a = current_node->next; // Update head_a if the head is removed
            }

            push_b(&current_node, head_b); // Push the node to stack_b

            // Update traversal pointer
            if (prev_node) {
                current_node = prev_node->next;
            } else {
                current_node = *head_a;
            }
        } else {
            // Move both pointers forward
            prev_node = current_node;
            current_node = current_node->next;
        }
    }

    // Debug: Print final state of stack_b
    ft_printf("\nFinal Stack B:\n");
    current_node = *head_b;
    while (current_node) {
        ft_printf("[Data: %d, Address: %p]\n", current_node->data, (void *)current_node);
        current_node = current_node->next;
    }
}
