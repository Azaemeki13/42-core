/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:59:23 by cauffret          #+#    #+#             */
/*   Updated: 2025/02/06 12:41:22 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	push_b(t_list **head_a, t_list **head_b)
{
	t_list	*new_node;

	new_node = NULL;
	if (!*head_a)
		return ;
	new_node = *head_a;
	*head_a = (*head_a)->next;
	if (*head_a)
		(*head_a)->prev = NULL;
	if (!*head_b)
	{
		*head_b = new_node;
		(*head_b)->next = NULL;
		(*head_b)->prev = NULL;
	}
	else
	{
		new_node->next = *head_b;
		(*head_b)->prev = new_node;
		*head_b = new_node;
		(*head_b)->prev = NULL;
	}
	overall_refresher((*head_a), (*head_b));
	write(1, "pb\n", 3);
}

void	push_a(t_list **head_a, t_list **head_b)
{
	t_list	*new_node;

	new_node = NULL;
	if (!*head_b)
	{
		print_error();
		return ;
	}
	new_node = *head_b;
	*head_b = (*head_b)->next;
	if (*head_b)
		(*head_b)->prev = NULL;
	if (!(*head_a))
		set_nul(head_a, new_node);
	else
	{
		new_node->next = *head_a;
		(*head_a)->prev = new_node;
		*head_a = new_node;
		(*head_a)->prev = NULL;
	}
	overall_refresher((*head_a), (*head_b));
	write(1, "pa\n", 3);
}

void	set_nul(t_list **head, t_list *new_node)
{
	*head = new_node;
	(*head)->next = NULL;
	(*head)->prev = NULL;
}
