/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:36:31 by cauffret          #+#    #+#             */
/*   Updated: 2025/04/07 15:10:30 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void create_node(t_list **head)
{
    t_list *new_node = NULL;
    t_list *nav = NULL;
    t_shared *message = NULL;
    pthread_t controler;

    new_node = malloc(sizeof(t_list));
    ft_memset(new_node, 0,sizeof(t_list));
    new_node->state = malloc(sizeof(t_mutex));
    message = malloc(sizeof(t_shared));
    pthread_mutex_init(&message->message, NULL);
    new_node->message = message;
    new_node->controler = controler;
    ft_memset(new_node->state, 0, sizeof(t_mutex));
    if (!*head)
        (*head) = new_node;
    else
    {
        nav = (*head);
        while (nav->next)
            nav = nav->next;
        nav->next = new_node;
        new_node->prev = nav;
    }
}

int generate_list(t_list **head, char *argument)
{
    int i;

    i = ft_atoi(argument);
    if (i < 1)
    {
        printf("Please at least one philo on table. \n");
        return (0);
    }
    while (i != 0)
    {
        create_node(head);
        i--;
    }
    return (1);
}

int populate_timers(t_list **head, char **arguments)
{
    t_list *nav = NULL;
    int j;

    j = 0;
    arguments++;
    nav = (*head);
    if ((ft_atoi(arguments[0])) < 0 || (ft_atoi(arguments[1]) < 0) 
        || (ft_atoi(arguments[2])) < 0)
    {
        printf("Please enter proper timers. \n");
        return (0);
    }
    while (nav)
    {
        nav->index = j++;
        nav->list_size = lst_size(*head);
        nav->time_to_die = (long long)ft_atoi(arguments[0]);
        nav->time_to_eat = (long long)ft_atoi(arguments[1]);
        nav->time_to_sleep = (long long)ft_atoi(arguments[2]);
        nav = nav->next;
    }
    return(1);
}

int populate_requirements(t_list **head, char **arguments)
{
    t_list *nav = NULL;
    int requirements;
    int f;

    f = 4;
    while(f != 0)
    {
        arguments++;
        f--;
    }
    nav = (*head);
    if (!*arguments)
        requirements = 5;
    else
    {
        requirements = ft_atoi((*arguments));
        if (requirements <= 0)
        {
            printf("Please enter smart requirements :). \n");
            return (0);
        }
    }
    facto_requirements(nav, requirements);
    return(1);
}

int populate_list (t_list **head, char **arguments)
{
    if (generate_list(head, *(arguments)) == 0
    || (populate_timers(head, arguments) == 0) 
    || (populate_requirements(head, arguments) == 0))
    {
        clear_list(head);
        return(0);
    }
    make_it_circular(*head);
    return (1);
}

int lst_size(t_list *head)
{
    t_list *nav;
    int i;

    nav = head;
    i = 0;
    
    while(nav != head->prev)
    {
        i++;
        nav = nav->next;
    }
    return(i); 
}