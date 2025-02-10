/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:59:28 by cauffret          #+#    #+#             */
/*   Updated: 2025/02/06 11:48:31 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	reverse_rotate_a(t_list **head_a)
{
	t_list	*current_node;
	t_list	*temp_a;

	temp_a = NULL;
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
	write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_list **head_b)
{
	t_list	*current_node;
	t_list	*temp_b;

	temp_b = NULL;
	if (!*head_b || !(*head_b)->next)
		return ;
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
	write(1, "rrb\n", 4);
}
