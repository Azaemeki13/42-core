/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:19:00 by cauffret          #+#    #+#             */
/*   Updated: 2025/02/10 12:52:26 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	push_to_three(t_list **head_a, t_list **head_b)
{
	t_list	*cheapest;

	cheapest = NULL;
	push_two(head_a, head_b);
	while ((*head_a)->next->next->next != 0)
	{
		overall_refresher(*head_a, *head_b);
		node_targeting(head_b, head_a);
		refresh_rota_cost(*head_a, *head_b, *head_a);
		list_cheapest((*head_a));
		cheapest = find_cheapest(*head_a);
		rotate_a_to_b((head_a), (head_b), cheapest);
	}
	sort_three(head_a);
}

void	after_three(t_list **head_a, t_list **head_b)
{
	while (*head_b)
	{
		overall_refresher(*head_a, *head_b);
		node_targeting2(head_a, head_b);
		rota_cost2(*head_b);
		rotate_b_to_a((head_a), (head_b), (*head_b));
	}
	f_solving(head_a, head_b);
}

void	all_done(t_list **head_a, t_list **head_b)
{
	push_to_three(head_a, head_b);
	after_three(head_a, head_b);
}

void	rotate_a_to_b(t_list **head_a, t_list **head_b, t_list *current_node)
{
	t_rot_mode	mode;

	mode = current_node->rotation;
	if (mode == ROT_RR)
		perform_rot_rr(head_a, head_b, current_node);
	else if (mode == ROT_RRR)
		perform_rot_rrr(head_a, head_b, current_node);
	else if (mode == ROT_RA_RRB)
		perform_rot_ra_rrb(head_a, head_b, current_node);
	else if (mode == ROT_RRA_RB)
		perform_rot_rra_rb(head_a, head_b, current_node);
	push_b(head_a, head_b);
	overall_refresher(*head_a, *head_b);
}

void	rotate_b_to_a(t_list **head_a, t_list **head_b, t_list *current_node)
{
	t_rot_mode	mode;

	mode = current_node->rotation;
	if (mode == ROT_RR)
		perform_rot_rr2(head_a, head_b, current_node);
	else if (mode == ROT_RRR)
		perform_rot_rrr2(head_a, head_b, current_node);
	else if (mode == ROT_RA_RRB)
		perform_rot_ra_rrb2(head_a, head_b, current_node);
	else if (mode == ROT_RRA_RB)
		perform_rot_rra_rb2(head_a, head_b, current_node);
	push_a(head_a, head_b);
	overall_refresher(*head_a, *head_b);
}
