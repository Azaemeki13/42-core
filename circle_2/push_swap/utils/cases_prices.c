/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_prices.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:44:20 by root              #+#    #+#             */
/*   Updated: 2025/02/07 16:24:43 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

int ft_max(int a, int b)
{
    if (a < b)
        return (b);
    return(a);
}

void compute_loop(int *a, int *b, t_rot_mode *mode)
{
    if (*b < *a)
    {
        *a = *b;
        (*mode) = ROT_RRR;
    }
    else
        (*mode) = ROT_RR;
}
void rota_cost2(t_list *head_b)
{
    if (head_b->target_node->above_median)
        head_b->rotation = ROT_RRA_RB;
    else 
    {
        head_b->rotation = ROT_RA_RRB;
    }
}
int compute_rotation_cost(int index_a, int index_b, int len_a, int len_b, t_rot_mode *mode)
{
    int c1;
    int c2;
    int c3;
    int c4;
    
    c1 = ft_max(index_a, index_b);
    c2 = ft_max(len_a - index_a, len_b - index_b);
    c3 = index_a +(len_b - index_b);
    c4 = (len_a - index_a) + index_b;
    compute_loop(&c1, &c2, mode);
    if (c3 < c1)
    {
        c1 = c3;
        (*mode) = ROT_RA_RRB;
    } 
    if (c4 < c1)
    {
        c1 = c4;
        (*mode) = ROT_RRA_RB;
    }
    return (c1 + 1);
}
void refresh_rota_cost(t_list *head_a, t_list *head_b, t_list *from)
{
    int len_a;
    int len_b;
    t_rot_mode mode;
    t_list *current_node = NULL;
    
    current_node = from;
    len_a = list_size(head_a);
    len_b = list_size(head_b);
    while (current_node)
    {
        current_node->push_price = compute_rotation_cost(current_node->index, current_node->target_node->index, len_a, len_b, &mode);
        current_node->rotation = mode;
        current_node = current_node->next;
        overall_refresher(head_a, head_b);
    }
}
void push_to_three(t_list **head_a, t_list **head_b)
{
    t_list *cheapest = NULL;
    
    push_two(head_a, head_b);
    while ((*head_a)->next->next->next != 0)
    {
        overall_refresher(*head_a, *head_b);
        node_targeting(head_b, head_a);
        refresh_rota_cost(*head_a, *head_b, *head_a);
        list_cheapest((*head_a));
        cheapest = find_cheapest(*head_a);
        rotate_a_to_b((head_a),(head_b), cheapest);
    }
    sort_three(head_a);
}

void after_three(t_list **head_a, t_list **head_b)
{
    
    while (*head_b)
    {
        overall_refresher(*head_a, *head_b);
        node_targeting2(head_a, head_b);
        rota_cost2(*head_b);
        rotate_b_to_a((head_a),(head_b), (*head_b));
    }
    f_solving(head_a, head_b);
}

void all_done(t_list **head_a, t_list **head_b)
{
    push_to_three(head_a, head_b);
    after_three(head_a, head_b);
}

void rotate_a_to_b(t_list **head_a, t_list **head_b, t_list *current_node)
{
    t_rot_mode mode;

    mode = current_node->rotation;
    if (mode == ROT_RR)
        perform_rot_rr(head_a, head_b, current_node);
    else if (mode == ROT_RRR)
        perform_rot_rrr(head_a, head_b, current_node);
    else if (mode == ROT_RA_RRB)
        perform_rot_ra_rrb(head_a, head_b, current_node);
    else if (mode == ROT_RRA_RB)
        perform_rot_rra_rb(head_a, head_b, current_node);
    push_b(head_a, head_b);
    overall_refresher(*head_a, *head_b);
}

void rotate_b_to_a(t_list **head_a, t_list **head_b, t_list *current_node)
{
    t_rot_mode mode;

    mode = current_node->rotation;
    if (mode == ROT_RR)
        perform_rot_rr2(head_a, head_b, current_node);
    else if (mode == ROT_RRR)
        perform_rot_rrr2(head_a, head_b, current_node);
    else if (mode == ROT_RA_RRB)
        perform_rot_ra_rrb2(head_a, head_b, current_node);
    else if (mode == ROT_RRA_RB)
        perform_rot_rra_rb2(head_a, head_b, current_node);
    push_a(head_a, head_b);
    overall_refresher(*head_a, *head_b);
}
