/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:00:28 by cauffret          #+#    #+#             */
/*   Updated: 2025/01/27 17:34:26 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// MOST SIGNIFICANT TO LEAST SIGNIFICANT
#include "ft_push_swap.h"

void	create_node(t_list **head, char *arguments)
{
	t_list	*new_node;

	/* NOTE : here actually we always go from start of list,
		may want to be optimised.*/
	new_node = NULL;
	new_node = malloc(sizeof(t_list));
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

void	append_node(t_list **head, t_list *new_node)
{
	t_list	*current_node;

	current_node = NULL;
	current_node = (*head);
	while (current_node && current_node->next)
	{
		current_node = current_node->next;
	}
	current_node->next = new_node;
	new_node->prev = current_node;
}

char	**argv_to_arg(int argc, char **argv)
{
	char	**arguments;
	int		i;

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

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*stack_a_test;
	t_list	*stack_b_test;
	t_list	*cheapest;
	char	**arguments;
	int		i;

	stack_a = NULL;
	stack_b = NULL;
	stack_a_test = NULL;
	stack_b_test = NULL;
	cheapest = NULL;
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
	while (arguments[i] != NULL)
	{
		create_node(&stack_a, arguments[i]);
		i++;
	}
	presort(&stack_a, &stack_b, arguments);
	ft_printf("all good here\n");
	node_targeting(&stack_a, &stack_b);
	stack_a_test = stack_a;
	stack_b_test = stack_b;
	while (stack_a_test)
	{
		ft_printf("Value of A [index :%d, Value: %d, address %p]\n",
			stack_a_test->index, stack_a_test->data, (void *)stack_a_test);
		stack_a_test = stack_a_test->next;
	}
	stack_b_test = stack_b;
	while (stack_b_test)
	{
		ft_printf("Value of B [index :%d, Value: %d, target %p]\n",
			stack_b_test->index, stack_b_test->data, stack_b_test->target_node);
		stack_b_test = stack_b_test->next;
	}
	ft_printf("List size is %d \n", list_size(stack_a));
	stack_a_test = stack_a;
	stack_b_test = stack_b;
	while (stack_b)
	{
		list_cheapest(stack_b);
		ft_printf("cheapest listed.\n");
		cheapest = find_cheapest(stack_b);
        node_targeting(&stack_a, &stack_b);
		ft_printf("done with node targeting.\n");
		ft_printf("cheapest tagged. \n");
		final_rotate(&stack_a, &stack_b, cheapest);
        	ft_printf("rotation done. \n");
		price_refresher(stack_a, stack_b);
		ft_printf("price refreshed.\n");
	}
    f_solving(&stack_a, &stack_b);
	ft_printf("final solving done. \n");
	stack_a_test = stack_a;
	while (stack_a_test)
	{
		ft_printf("Value of A [index :%d, Value: %d]\n", stack_a_test->index,
			stack_a_test->data);
		stack_a_test = stack_a_test->next;
	}
	stack_b_test = stack_b;
	while (stack_b_test)
	{
		ft_printf("Value of B [index :%d, Value: %d, cheapest %d]\n",
			stack_b_test->index, stack_b_test->data, stack_b_test->cheapest);
		stack_b_test = stack_b_test->next;
	}
	free_stack(stack_a);
	free_stack(stack_b);
	free_arguments(arguments);
	return (0);
}
