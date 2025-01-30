/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort_prep.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/01/30 18:10:36 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../ft_push_swap.h"

// FYI dummy, bottom means first that was in the list, you cannot push it ;)

void	sort_two(t_list **head_a)
{
	if ((*head_a)->data < (*head_a)->next->data)
		return ;
	else
		swap_a(head_a);
	return ;
}

void	sort_three(t_list **head_a)
{
	if (is_sorted(*head_a))
		return ;
	if ((*head_a)->data > (*head_a)->next->data)
		swap_a(head_a);
	rotate_a(head_a);
	if ((*head_a)->data > (*head_a)->next->data)
		swap_a(head_a);
	reverse_rotate_a(head_a);
	if ((*head_a)->data > (*head_a)->next->data)
	{
		swap_a(head_a);
	}
}

int	is_sorted(t_list *head_a)
{
	long	data2;
	long	data3;

	data2 = head_a->next->data;
	if (!head_a->next->next)
	{
		if (head_a->data < data2)
			return (1);
		else
			return (0);
	}
	else
	{
		data3 = head_a->next->next->data;
		if (head_a->data < data2 && data2 < data3)
			return (1);
		else
			return (0);
	}
}

int	presort_checker(char **arguments)
{
	int	i;

	i = 0;
	while (arguments[i] != 0)
		i++;
	return (i);
}
