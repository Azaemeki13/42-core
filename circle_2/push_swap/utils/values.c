/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:54:41 by cauffret          #+#    #+#             */
/*   Updated: 2025/02/10 12:55:05 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

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

t_list	*bigger_smallest(t_list *from, t_list *to)
{
	t_list		*result;
	long long	diff;

	result = NULL;
	diff = LONG_MAX;
	while (to)
	{
		if (from->data > to->data)
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

t_list	*smallest_bigger(t_list *from, t_list *to)
{
	t_list		*result;
	long long	diff;

	result = NULL;
	diff = LONG_MAX;
	while (to)
	{
		if (from->data < to->data)
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
