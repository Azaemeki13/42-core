/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_price.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:06:01 by root              #+#    #+#             */
/*   Updated: 2025/01/29 18:34:26 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

	void	index_refresher(t_list *head)
	{
		int	i;

		i = 0;
		while (head)
		{
			head->index = i;
			if (head->index <= (list_size(head) / 2))
				head->above_median = 0;
			else
				head->above_median = 1;
			i++;
			head = head->next;
		}
	}

	int	list_size(t_list *head)
	{
		t_list	*current_node;
		int		i;

		current_node = NULL;
		i = 0;
		current_node = head;
		while (current_node)
		{
			current_node = current_node->next;
			i++;
		}
		return (i);
	}

	int	minimal_rotation_cost(int i, int len)
	{
		if (i <= len / 2)
			return (i);
		else
		{
			return (len - i);
		}
	}

	void	price_refresher(t_list *head_a, t_list *head_b)
	{
		int		len_a;
		int		len_b;
		t_list	*current_node;
		int		cost_a;
		int		cost_b;

		current_node = NULL;
		len_a = list_size(head_a);
		len_b = list_size(head_b);
		current_node = head_b;
		while (current_node)
		{
			cost_b = minimal_rotation_cost(current_node->index, len_b);
			cost_a = 0;
			if (current_node->target_node)
				cost_a = minimal_rotation_cost(current_node->target_node->index,
						len_a);
			current_node->push_price = cost_a + cost_b;
			current_node = current_node->next;
		}
	}

	void	overall_refresher(t_list *head_a, t_list *head_b)
	{
		index_refresher(head_a);
		index_refresher(head_b);
	}