/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_logic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:31:14 by root              #+#    #+#             */
/*   Updated: 2025/01/27 15:04:27 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	node_targeting(t_list **head_a, t_list **head_b)
{
	t_list	*b_move;

	b_move = NULL;
	b_move = (*head_b);
	while (b_move)
	{
		b_move->target_node = find_target(*head_a, b_move);
		b_move = b_move->next;
	}
	overall_refresher((*head_a), (*head_b));
}

t_list	*find_target(t_list *head_a, t_list *b_node)
{
	t_list	*best_target;
	long	min_value;
	long	max_value;
	t_list	*tmp;

	best_target = head_a;
	tmp = head_a;
	min_value = LONG_MAX;
	max_value = LONG_MIN;
	value_filler(&min_value, &max_value, head_a);
	if (b_node->data < min_value)
		return (mini_value(head_a, min_value));
	if (b_node->data > max_value)
		return (mini_value(head_a, min_value));
	tmp = head_a;
	while (tmp)
	{
		if (tmp->data >= b_node->data)
		{
			return (tmp);
		}
		tmp = tmp->next;
	}
	return (best_target);
}

t_list	*mini_value(t_list *head_a, int min_value)
{
	t_list	*tmp;

	tmp = NULL;
	tmp = head_a;
	while (tmp->data != min_value)
		tmp = tmp->next;
	return (tmp);
}

t_list	*maxi_value(t_list *head_a, int max_value)
{
	t_list	*tmp;

	tmp = NULL;
	tmp = head_a;
	while (tmp->data != max_value)
		tmp = tmp->next;
	return (tmp);
}

void	value_filler(long *min_value, long *max_value, t_list *head_a)
{
	t_list	*tmp;

	tmp = NULL;
	tmp = head_a;
	while (tmp != NULL)
	{
		if (tmp->data < *min_value)
			*min_value = tmp->data;
		if (tmp->data > *max_value)
			*max_value = tmp->data;
		tmp = tmp->next;
	}
}
