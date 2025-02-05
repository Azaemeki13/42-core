/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:31:14 by root              #+#    #+#             */
/*   Updated: 2025/02/05 16:57:41 by cauffret         ###   ########.fr       */
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
	t_list	*best_target = NULL;
	long	min_value;
	long	max_value;

	min_value = LONG_MAX;
	max_value = LONG_MIN;
	value_filler(&min_value, &max_value, to);
	if (from->data < min_value || from->data > max_value)
		return (maxi_value(to, max_value));
	best_target = bigger_smallest(from,to);
	if (!best_target)
		best_target = mini_value(to, min_value);
	return (best_target);
}

t_list	*find_target_2(t_list *to, t_list *from)
{
	t_list	*best_target = NULL;
	long	min_value;
	long	max_value;

	min_value = LONG_MAX;
	max_value = LONG_MIN;
	value_filler(&min_value, &max_value, to);
	if (from->data > max_value || from->data < min_value)
		return (mini_value(to, min_value));
	best_target = smallest_bigger(from,to);
	if (!best_target)
		best_target = mini_value(to, min_value);
	return (best_target);
}

t_list	*mini_value(t_list *to, long min_value)
{
	t_list	*tmp;

	tmp = NULL;
	tmp = to;
	while (tmp->data != min_value)
		tmp = tmp->next;
	return (tmp);
}

t_list	*maxi_value(t_list *to, long max_value)
{
	t_list	*tmp;

	tmp = NULL;
	tmp = to;
	while (tmp->data != max_value)
		tmp = tmp->next;
	return (tmp);
}

void	value_filler(long *min_value, long *max_value, t_list *to)
{
	t_list	*tmp;

	tmp = NULL;
	tmp = to;
	while (tmp != NULL)
	{
		if (tmp->data < *min_value)
			*min_value = tmp->data;
		if (tmp->data > *max_value)
			*max_value = tmp->data;
		tmp = tmp->next;
	}
}

t_list *bigger_smallest(t_list *from, t_list *to)
{
	t_list *result = NULL;
	long long diff;

	diff = LONG_MAX;
	while (to)
	{
		if ( from->data > to->data)
		{
			if (diff > (from->data - to->data))
				{
					diff = from->data - to->data;
					result = to;
				}
		}
		to = to->next;
	}
	return (result);
}

t_list *smallest_bigger(t_list *from, t_list *to)
{
	t_list *result = NULL;
	long long diff;

	diff = LONG_MAX;
	while (to)
	{
		if ( from->data < to->data)
		{
			if (diff > (to->data - from->data))
				{
					diff = to->data - from->data;
					result = to;
				}
		}
		to = to->next;
	}
	return (result);
}
