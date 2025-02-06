/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:09:23 by cauffret          #+#    #+#             */
/*   Updated: 2025/02/06 12:41:22 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	free_stack(t_list *head)
{
	t_list	*tmp_stack = NULL;

	while (head)
	{
		tmp_stack = head;
		head = head->next;
		if (tmp_stack->target_node)
			tmp_stack->target_node = NULL;
		free(tmp_stack);
	}
}

void	free_arguments(char **arguments)
{
	int i;

	i = 0;
	if (!arguments)
		return ;
	while (arguments[i])
	{
		free(arguments[i]);
		i++;
	}
	free(arguments);
}

void free_all (t_list **head_a, t_list **head_b, char **arguments)
{
	free_stack(*head_a);
	free_stack(*head_b);
	free_arguments(arguments);
}