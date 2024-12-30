/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_refresher.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 18:58:29 by cauffret          #+#    #+#             */
/*   Updated: 2024/12/30 19:03:53 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void index_refresher(t_list **head)
{
    t_list *current_node;
    
    current_node =(*head);
    (*head)->index = 0;
    while (current_node)
    {
        current_node->index++;
        current_node = current_node->next;
    }
}