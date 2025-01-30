/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:36:27 by cauffret          #+#    #+#             */
/*   Updated: 2025/01/29 18:34:20 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void final_refresher (t_list **head_a, t_list **head_b)
{
    overall_refresher((*head_a), (*head_b));
    price_refresher((*head_a), (*head_b));
    list_cheapest((*head_b));
    node_targeting(head_a, head_b);
}