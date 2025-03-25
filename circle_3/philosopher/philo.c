/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:46:50 by cauffret          #+#    #+#             */
/*   Updated: 2025/03/25 18:13:51 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char ** char_to_arg(char **argv)
{
    char **result;
    result = ft_split(argv[1], ' ');
    return (result);
}

int main(int argc, char **argv)
{
    t_list *head = NULL;
    char ** ynk;
    if (argc == 2 )
    {
        ynk = char_to_arg(argv);
        populate_list(&head, ynk);
    }
    else if (argc < 5 || argc > 6 )
        return(1);
    argv++;
    populate_list(&head,argv);
    t_list *nav = head;
    while (nav)
    {
        printf("List [Index : %d, t2d %ld, t2e %ld, t2s %ld, requirements %d]\n", nav->index,nav->time_to_die, nav->time_to_eat,nav->time_to_sleep, nav->requirements);
        nav = nav->next;
    }
}