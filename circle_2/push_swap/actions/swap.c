/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:59:35 by cauffret          #+#    #+#             */
/*   Updated: 2025/01/21 11:53:39 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	swap_a(t_list *head)
{
	t_list	*current_node;
	int		temp_data;

	current_node = NULL;
	if (!head || !head->next)
		return ;
	temp_data = 0;
	current_node = head->next;
	temp_data = current_node->data;
	current_node->data = head->data;
	head->data = temp_data;
	index_refresher(head);
	ft_printf("sa\n");
}

void	swap_b(t_list *head)
{
	t_list	*current_node;
	int		temp_data;

	current_node = NULL;
	if (!head || !head->next)
		return ;
	temp_data = 0;
	current_node = head->next;
	temp_data = current_node->data;
	current_node->data = head->data;
	head->data = temp_data;
	index_refresher(head);
	ft_printf("sb\n");
}

void	swap_all(t_list *head_a, t_list *head_b)
{
	swap_a(head_a);
	swap_b(head_b);
	index_refresher(head_a);
	index_refresher(head_b);
	ft_printf("ss\n");
}
