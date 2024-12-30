/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:00:28 by cauffret          #+#    #+#             */
/*   Updated: 2024/12/30 17:02:43 by cauffret         ###   ########.fr       */
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
//  t_list          *test;
    signed int i;

    i = 1;
    if (argc < 2)
        return (ft_printf("Error, please retry"));
    else 
        {
            while (argv[i] != 0)
            {
                create_node(&stack_a, argv[i++]); // using i++ here and not before because otherwise OOB access .
            }
        }
// Here I want to initilise test after I perform operations on stack a, otherwise
// it's not returning anything :) 
 //   test = stack_a;
/*    while (test != NULL)
    {
        printf("Stack value at address : %p is the following : %d\n", (void *)test, test->data);
        test = test->next;
    }
*/
    swap_a(stack_a);
    while (stack_a)
    {
        t_list *tmp_stack = stack_a;
        stack_a = stack_a->next;
        free(tmp_stack);
    }
    return 0;
}
