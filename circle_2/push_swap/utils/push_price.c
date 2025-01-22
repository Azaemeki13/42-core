/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_price.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:06:01 by root              #+#    #+#             */
/*   Updated: 2025/01/22 16:58:30 by root             ###   ########.fr       */
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
int len_stack(t_list *head)
{
    t_list *current_node = NULL;
    int i;

    i = 0;
    if (!head)
        return 444;
    current_node = head;
    while (current_node && current_node->next)
        current_node = current_node->next;
    i = (current_node->index);
    return (i);
}

void set_median (t_list *head)
{
    t_list *current_node = NULL;
    int i;

    i = 0;
    if (!head)
        return;
    current_node = head;
    
    i = len_stack(head);
    current_node = head;
    while (current_node)
    {
        if (current_node->index <= (i / 2))
            current_node->above_median = 0;
        else
            current_node->above_median = 1;
        current_node = current_node->next;
    }
}

void price_refresher(t_list *head_a, t_list *head_b)
{
    t_list *current_node = NULL;
    int len_a;
    int len_b;

    len_a = len_stack(head_a);
    len_b = len_stack(head_b);
    current_node = head_b;
    while (current_node)
    {
        current_node->push_price = current_node->index;
        if (current_node->above_median == 0)
            current_node->push_price = (len_b - (current_node->push_price));
        else if (current_node->target_node->above_median == 1)
            current_node->push_price += current_node->target_node->index;
        else 
            current_node->push_price += len_a - (current_node->target_node->index);
        current_node = current_node->next;
    }
}

void overall_refresher(t_list *head_a, t_list *head_b)
{
    index_refresher(head_a);
    ft_printf("index refreshed on a.\n");
    index_refresher(head_b);
    ft_printf("index refreshed on b.\n");
    set_median(head_a);
    ft_printf("median set on a.\n");
    set_median(head_b);
    ft_printf("median set on b.\n");
    price_refresher(head_a, head_b);
}