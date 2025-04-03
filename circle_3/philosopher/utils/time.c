/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 10:58:25 by ituriel           #+#    #+#             */
/*   Updated: 2025/04/03 11:12:04 by ituriel          ###   ########.fr       */
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

