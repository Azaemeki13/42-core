/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:25:40 by root              #+#    #+#             */
/*   Updated: 2025/02/13 13:17:03 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	push_two(t_list **head_a, t_list **head_b)
{
	push_b(head_a, head_b);
	push_b(head_a, head_b);
}

void	presort(t_list **head_a, t_list **head_b, char **arguments)
{
	if (is_sorted(*head_a))
		return ;
	if (presort_checker(arguments) == 2)
	{
		sort_two(head_a);
		return ;
	}
	if (presort_checker(arguments) == 3)
	{
		sort_three(head_a);
		return ;
	}
	if (presort_checker(arguments) == 4)
	{
		sort_4(head_a, head_b);
		overall_refresher(*head_a, *head_b);
	}
	else if (presort_checker(arguments) > 4)
	{
		all_done(head_a, head_b);
		overall_refresher(*head_a, *head_b);
		return ;
	}
}
