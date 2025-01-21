/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_price.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:06:01 by root              #+#    #+#             */
/*   Updated: 2025/01/21 16:12:45 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void price_refresher(t_list *head)
{
    t_list *current_node = NULL;

    current_node = head;
    if (!current_node)
        return;
    while (current_node)
    {
        current_node->push_price = ((current_node->index) + (current_node->target_node->index));
        current_node = current_node->next;
    }
}