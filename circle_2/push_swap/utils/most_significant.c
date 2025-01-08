/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   most_significant.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:53:48 by ituriel           #+#    #+#             */
/*   Updated: 2025/01/08 15:41:34 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

int pass_amount( t_list *head_a)
{
signed int i;
t_list *current_node = NULL;

if (!head_a)
    return (0);
current_node = head_a;
i = 0;
while (current_node && current_node->next)
{
    if (current_node->digit_count > i)
        i = current_node->digit_count;
    current_node = current_node->next;
}
return (i);
}

int numeric_convertor(unsigned long long n)
{
int result; 

result = n;
while (n > 10)
{
    n = n / 10;
}
result = n;
return (result);
}

int comparer (t_list *head)
{
    unsigned long long i;
    unsigned long long n;

    if (!head->next)
        return (i >=n);
    i = numeric_convertor(head->data);
    n = numeric_convertor(head->next->data);
    ft_printf("Comparing i: %d and n: %d\n", head->data,head->next->data);
    return(i <= n);
}
