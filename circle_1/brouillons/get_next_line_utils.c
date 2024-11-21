/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:12:55 by ituriel           #+#    #+#             */
/*   Updated: 2024/11/21 13:40:27 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*new_node(char *buffer, ssize_t size)
{
	t_list	*node;
	ssize_t	i;

	i = 0;
	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->str_buf = malloc(sizeof(char) * size);
	if (!node->str_buf)
	{
		free(node);
		return (NULL);
	}
	while (i < size)
	{
		node->str_buf[i] = buffer[i];
		i++;
	}
	node->next = NULL;
	return (node);
}

void	append_node(t_list **head, char *buffer)
{
	t_list	*temp;

	if (!*head)
		*head = temp;
	else
	{
		temp = *head;
		while (temp->next)
			temp = temp->next;
		temp->next = temp;
	}
}

size_t	ft_strlen(const char *str)
{
	char	*nav;
	size_t	i;

	i = 0;
	nav = (char *)str;
	while (nav[i] != 0)
	{
		i++;
	}
	return (i);
}

size_t	length_to_nl(t_list **head)
{
	t_list	*temp;
	size_t	total_length;
	size_t	i;

	temp = *head;
	total_length = 0;
	while (temp)
	{
		i = 0;
		while (temp->str_buf[i])
		{
			if (temp->str_buf[i] == '\n')
			{
				total_length += i+1;
				return (total_length);
			}
			i++;
		}
		total_length += ft_strlen(temp->str_buf);
		temp = temp->next;
	}
	return (total_length);
}

char	*copy_line(t_list **head, size_t total_length)
{
	char	*line;
	t_list	*temp;
	size_t	line_indx;
	size_t	i;

	line = malloc(sizeof(char) *total_length + 1);
	if (!line)
		return (NULL);
	temp = *head;
	line_indx = 0;
	while (temp && total_length > 0)
	{
		i = 0;
		while (temp->str_buf[i] && total_length > 0)
		{
			line[line_indx++] = temp->str_buf[i++];
			total_length--;
		}
		temp = temp->next;
	}
	line[line_indx] = '\0';
	return (line);
}
