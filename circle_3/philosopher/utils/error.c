/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:35:16 by cauffret          #+#    #+#             */
/*   Updated: 2025/04/07 10:49:14 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void clear_list(t_list **head)
{
    t_list *temp = NULL;
    t_list *last = NULL;

    last = (*head)->prev;
    if (last)
        last->next = NULL;
    while (*head)
    {
        if ((*head)->message)
            pthread_mutex_destroy(&(*head)->message->message);
        if ((*head)->philosopher)
            pthread_join((*head)->philosopher, NULL);
        if((*head)->state->fork_init)
            pthread_mutex_destroy(&(*head)->state->fork);
        if((*head)->state->thinking_init)
            pthread_mutex_destroy(&(*head)->state->thinking);
        if((*head)->state->sleeping_init)
            pthread_mutex_destroy(&(*head)->state->sleeping);
        if((*head)->state->priority_init)
            pthread_mutex_destroy(&(*head)->state->priority);
        free((*head)->state);
        free((*head)->message);
        temp = (*head)->next;
        free(*head);
        (*head) = temp;
    }
    (*head) = NULL;
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
