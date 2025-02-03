/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_logic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:31:14 by root              #+#    #+#             */
/*   Updated: 2025/02/03 12:51:37 by root             ###   ########.fr       */
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

t_list	*find_target(t_list *to, t_list *from)
{
	t_list	*best_target = NULL;
	long	min_value;
	long	max_value;
	t_list	*tmp = NULL;

	min_value = LONG_MAX;
	max_value = LONG_MIN;
	value_filler(&min_value, &max_value, to);
	if (from->data < min_value || from->data > max_value)
		return (mini_value(to, min_value));
	tmp = to;
	while (tmp)
	{
		if (tmp->data >= from->data)
		{
			if (!best_target || tmp->data < best_target->data)
				best_target = tmp;
		}
		tmp = tmp->next;
	}
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
