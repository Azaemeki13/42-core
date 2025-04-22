/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:35:16 by cauffret          #+#    #+#             */
/*   Updated: 2025/04/22 16:55:42 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	clear_list(t_list **head, t_shared *message)
{
	t_list	*last;

	last = NULL;
	if ((*head) && (*head)->prev)
		(*head)->prev->next = NULL;
	if (message)
	{
		pthread_mutex_destroy(&message->message);
		free(message);
		message = NULL;
	}
	last = (*head);
	short_clear(last);
	(*head) = NULL;
}

void	short_clear(t_list *last)
{
	t_list	*temp;

	temp = NULL;
	while (last)
	{
		if (last->state->fork_init)
			pthread_mutex_destroy(&last->state->fork);
		if (last->state->thinking_init)
			pthread_mutex_destroy(&last->state->thinking);
		if (last->state->sleeping_init)
			pthread_mutex_destroy(&last->state->sleeping);
		free(last->state);
		temp = (last)->next;
		free(last);
		last = temp;
	}
}

void	*ft_memset(void *ptr, int value, size_t num)
{
	char	*base;
	size_t	i;

	i = 0;
	base = (char *)ptr;
	while (i < num)
	{
		base[i] = (char)value;
		i++;
	}
	return (ptr);
}
