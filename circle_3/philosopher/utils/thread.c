/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:36:31 by cauffret          #+#    #+#             */
/*   Updated: 2025/03/31 12:49:56 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void wait_init(t_list *head)
{
    usleep(50 * ((head->list_size) - (head->index)));
}

void init_mutex(t_list *list)
{
    list->state->fork_init = pthread_mutex_init(&list->state->fork, NULL);
    list->state->sleeping_init = pthread_mutex_init(&list->state->sleeping, NULL);
    list->state->thinking_init = pthread_mutex_init(&list->state->thinking, NULL);
}

void *routine(void *arg)
{
    t_list *list = (t_list *)arg;
    init_mutex(list);
    wait_init(list);
    while (list->requirements != 0)
    {
        philo_miam(list);
        philo_zzz(list);
        list->requirements--;
    }
}

void create_pĥilo(t_list **head)
{
    t_list *nav;

    nav = (*head);
    while(nav)
    {
        pthread_create(nav->philosopher, NULL, routine, &nav);
        nav = nav->next;
    }
}