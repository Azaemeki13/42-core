/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:59:23 by cauffret          #+#    #+#             */
/*   Updated: 2025/01/29 18:26:34 by cauffret         ###   ########.fr       */
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
	ft_printf("pb\n");
}

void	push_a(t_list **head_a, t_list **head_b)
{
	t_list *new_node = NULL;

	if (!*head_b)
	{
		print_error();
		return ;
	}
	new_node = *head_b;
	*head_b = (*head_b)->next;
	if (*head_b)
		(*head_b)->prev = NULL;
	if (!*head_a)
	{
		*head_a = new_node;
		(*head_a)->next = NULL;
		(*head_a)->prev = NULL;
	}
	else
	{
		new_node->next = *head_a;
		(*head_a)->prev = new_node;
		*head_a = new_node;
		(*head_a)->prev = NULL;
	}
	overall_refresher((*head_a),(*head_b));
	if (!*head_b)
	{
		return ;
	}
	ft_printf("pa\n");
}
