/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:00:28 by cauffret          #+#    #+#             */
/*   Updated: 2024/12/13 17:29:33 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../libft/ft_printf/ft_printf.h"
#include "ft_push_swap.h"

t_list *sort_index(t_list *head)
{
    if (head == NULL)
        return ;
    while(head->index != 1)
        head->next;
    return (head);
}
void  create_node (t_list **head)
{
    t_list *new_node;
    t_list *head_node;
    head_node = sort_index(*head);
        new_node = malloc(sizeof (t_list));
    if (head_node == NULL) 
    {
        *head = new_node;
    }
} 

int main (int argc, char **argv)
{
    if (argc < 2)
        return (ft_putstr("Error, pelase retry"));
        
}