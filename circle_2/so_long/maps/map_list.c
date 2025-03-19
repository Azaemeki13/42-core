/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:53:05 by ituriel           #+#    #+#             */
/*   Updated: 2025/03/11 16:40:19 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	create_node(t_buffer **head, char *arguments)
{
	t_buffer	*new_node;

	new_node = NULL;
	new_node = malloc(sizeof(*new_node));
	new_node->content = arguments;
	new_node->index = -1;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (*head == NULL)
		*head = new_node;
	else
	{
		add_node(head, new_node);
	}
}

void	add_node(t_buffer **head, t_buffer *new_node)
{
	t_buffer	*current_node;

	current_node = NULL;
	current_node = (*head);
	while (current_node && current_node->next)
	{
		current_node = current_node->next;
	}
	current_node->next = new_node;
	new_node->prev = current_node;
}

t_buffer	*arg_to_node(t_buffer *map_buffer, int fd)
{
	char	*arguments;

	arguments = get_next_line(fd);
	while (arguments != NULL)
	{
		create_node(&map_buffer, arguments);
		arguments = get_next_line(fd);
	}
	index_refresher(map_buffer);
	return (map_buffer);
}

void	index_refresher(t_buffer *map_buffer)
{
	int	i;

	i = -1;
	while (map_buffer)
	{
		map_buffer->index = ++i;
		map_buffer = map_buffer->next;
	}
}
