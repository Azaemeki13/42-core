/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:14:41 by root              #+#    #+#             */
/*   Updated: 2025/01/27 13:15:39 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	list_cheapest(t_list *head_b)
{
	long	highest;
	t_list	*node_result;

	node_result = NULL;
	highest = LONG_MAX;
	if (!head_b)
		return ;
	while (head_b)
	{
		if (head_b->push_price < highest)
		{
			highest = head_b->push_price;
			node_result = head_b;
		}
		head_b = head_b->next;
	}
	node_result->cheapest = 1;
}

t_list	*find_cheapest(t_list *head_b)
{
	while (head_b)
	{
		if (head_b->cheapest)
			return (head_b);
		head_b = head_b->next;
	}
	return (NULL);
}