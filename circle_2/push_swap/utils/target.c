/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:31:14 by root              #+#    #+#             */
/*   Updated: 2025/02/10 12:54:31 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	node_targeting(t_list **to, t_list **from)
{
	t_list	*b_move;

	b_move = NULL;
	b_move = (*from);
	while (b_move)
	{
		b_move->target_node = find_target(*to, b_move);
		b_move = b_move->next;
	}
	overall_refresher((*to), (*from));
}

void	node_targeting2(t_list **to, t_list **from)
{
	t_list	*b_move;

	b_move = NULL;
	b_move = (*from);
	while (b_move)
	{
		b_move->target_node = find_target_2(*to, b_move);
		b_move = b_move->next;
	}
	overall_refresher((*to), (*from));
}

t_list	*find_target(t_list *to, t_list *from)
{
	t_list	*best_target;
	long	min_value;
	long	max_value;

	best_target = NULL;
	min_value = LONG_MAX;
	max_value = LONG_MIN;
	value_filler(&min_value, &max_value, to);
	if (from->data < min_value || from->data > max_value)
		return (maxi_value(to, max_value));
	best_target = bigger_smallest(from, to);
	if (!best_target)
		best_target = mini_value(to, min_value);
	return (best_target);
}

t_list	*find_target_2(t_list *to, t_list *from)
{
	t_list	*best_target;
	long	min_value;
	long	max_value;

	best_target = NULL;
	min_value = LONG_MAX;
	max_value = LONG_MIN;
	value_filler(&min_value, &max_value, to);
	if (from->data > max_value || from->data < min_value)
		return (mini_value(to, min_value));
	best_target = smallest_bigger(from, to);
	if (!best_target)
		best_target = mini_value(to, min_value);
	return (best_target);
}
