/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:09:57 by cauffret          #+#    #+#             */
/*   Updated: 2025/02/11 11:55:40 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	sort_4(t_list **head_a, t_list **head_b)
{
	overall_refresher(*head_a, *head_b);
	f_solving(head_a, head_b);
	push_b(head_a, head_b);
	sort_three(head_a);
	push_a(head_a, head_b);
	overall_refresher(*head_a, *head_b);
}
