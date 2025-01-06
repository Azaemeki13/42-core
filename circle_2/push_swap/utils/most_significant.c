/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   most_significant.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:53:48 by ituriel           #+#    #+#             */
/*   Updated: 2025/01/06 17:21:17 by ituriel          ###   ########.fr       */
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

