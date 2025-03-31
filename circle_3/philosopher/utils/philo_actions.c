/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:28:18 by ituriel           #+#    #+#             */
/*   Updated: 2025/03/31 12:59:56 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long long get_current_mili(void)
{
    long long result;
    struct timeval tv;

    gettimeofday(&tv, NULL);
    result = (long long)tv.tv_sec * 1000LL + tv.tv_usec / 1000LL;

    return (result);
}

void philo_cogito(t_list *head)
{
    if (pthread_mutex_trylock(&head->next->state->fork) != 0)     
    {
        pthread_mutex_lock(&head->state->thinking);
        printf("%lld ms Philosopher %d is thinking\n", get_current_mili(), head->index);
    }
    else
        return ;
    while (pthread_mutex_trylock(&head->next->state->fork) != 0)
        usleep(1);
    pthread_mutex_unlock(&head->state->thinking);     
}

void philo_miam(t_list *head)
{    
    philo_cogito(head);
    printf("%lld ms Philosopher %d has taken right fork.\n",get_current_mili(), head->index);
    while (pthread_mutex_trylock(&head->state->fork) != 0)
        usleep(1);
    printf("%lld ms Philosopher %d has taken left fork.\n", get_current_mili(), head->index);
    printf("%lld ms Philosopher %d is eating\n", get_current_mili(), head->index);
    usleep((head->time_to_eat) * 1000);
    pthread_mutex_unlock(&head->state->fork);
    pthread_mutex_unlock(&head->next->state->fork);
}

void philo_zzz(t_list *head)
{
    if (pthread_mutex_lock(&head->state->sleeping) == 0)
        printf("%lld ms Philosopher %d is sleeping.\n",get_current_mili(), head->index);
    usleep(head->time_to_sleep * 1000);
    pthread_mutex_unlock(&head->state->sleeping);
}