/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:54:39 by cauffret          #+#    #+#             */
/*   Updated: 2025/02/10 12:58:39 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	swap_a_all(t_list **head)
{
	t_list	*first;
	t_list	*second;

	first = NULL;
	second = NULL;
	if (!(*head) || !(*head)->next)
		return ;
	first = (*head);
	second = (first)->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	(*head) = second;
}

void	swap_b_all(t_list **head)
{
	t_list	*first;
	t_list	*second;

	first = NULL;
	second = NULL;
	if (!(*head) || !(*head)->next)
		return ;
	first = (*head);
	second = (first)->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	(*head) = second;
}

void	swap_all(t_list **head_a, t_list **head_b)
{
	swap_a_all(head_a);
	swap_b_all(head_b);
	overall_refresher((*head_a), (*head_b));
	write(1, "ss\n", 3);
}
