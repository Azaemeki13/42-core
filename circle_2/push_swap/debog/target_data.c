/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:14:42 by cauffret          #+#    #+#             */
/*   Updated: 2025/01/30 16:17:49 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void target_show(t_list *to_show)
{
        ft_printf("****************************************************Push price: %d Node Value: %d Target node value :%d \n", to_show->push_price, to_show->data, to_show->target_node->data);
}

void cheapest_show(t_list *to_show)
{
    while (to_show)
    {
        if(to_show->cheapest)
            ft_printf("*-*-*-*-*-This is cheapest: [Data: %d, Index: %d]\n*-*-*-*-*-", to_show->data,to_show->index);
        to_show = to_show->next;
    }
}