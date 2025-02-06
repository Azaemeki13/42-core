/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:59:35 by cauffret          #+#    #+#             */
/*   Updated: 2025/02/06 11:49:16 by root             ###   ########.fr       */
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
	write(1,"sa\n",3);
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
	write(1,"sb\n",3);
}
