/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:21:37 by cauffret          #+#    #+#             */
/*   Updated: 2025/02/03 11:59:44 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	rotate_above1(t_list **head_a, t_list **head_b, t_list *target_node)
{
	if (!head_a || !head_b)
		return ;
	while (target_node != 0 && target_node->target_node->index != 0)
		reverse_rotate_all(head_a, head_b);
	overall_refresher(*head_a, *head_b);
	while (target_node->target_node->index != 0)
		reverse_rotate_b(head_b);
	while (target_node->index != 0)
	{
		reverse_rotate_a(head_a);
	}
	push_b(head_a, head_b);
	overall_refresher(*head_a, *head_b);
}

void	rotate_before1(t_list **head_a, t_list **head_b, t_list *target_node)
{
	if (!head_a || !head_b)
		return ;
	while (target_node != 0 && target_node->target_node->index != 0)
		rotate_all(head_a, head_b);
	overall_refresher(*head_a, *head_b);
	while (target_node->target_node->index != 0)
		rotate_b(head_b);
	while (target_node->index != 0)
	{
		rotate_a(head_a);
	}
	push_b(head_a, head_b);
	overall_refresher(*head_a, *head_b);
}

void final_rotate1(t_list **head_a, t_list **head_b, t_list *target_node)
{   
    if (target_node->above_median)
        rotate_above1(head_a, head_b, target_node);
    else
        rotate_before1(head_a, head_b, target_node);
}
