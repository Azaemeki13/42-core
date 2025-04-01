/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_annex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:36:31 by cauffret          #+#    #+#             */
/*   Updated: 2025/04/01 14:11:38 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

char *format_arg(char **arguments)
{
    char *result;
    char *temp;
    
    result = ft_strdup("");
    while(*arguments)
    {
        temp = ft_strjoin(result, *arguments);
        free(result);
        result = temp;
        arguments++;
    }
    printf("Thats the result %s\n", result);
    return (result);
}

void facto_requirements(t_list *nav, unsigned int requirements)
{
    t_list *temp;

    temp = nav;
    while (temp)
    {
        temp->requirements = (unsigned int) requirements;
        init_mutex(temp);
        temp = temp->next;
    }
}

void make_it_circular(t_list *head)
{
    t_list *temp = NULL;

    temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = head;
    head->prev = temp;
}
void clear_list(t_list **head)
{
    t_list *temp = NULL;
    t_list *last = NULL;

    last = (*head)->prev;
    if (last)
        last->next = NULL;
    while (*head)
    {
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
        temp = (*head)->next;
        free(*head);
        (*head) = temp;
    }
    (*head) = NULL;
}
