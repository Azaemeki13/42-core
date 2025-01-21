/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:00:28 by cauffret          #+#    #+#             */
/*   Updated: 2025/01/21 13:06:35 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// MOST SIGNIFICANT TO LEAST SIGNIFICANT 
#include "ft_push_swap.h"

void  create_node (t_list **head, char *arguments)
{
    /* NOTE : here actually we always go from start of list, may want to be optimised.*/
    t_list *new_node = NULL;

    new_node = malloc(sizeof (t_list));
    new_node->data = ft_atol(arguments);
    new_node->next = NULL;
    new_node->prev = NULL;
    if (*head == NULL) 
        *head = new_node;
    else 
    {
        append_node(head, new_node);
    }
}

void append_node(t_list **head, t_list *new_node)
{
    t_list *current_node =  NULL;

    current_node = (*head);
    while (current_node && current_node->next)
    {
        current_node = current_node->next;
    }
    current_node->next = new_node;
    new_node->prev = current_node;
}

char **argv_to_arg(int argc, char **argv)
{
    char **arguments;
    int i;

    i = 0;
    arguments = NULL;
    if (argc == 2)
    {
        arguments = ft_split(argv[1], ' ');
    }
    else if (argc > 2)
    {
        arguments = malloc(sizeof(char *) * (argc));
        while (i < (argc - 1))
        {
        arguments[i] = ft_strdup(argv[i + 1]);
        i++;
        }
        arguments[i] = NULL;
    }
    return (arguments);
}

int main (int argc, char **argv)
{
    t_list   *stack_a = NULL;  
    t_list   *stack_b = NULL;
    t_list   *stack_a_test = NULL;
    t_list   *stack_b_test = NULL;  
    char **arguments;
    int i;

    i = 0;
    arguments = NULL;
    if (argc == 1 || (argc == 2 && argv[1][0] == 0))
    {
        print_error();
        return (0);
    }
    arguments = argv_to_arg(argc, argv);
    if (!error_checker(arguments))
    {
        free_arguments(arguments);
        print_error();
        return (0);
    }
    while (arguments[i]!= NULL)
    {
        create_node(&stack_a, arguments[i]);
        i++;
    }
    presort(&stack_a, &stack_b, arguments);
    node_targeting(&stack_a, &stack_b);
    stack_a_test = stack_a;
    stack_b_test = stack_b;
    while (stack_a_test)
    {
        ft_printf("Value of A [index :%d, Value: %d, adress %p]\n", stack_a_test->index,stack_a_test->data, (void *) stack_a_test);
        stack_a_test = stack_a_test->next;
    }
    while (stack_b_test)
    {
        ft_printf("Value of B [index :%d, Value: %d, push price %d]\n", stack_b_test->index,stack_b_test->data,stack_b_test->push_price);
        stack_b_test = stack_b_test->next;
    }
    free_stack(stack_a);
    free_stack(stack_b);
    free_arguments(arguments);
    
    return 0;
}
