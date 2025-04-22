/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_annex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:36:31 by cauffret          #+#    #+#             */
/*   Updated: 2025/04/07 10:49:15 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void facto_requirements(t_list *nav, unsigned int requirements)
{
    t_list *temp;

    temp = nav;
    while (temp)
    {
        temp->requirements = (unsigned int) requirements;
        init_mutex(temp);
        temp = temp->next;
    }
}

void make_it_circular(t_list *head)
{
    t_list *temp = NULL;

    temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = head;
    head->prev = temp;
}
