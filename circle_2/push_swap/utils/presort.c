/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:25:40 by root              #+#    #+#             */
/*   Updated: 2025/01/30 13:34:09 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	presort(t_list **head_a, t_list **head_b, char **arguments)
{
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
	else if (presort_checker(arguments) > 3)
	{
		rota_one(head_a, head_b);
		sort_three(head_a);
		index_refresher(*head_a);
		index_refresher(*head_b);
		return ;
	}
}