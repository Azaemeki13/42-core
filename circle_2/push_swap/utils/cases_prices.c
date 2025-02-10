/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_prices.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:44:20 by root              #+#    #+#             */
/*   Updated: 2025/02/10 12:48:29 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

int	ft_max(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}

void	compute_loop(int *a, int *b, t_rot_mode *mode)
{
	if (*b < *a)
	{
		*a = *b;
		(*mode) = ROT_RRR;
	}
	else
		(*mode) = ROT_RR;
}

void	rota_cost2(t_list *head_b)
{
	if (head_b->target_node->above_median)
		head_b->rotation = ROT_RRA_RB;
	else
	{
		head_b->rotation = ROT_RA_RRB;
	}
}

int	compute_rotation_cost(t_list *current_node, int len_a, int len_b,
		t_rot_mode *mode)
{
	int	c1;
	int	c2;
	int	c3;
	int	c4;

	c1 = ft_max(current_node->index, current_node->target_node->index);
	c2 = ft_max(len_a - current_node->index, len_b
			- current_node->target_node->index);
	c3 = current_node->index + (len_b - current_node->target_node->index);
	c4 = (len_a - current_node->index) + current_node->target_node->index;
	compute_loop(&c1, &c2, mode);
	if (c3 < c1)
	{
		c1 = c3;
		(*mode) = ROT_RA_RRB;
	}
	if (c4 < c1)
	{
		c1 = c4;
		(*mode) = ROT_RRA_RB;
	}
	return (c1 + 1);
}

void	refresh_rota_cost(t_list *head_a, t_list *head_b, t_list *from)
{
	int			len_a;
	int			len_b;
	t_rot_mode	mode;
	t_list		*current_node;

	current_node = NULL;
	current_node = from;
	len_a = list_size(head_a);
	len_b = list_size(head_b);
	while (current_node)
	{
		current_node->push_price = compute_rotation_cost(current_node, len_a,
				len_b, &mode);
		current_node->rotation = mode;
		current_node = current_node->next;
		overall_refresher(head_a, head_b);
	}
}
