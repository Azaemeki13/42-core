/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:59:35 by cauffret          #+#    #+#             */
/*   Updated: 2025/01/30 18:08:59 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	swap_a(t_list **head)
{
	t_list *first = NULL;
	t_list *second = NULL;
	
	if (!(*head) || !(*head)->next)
		return;
	first = (*head);
	second = (first)->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	(*head) = second;
	ft_printf("sa\n");
}

void	swap_b(t_list **head)
{
	t_list *first = NULL;
	t_list *second = NULL;
	
	if (!(*head) || !(*head)->next)
		return;
	first = (*head);
	second = (first)->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	(*head) = second;
	ft_printf("sb\n");
}

void	swap_all(t_list **head_a, t_list **head_b)
{
	swap_a(head_a);
	swap_b(head_b);
	overall_refresher((*head_a), (*head_b));
	ft_printf("ss\n");
}
