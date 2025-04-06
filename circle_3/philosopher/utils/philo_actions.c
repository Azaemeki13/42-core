/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:28:18 by ituriel           #+#    #+#             */
/*   Updated: 2025/04/06 12:57:04 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void philo_cogito(t_list *head)
{
    if ((head != target_prio(head))&& (!philo_controler(head)))
    {
        is_alive(head);
        pthread_mutex_lock(&head->state->thinking);
        is_alive(head);
        printf("%lld ms Philosopher %d is thinking\n", get_elapsed(head), head->index);
        while ((head != target_prio(head))&& (!philo_controler(head)))
        {
            is_alive(head);
            usleep(10);
        }
        pthread_mutex_unlock(&head->state->thinking);     
        return ;
    }
    else
        return ;
}

void philo_miam(t_list *head)
{    
    is_alive(head);
    pthread_mutex_lock(&head->next->state->fork);
    printf("%lld ms Philosopher %d has taken right fork.\n",get_elapsed(head), head->index);
    is_alive(head);
    pthread_mutex_lock(&head->state->fork);
    printf("%lld ms Philosopher %d has taken left fork.\n", get_elapsed(head), head->index);
    printf("%lld ms Philosopher %d is eating\n", get_elapsed(head), head->index);
    usleep((head->time_to_eat) * 1000);
    pthread_mutex_lock(&head->state->priority);
    head->state->priority_n = 0;
    pthread_mutex_unlock(&head->state->priority);
    pthread_mutex_unlock(&head->state->fork);
    pthread_mutex_unlock(&head->next->state->fork);
    head->last_eat = get_elapsed(head);
}

void philo_zzz(t_list *head)
{
    is_alive(head);
    pthread_mutex_lock(&head->state->sleeping);
    printf("%lld ms Philosopher %d is sleeping.\n",get_elapsed(head), head->index);
    is_alive(head);
    usleep(head->time_to_sleep * 1000);
    is_alive(head);
    pthread_mutex_unlock(&head->state->sleeping);
}

int philo_controler(t_list *head)
{
    if (fork_1_check(head) && (fork_2_check(head)))
        return(1);
    else
    {
        if (pthread_mutex_trylock(&head->state->priority) == 0)
        {
            head->state->priority_n += 1;
            pthread_mutex_unlock(&head->state->priority);
            return (0);
        }
        else
        {
            while (pthread_mutex_trylock(&head->state->priority) != 0)
            {
                usleep(1);
            }
            head->state->priority_n += 1;
            pthread_mutex_unlock(&head->state->priority);
            return(0);
        }
    }
    return (0);
}

int  fork_1_check(t_list *head)
{
    if (pthread_mutex_trylock(&head->state->fork) == 0)
    {
        pthread_mutex_unlock(&head->state->fork);
        return (1);
    }
    else
        return(0);
}

int  fork_2_check(t_list *head)
{
    if (pthread_mutex_trylock(&head->next->state->fork) == 0)
    {
        pthread_mutex_unlock(&head->next->state->fork);
        return (1);
    }
    else
        return(0);
}

t_list *target_prio(t_list *head)
{
    t_list *nav = NULL;
    t_list *result = NULL;
    int i;
    unsigned int comparer;

    comparer = 0;
    i = 0;
    nav = head;
    while(i != nav->list_size)
    {
        pthread_mutex_lock(&nav->state->priority);
        if (comparer < nav->state->priority_n)
        {
            comparer = nav->state->priority_n;
            result = nav;
        }
        pthread_mutex_unlock(&nav->state->priority);
        nav = nav->next;
        i++;
    }
    return(result);
}