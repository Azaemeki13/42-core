/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:00:28 by cauffret          #+#    #+#             */
/*   Updated: 2025/01/06 11:34:45 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void  create_node (t_list **head, char *argv)
{
    /* NOTE : here actually we always go from start of list, may want to be optimised.*/
    t_list *new_node = NULL;
    t_list *current_node = NULL;
    static int  i = 0;

    new_node = malloc(sizeof (t_list));
    new_node->data = ft_atoi(argv);
    new_node->index = (i++);
    new_node->next = NULL;
    if (*head == NULL) 
    {
        *head = new_node;
    }
    else 
    {
        current_node = *head;
        while (current_node->next != NULL)
            current_node = current_node-> next;
        current_node->next = new_node;
    }
} 

int main (int argc, char **argv)
{
    static t_list   *stack_a = NULL;
    //t_list *stack_b = NULL;
    //t_list          *testa;
    //t_list          *testb;
    signed int i;

    i = 1;
    //testa = stack_a;
    //testb = stack_b;
    if (argc < 2)
        return (ft_printf("Error, please retry"));
    else 
        {
            while (argv[i] != 0)
            {
                create_node(&stack_a, argv[i++]); // using i++ here and not before because otherwise OOB access .
            }
        }
    rotate_a(&stack_a);
    free_stack(stack_a);
    return 0;
}
