/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:46:50 by cauffret          #+#    #+#             */
/*   Updated: 2025/04/01 11:18:56 by cauffret         ###   ########.fr       */
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
    else
    {
        argv++;
        populate_list(&head,argv);
    }
    if (!head)
        return(0);
    create_philo(&head);
}