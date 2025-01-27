/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort_prep.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:30:36 by root              #+#    #+#             */
/*   Updated: 2025/01/20 10:25:27 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

// FYI dummy, bottom means first that was in the list, you cannot push it ;)

void	sort_two(t_list **head_a)
{
	if ((*head_a)->data < (*head_a)->next->data)
		return ;
	else
		swap_a(*head_a);
	return ;
}

void	sort_three(t_list **head_a)
{
	if (is_sorted(*head_a))
		return ;
	if ((*head_a)->data > (*head_a)->next->data)
		swap_a(*head_a);
	rotate_a(head_a);
	if ((*head_a)->data > (*head_a)->next->data)
		swap_a(*head_a);
	reverse_rotate_a(head_a);
	if ((*head_a)->data > (*head_a)->next->data)
	{
		swap_a(*head_a);
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

void	push_until_three(t_list **head_a, t_list **head_b)
{
	while ((*head_a)->next->next->next != 0)
	{
		push_b(head_a, head_b);
	}
	while ((*head_a)->prev)
	{
		(*head_a) = (*head_a)->prev;
	}
	ft_printf("Successfully pushed all \n");
	return ;
}

int	presort_checker(char **arguments)
{
	int	i;

	i = 0;
	while (arguments[i] != 0)
		i++;
	return (i);
}
