/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:34:06 by root              #+#    #+#             */
/*   Updated: 2025/02/06 12:41:26 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	rotate_above2(t_list **head_a, t_list **head_b, t_list *target_node)
{
	if (!head_a || !head_b)
		return ;
	while (target_node->index != 0 && target_node->target_node->index != 0)
		rotate_all(head_a, head_b);
	while (target_node->target_node->index != 0)
		rotate_a(head_a);
	while (target_node->index != 0)
	{
		rotate_b(head_b);
	}
	push_a(head_a, head_b);
	overall_refresher(*head_a, *head_b);
}

void	rotate_before2(t_list **head_a, t_list **head_b, t_list *target_node)
{
	if (!head_a || !head_b)
		return ;
	while (target_node->index != 0 && target_node->target_node->index != 0)
		reverse_rotate_all(head_a, head_b);
	while (target_node->target_node->index != 0)
		reverse_rotate_a(head_a);
	while (target_node->index != 0)
	{
		reverse_rotate_b(head_b);
	}
	push_a(head_a, head_b);
	overall_refresher(*head_a, *head_b);
}

void	final_rotate2(t_list **head_a, t_list **head_b, t_list *target_node)
{
	if (target_node->above_median)
		rotate_above2(head_a, head_b, target_node);
	else
	{
		rotate_before2(head_a, head_b, target_node);
	}
}

t_list	*find_min(t_list *head)
{
	long	min;
	t_list	*result;

	result = NULL;
	min = LONG_MAX;
	if (!head)
		return (result);
	while (head)
	{
		if (head->data < min)
		{
			min = head->data;
			result = head;
		}
		head = head->next;
	}
	return (result);
}

void	f_solving(t_list **head_a, t_list **head_b)
{
	t_list *min = NULL;

	min = find_min(*head_a);
	if (min->above_median)
	{
		while (min->index != 0)
			reverse_rotate_a(head_a);
	}
	else
	{
		while (min->index != 0)
			rotate_a(head_a);
	}
	overall_refresher(*head_a, *head_b);
}