/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:36:31 by cauffret          #+#    #+#             */
/*   Updated: 2025/04/01 16:41:16 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void wait_init(t_list *head)
{
    head->state->priority_n = head->list_size - head->index;
    usleep(50);
}

void init_mutex(t_list *list)
{
    list->state->fork_init = pthread_mutex_init(&list->state->fork, NULL);
    list->state->sleeping_init = pthread_mutex_init(&list->state->sleeping, NULL);
    list->state->thinking_init = pthread_mutex_init(&list->state->thinking, NULL);
    list->state->priority_init = pthread_mutex_init(&list->state->priority, NULL);
}

void *routine(void *arg)
{
    t_list *list = (t_list *)arg;
    printf("Mutex initialised\n");
    while (list->requirements != 0)
    {
        philo_miam(list);
        philo_zzz(list);
        philo_cogito(list);
        list->requirements--;
    }
    return NULL;
}

void create_philo(t_list **head)
{
    t_list *nav;
    int list_size;
    int i;

    i = 0;
    nav = (*head);
    list_size = lst_size(*head) + 1;    
    while(i != list_size)
    {
        pthread_create(&nav->philosopher, NULL, routine, nav);
        usleep(10);
        nav = nav->next;
        i++;
    }
    printf("done with philo creation.\n");
    i = 0;
    nav = (*head);
    while(i != list_size)
    {
        pthread_join(nav->philosopher, NULL);
        nav = nav->next;
        i++;
    }
}