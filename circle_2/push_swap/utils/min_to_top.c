/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_to_top.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:34:06 by root              #+#    #+#             */
/*   Updated: 2025/02/07 16:36:47 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

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