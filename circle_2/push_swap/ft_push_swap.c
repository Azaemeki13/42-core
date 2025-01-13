/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:00:28 by cauffret          #+#    #+#             */
/*   Updated: 2025/01/13 10:14:39 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// MOST SIGNIFICANT TO LEAST SIGNIFICANT 
#include "ft_push_swap.h"

void  create_node (t_list **head, char *arguments)
{
    /* NOTE : here actually we always go from start of list, may want to be optimised.*/
    t_list *new_node = NULL;
    t_list *current_node = NULL;
    t_list *temp_node = NULL;

    new_node = malloc(sizeof (t_list));
    new_node->data = ft_atol(arguments);
    new_node->next = NULL;
    new_node->prev = NULL;
    if (*head == NULL) 
    {
        *head = new_node;
    }
    else 
    {
        current_node = (*head);
        while (current_node->next != NULL)
        {
            temp_node = current_node;
            current_node = current_node-> next;
        }
        current_node->prev = temp_node;
        current_node->next = new_node;
    }
} 
/*
int main (int argc, char **argv)
{
     t_list   *stack_a = NULL;
    t_list *stack_b = NULL;
    char **arguments;
 
    arguments = NULL;
    if (argc == 1 || (argc == 2 && argv[1][0] == 0))
        return
    if (argc < 3)
        return (ft_printf("Error, please retry\n"));
    else 
        {
            while (argv[i] != 0)
            {
                create_node(&stack_a, argv[i++]); // using i++ here and not before because otherwise OOB access .
            }
        }
    list_sorter(&stack_a, &stack_b);
    testa = stack_a;
   // testb = stack_b;
    ft_printf("List sorting action finished.\n");
    
    while (testa)
    {
        ft_printf("Stack A: [Data: %d, Adress: %p]\n", testa->data, (void*) testa);
        testa = testa->next;
    }

    
    free_stack(stack_a);
    free_stack(stack_b);
    return 0;
}
*/