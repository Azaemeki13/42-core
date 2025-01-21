/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:45:46 by root              #+#    #+#             */
/*   Updated: 2025/01/21 12:04:20 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void index_refresher(t_list *head)
{
    t_list *current_node = NULL;
    int i;
    
    i = 0;
    if (!head)
        return;
    current_node = head;
    current_node->index = i;
    while (current_node)
    {
        current_node->index = i++;
        current_node = current_node->next;
    }
}