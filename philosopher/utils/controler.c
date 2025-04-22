/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:32:05 by cauffret          #+#    #+#             */
/*   Updated: 2025/04/22 15:23:00 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void precise_usleep(long long micro)
{
    long long start;
    
    start = get_current_mili();
    while (get_current_mili()  != start + (micro / 1000LL))
        ;
    return ;
}

void *contro_routine(void * arg)
{
    t_list *list;
    t_list *temp;
    
    list = (t_list *)arg;
   while (1)
   {
    temp = list;
    if (!contro_helper(temp))
        return (NULL);
    if (contro_helper2(temp) == 0)
        return (NULL);
    if (list->prev->requirements == 0)
        return (NULL);
    usleep(5);
   }
    return NULL;
}

int contro_helper(t_list *arg)
{
    t_list *temp = NULL;
    int remaining;
    int i;

    remaining = 0;
    i = 0;
    temp = arg;
    while (i < temp->list_size)
    {
        if (temp->requirements > 0)
            ++ remaining;
        temp = temp->next;
        i++;
    }
    if (remaining == 0)
        return (0);
    else
        return (1);
}

int contro_helper2(t_list *list)
{
    int i;
    t_list *temp = NULL;

    i = 0;
    temp = list;
    while(i < list->list_size)
    {
        if (temp->requirements > 0)
        {
            is_alive(temp);
            if (!temp->living_state)
            return 0;
        }
        temp = temp->next;
        i++;
    }
    return (1);
}
