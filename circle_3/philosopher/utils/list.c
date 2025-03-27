/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:36:31 by cauffret          #+#    #+#             */
/*   Updated: 2025/03/27 16:22:38 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void create_node(t_list **head)
{
    t_list *new_node = NULL;
    t_list *nav = NULL;

    new_node = malloc(sizeof(t_list));
    memset(new_node, 0,sizeof(t_list));
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
    make_it_circular(*head);
    return (1);
}

int populate_timers(t_list **head, char **arguments)
{
    t_list *nav = NULL;
    int i;

    i = 0;
    nav = (*head);
    if ((ft_atoi(arguments[0])) < 0 || (ft_atoi(arguments[1]) < 0) 
        || (ft_atoi(arguments[2])) < 0)
    {
        printf("Please enter proper timers. \n");
        return (0);
    }
    while (nav != (*head)->prev)
    {
        nav->index = i++;
        nav->time_to_die = (time_t)ft_atoi(arguments[0]);
        nav->time_to_eat = (time_t)ft_atoi(arguments[1]);
        nav->time_to_sleep = (time_t)ft_atoi(arguments[2]);
        nav = nav->next;
    }
    return(1);
}

int populate_requirements(t_list **head, char **arguments)
{
    t_list *nav = NULL;
    int requirements;
    int f;

    f = 3;
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
    arguments++;
    if (generate_list(head, *(arguments)) == 0
    || (populate_timers(head, arguments) == 0) 
    || (populate_requirements(head, arguments) == 0))
    {
        printf("Please enter right parameters. \n");
        clear_list(head);
        return(0);
    }
    return (1);
}
