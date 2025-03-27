/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:36:31 by cauffret          #+#    #+#             */
/*   Updated: 2025/03/27 15:36:14 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void wait_init(t_list *head)
{
    usleep(50 * ((head->list_size) - (head->index)));
}

void *routine(void *arg)
{
    t_list *list = (t_list *)arg;
    wait_init(list);
    while (list->requirements != 0)
    {
        philo_miam(head);
        philo_cogito(head);
        philo_zzz(head);
        requirements;
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