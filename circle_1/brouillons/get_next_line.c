/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:12:52 by ituriel           #+#    #+#             */
/*   Updated: 2024/11/21 11:29:03 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char	*result;

	result = (char *)s;
	while (*result != '\0')
	{
		if (*result == (char)c)
			return ((char *)result);
		result++;
	}
	if (c == '\0')
	{
		return (result);
	}
    return (NULL);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (dest < src)
	{
		while (n--)
			*d++ = *s++;
	}
	else if (dest > src)
	{
		while (n > 0)
		{
			n--;
			d[n] = s[n];
		}
	}
	return (dest);
}

void	clean_up_list(t_list **head, size_t consumed_length)
{
	t_list	*temp;
	size_t	i;

	while (*head && consumed_length > 0)
	{
		temp = *head;
		i = 0;
		while (temp->str_buf[i] && consumed_length > 0)
		{
			i++;
			consumed_length--;
		}
		if (temp->str_buf[i] == '\0')
		{
			*head = temp->next;
			free(temp->str_buf);
			free(temp);
		}
		else
		{
			ft_memmove(temp->str_buf, temp->str_buf + i,
				(ft_strlen(temp->str_buf + i)) + 1);
			break ;
		}
	}
}

int	newline_found(t_list **head)
{
	t_list	*temp;
	size_t	i;

	temp = *head;
	while (temp)
	{
		i = 0;
		while (i < ft_strlen(temp->str_buf))
		{
			if (temp->str_buf[i] == '\n')
			{
				return (1);
			}
			i++;
		}
		temp = temp->next;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static t_list	*head = NULL;
	char			buffer[BUFFER_SIZE];
	ssize_t			bytes_read;
	t_list			*node;
	char			*line;
	ssize_t alloc = 0;

	// Validate inputs
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	line = NULL;

	// Read and stash data until a newline is found or EOF is reached
	while (!newline_found(&head))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (NULL);
		buffer[bytes_read] = '\0'; // Null-terminate buffer
		node = new_node(buffer, bytes_read);
		if (!node)
			return (NULL);
		append_node(&head, node);
	}

	// Determine line length (including newline if present)
	alloc = length_to_nl(&head);
	if (bytes_read == 0)
	{
		// Handle EOF without newline
		if (head)
		{
			line = copy_line(&head, alloc);
			clean_up_list(&head, alloc);
			return (line);
		}
		return (NULL);
	}

	// Copy the line and clean up the stash
	line = copy_line(&head, bytes_read);
	clean_up_list(&head, bytes_read);
	return (line);
}
	
