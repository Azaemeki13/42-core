/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 10:58:25 by ituriel           #+#    #+#             */
/*   Updated: 2025/04/06 14:36:27 by ituriel          ###   ########.fr       */
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

void start_time(t_list *head)
{
    long long start_time;
    int i;

    i = 0;
    start_time = get_current_mili();
    while (i < head->list_size)
    {
        head->start_time = start_time;
        head = head->next;
        i++;
    }
}
long long get_elapsed(t_list *head)
{
    return((get_current_mili() - head->start_time));
}

void is_alive(t_list *head)
{
    long long elapsed;
    int i;

    i = 0;
    elapsed = get_elapsed(head);
    if (elapsed >= head->last_eat + head->time_to_die)
    {
        while (i != head->list_size)
        {
            head->living_state = 0;
            head = head->next;
            i++;
        }
    }
    else
        head->living_state = 1;
}

int check_alive(t_list *head)
{
    if (!head->living_state)
    {
        printf("A philosopher died.\n");
        return (0);
    }
    else
        return(1);
}