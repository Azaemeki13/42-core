/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_annex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:36:31 by cauffret          #+#    #+#             */
/*   Updated: 2025/03/25 16:55:26 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void facto_requirements(t_list *nav, unsigned int requirements)
{
    while (nav)
    {
        nav->requirements = (unsigned int) requirements;
        nav = nav->next;
    }
}