/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_all.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:39:29 by cauffret          #+#    #+#             */
/*   Updated: 2025/02/05 16:40:48 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	reverse_rotate_a_all(t_list **head_a)
{
	t_list	*current_node;
	t_list	*temp_a = NULL;

	current_node = (*head_a);
	while (current_node->next)
	{
		current_node = current_node->next;
	}
	temp_a = current_node;
	temp_a->prev->next = NULL;
	temp_a->next = (*head_a);
	(*head_a)->prev = temp_a;
	temp_a->prev = NULL;
	(*head_a) = temp_a;
	index_refresher(*head_a);
}

void	reverse_rotate_b_all(t_list **head_b)
{
	t_list	*current_node;
	t_list	*temp_b = NULL;

	if (!*head_b || !(*head_b)->next)
        return;
	current_node = (*head_b);
	while (current_node->next)
	{
		current_node = current_node->next;
	}
	temp_b = current_node;
	temp_b->prev->next = NULL;
	temp_b->next = (*head_b);
	(*head_b)->prev = temp_b;
	temp_b->prev = NULL;
	(*head_b) = temp_b;
	index_refresher(*head_b);
}

void	reverse_rotate_all(t_list **head_a, t_list **head_b)
{
	reverse_rotate_a_all(head_a);
	reverse_rotate_b_all(head_b);
	overall_refresher((*head_a), (*head_b));
	ft_printf("rrr\n");
}