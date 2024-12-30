/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:00:28 by cauffret          #+#    #+#             */
/*   Updated: 2024/12/30 12:27:13 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "./libft/ft_printf/ft_printf.h"
#include "ft_push_swap.h"

/*t_list *sort_index(t_list *head)
{
    if (head == NULL)
        return ;
    while(head->index != 1)
        head->next;
    return (head);
}
*/
void  create_node (t_list **head, char *argv)
{
    t_list *new_node;
    t_list *head_node;
    static int i;

    i =0;
    /* head_node = sort_index(*head); */
    new_node = malloc(sizeof (t_list));
    if (head_node == NULL) 
    {
        *head = new_node;
    }
    else 
    {
        head_node->next = new_node;
    }
    new_node->data = *(argv);
    new_node->index = (i++);
} 

int main (int argc, char **argv)
{
    static t_list   *stack_a = NULL;
    t_list          *test;

    test = malloc(sizeof(t_list));
    test = stack_a;
    if (argc < 2)
        return (ft_putstr("Error, please retry"));
    else 
        {
            while (*argv)
            {
                create_node(stack_a, *argv);
            }
        }
    while (test != NULL)
    {
        printf("Stack value at address : %p is the following : %d", *test, test->data);
        test->next;
    }
}