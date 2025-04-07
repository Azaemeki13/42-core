/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:32:05 by cauffret          #+#    #+#             */
/*   Updated: 2025/04/07 14:30:09 by cauffret         ###   ########.fr       */
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

t_list *find_last(t_list *list)
{
    while (list->index != (list->list_size - 1))
        list = list->next;
    return(list->next);
}

void *contro_routine(void * arg)
{
    t_list *list;
    t_list *temp;
    int i;
    
    list = (t_list *)arg;
    temp = list;
    i = 0;
    while((find_last(list))->requirements != 0)
    {
        i = 0;
        while(i != temp->list_size)
        {
            is_alive(temp);
            if ((!check_alive(temp)))
                return ;
            temp = temp->next;
        }
        precise_usleep(5000);
    }
    return ;
}
