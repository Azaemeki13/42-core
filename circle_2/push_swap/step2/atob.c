/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atob.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:06:01 by cauffret          #+#    #+#             */
/*   Updated: 2025/01/30 18:33:03 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void push_two(t_list **head_a, t_list **head_b)
{
    t_list *a_t = (*head_a);
    while(a_t)
    {
        ft_printf("Stack A  [Value: %d Index: %d]\n", a_t->data, a_t->index); 
        a_t = a_t->next;
    }
    ft_printf("starting push\n");
    push_b(head_a, head_b);
    push_b(head_a, head_b);
    t_list *b_t = (*head_b);
    a_t = (*head_a);
    while(a_t)
    {
        ft_printf("Stack A  [Value: %d Index: %d]\n", a_t->data, a_t->index); 
        a_t = a_t->next;
    }
    while (b_t)
    {
        ft_printf("Stack B  [Value: %d Index: %d]\n", b_t->data, b_t->index);
        b_t = b_t->next;
    }
}

void rota_one(t_list **head_a, t_list **head_b)
{
    t_list *cheapest = NULL;
    t_list *a_t = NULL;
    t_list *b_t = NULL;
    push_two(head_a, head_b);
    while((*head_a)->next->next->next != 0)
    {
        price_refresher((*head_b),(*head_a));
        list_cheapest((*head_a));
        cheapest = find_cheapest((*head_a));
        cheapest_show((*head_a));
        node_targeting(head_b, head_a);
        target_show(*head_a);
        final_rotate1(head_a, head_b, cheapest);
        a_t = (*head_a);
        b_t = (*head_b);
        while(a_t)
        {
            ft_printf("Stack A in loop [Value: %d Index: %d]\n", a_t->data, a_t->index); 
            target_show((a_t));
            a_t = a_t->next;
        }
        while(b_t)
        {
            ft_printf("Stack B in loop  [Value: %d Index: %d]\n", b_t->data, b_t->index); 
            b_t = b_t->next;
        }
        (*head_a) = (*head_a)->next;
        ft_printf("LOOP N FINISHED HIHIHIHI\n");
    }
}