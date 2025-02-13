/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort_prep.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:16:48 by cauffret          #+#    #+#             */
/*   Updated: 2025/02/13 13:14:19 by root             ###   ########.fr       */
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
	t_list	*data_one;
	t_list	*data_two;
	t_list	*data_three;

	data_one = NULL;
	data_two = NULL;
	data_three = NULL;
	data_one = (*head_a);
	data_two = (*head_a)->next;
	data_three = (*head_a)->next->next;
	if (data_one->data > data_two->data && data_one->data > data_three->data)
		rotate_a(head_a);
	else if (data_two->data > data_three->data)
		reverse_rotate_a(head_a);
	data_one = (*head_a);
	data_two = (*head_a)->next;
	data_three = (*head_a)->next->next;
	if (data_one->data > data_two->data)
		swap_a(head_a);
}

int	presort_checker(char **arguments)
{
	int	i;

	i = 0;
	while (arguments[i] != 0)
		i++;
	return (i);
}

int	is_sorted(t_list *head)
{
	while (head && head->next)
	{
		if (head->data > head->next->data)
			return (0);
		head = head->next;
	}
	return (1);
}
