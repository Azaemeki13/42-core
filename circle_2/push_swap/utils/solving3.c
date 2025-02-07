/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:06:01 by cauffret          #+#    #+#             */
/*   Updated: 2025/02/07 12:44:04 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void push_two(t_list **head_a, t_list **head_b)
{
    push_b(head_a, head_b);
    push_b(head_a, head_b);
}

void solving(t_list **head_a, t_list **head_b)
{
   
    until_three(head_a, head_b);
    after_three(head_a, head_b);
}

void until_three(t_list **head_a, t_list **head_b)
{
    t_list *cheapest = NULL;
      
    push_two(head_a, head_b);
    while((*head_a)->next->next->next != 0)
    {
        overall_refresher(*head_a, *head_b);
        node_targeting(head_b, head_a);
        price_refresher((*head_a),(*head_b));
        list_cheapest((*head_a));
        cheapest = find_cheapest((*head_a));
        final_rotate1(head_a, head_b, cheapest);
    }
    sort_three(head_a);
}

/*void after_three(t_list **head_a, t_list **head_b)
{
    t_list *cheapest = NULL;
    while((*head_b))
    {
        overall_refresher(*head_a, *head_b);
        node_targeting2(head_a, head_b);
        price_refresher((*head_b),(*head_a));
        list_cheapest((*head_b));
        cheapest = find_cheapest((*head_b));
        final_rotate2(head_a, head_b, cheapest);
    }
    f_solving(head_a, head_b);
}
*/
