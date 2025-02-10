/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:00:28 by cauffret          #+#    #+#             */
/*   Updated: 2025/02/10 15:10:03 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// MOST SIGNIFICANT TO LEAST SIGNIFICANT
#include "ft_push_swap.h"

void	create_node(t_list **head, char *arguments)
{
	t_list	*new_node;

	new_node = NULL;
	new_node = malloc(sizeof(t_list));
	new_node->data = ft_atol(arguments);
	new_node->index = -1;
	new_node->push_price = -1;
	new_node->above_median = 0;
	new_node->cheapest = -1;
	new_node->target_node = NULL;
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
	char	**arguments;

	stack_a = NULL;
	stack_b = NULL;
	arguments = NULL;
	if (argc == 1 || (argc == 2 && argv[1][0] == 0))
	{
		print_error();
		return (0);
	}
	arguments = argv_to_arg(argc, argv);
	if (!error_checker(arguments))
	{
		print_free_error(arguments);
		return (0);
	}
	stack_a = arg_to_node(arguments, stack_a);
	presort(&stack_a, &stack_b, arguments);
	free_all(&stack_a, &stack_b, arguments);
	return (0);
}

t_list	*arg_to_node(char **arguments, t_list *stack_a)
{
	int	i;

	i = 0;
	while (arguments[i] != NULL)
	{
		create_node(&stack_a, arguments[i]);
		i++;
	}
	return (stack_a);
}
