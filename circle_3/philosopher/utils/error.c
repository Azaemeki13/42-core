/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:35:16 by cauffret          #+#    #+#             */
/*   Updated: 2025/04/18 19:03:53 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void clear_list(t_list **head, t_shared *message)
{
    t_list *temp = NULL;
    t_list *last = NULL;

    last = (*head)->prev;
    if (message)
    {
        pthread_mutex_destroy(&message->message);
        free(message);
        message = NULL;
    }
    if (last)
        last->next = NULL;
    while (*head)
    {
        if ((*head)->message)
            pthread_mutex_destroy(&(*head)->message->message);
        printf("test 1\n");
        if ((*head)->philosopher)
            pthread_join((*head)->philosopher, NULL);
        printf("test 2\n");
        if((*head)->state->fork_init)
            pthread_mutex_destroy(&(*head)->state->fork);
        printf("test 3\n");
        if((*head)->state->thinking_init)
            pthread_mutex_destroy(&(*head)->state->thinking);
        printf("test 4\n");
        if((*head)->state->sleeping_init)
            pthread_mutex_destroy(&(*head)->state->sleeping);
        printf("test 5\n");
        if((*head)->state->priority_init)
            pthread_mutex_destroy(&(*head)->state->priority);
        printf("test 6\n");
        free((*head)->state);
        printf("test 7\n");
        free((*head)->message);
        printf("test 8\n");
        temp = (*head)->next;
        printf("test 9\n");
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
