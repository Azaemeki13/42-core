/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_price.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:06:01 by root              #+#    #+#             */
/*   Updated: 2025/02/05 13:13:00 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

	void	index_refresher(t_list *head)
	{
		int	i;
		int size;

		size = list_size(head);
		i = 0;
		while (head)
		{
			head->index = i;
			head->above_median = (i > size / 2);
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
	int same_d (t_list *a, t_list *b)
	{
		if (!a || !b)
			return (0);
		if ((a->above_median && b->above_median)
		|| (!a->above_median && !b->above_median))
			return(1);
		return(0);
	}
	
	void same_d_price(t_list *current_node, int len_a, int len_b)
	{
		t_list *target = NULL;
		int cost_a;
		int cost_b;
		int common;

		target = current_node->target_node;
		if(target)
		{
			cost_a = minimal_rotation_cost(current_node->index, len_a);
			cost_b = minimal_rotation_cost(target->index, len_b);
			if (same_d(current_node, target))
			{
				if (cost_a < cost_b)
					common = cost_a;
				else
					common = cost_b;
				current_node->push_price = (cost_a + cost_b) - common + 1;
			}
			else
			{
				current_node->push_price = cost_a + cost_b + 1;	
			}
		}
		
	}

	void	price_refresher(t_list *head_a, t_list *head_b)
	{
		int		len_a;
		int		len_b;
		t_list	*current_node = NULL;

		len_a = list_size(head_a);
		len_b = list_size(head_b);
		current_node = head_a;
		while (current_node)
		{
			same_d_price(current_node, len_a, len_b);
			current_node = current_node->next;
		}
			
	}

	void	overall_refresher(t_list *head_a, t_list *head_b)
	{
		index_refresher(head_a);
		index_refresher(head_b);
	}
