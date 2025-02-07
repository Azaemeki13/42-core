/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_price.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:06:01 by root              #+#    #+#             */
/*   Updated: 2025/02/07 16:32:46 by root             ###   ########.fr       */
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

	void	overall_refresher(t_list *head_a, t_list *head_b)
	{
		index_refresher(head_a);
		index_refresher(head_b);
	}
