/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:19:04 by root              #+#    #+#             */
/*   Updated: 2025/01/15 11:16:05 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

int arg_checker (char **argv)
{
    int i;
    int j;

    i = 0;
    while (argv[i])
    {
        j = 0;
        while (argv[i][j])
        {
            if (j == 0 && (argv[i][j] == '-'))
                j++;
            if (!ft_isdigit(argv[i][j]))
            {
                return (0);
            }
            j++;
        }
        i++;
    }
    return(1);
}

int limits_checker (const char *nptr)
{
    long long i;
    
    i = ft_atol(nptr);
    if (i < LONG_MIN || i > LONG_MAX)
    {
        return (0);
    }
    return (1);
}

int flow_checker (char **argv)
{
    int i;

    i = 0;
    while (argv[i])
    {
        if(!limits_checker(argv[i]))
            return (0);
        i++;
    }
    return (1);
}

int dup_checker (char **argv)
{
    int i;
    int j;
    
    i = 0;
    while (argv[i])
    {
        j = i + 1;
        while (argv[j])
        {
            if (ft_strcmp(argv[i], argv[j]) == 0)
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

int error_checker (char **argv)
{
    if (!arg_checker(argv))
    {
     return (0);   
    }
    ft_printf("No issue with arg checker\n");
    if (!flow_checker(argv))
    {
        return (0);
    }
    ft_printf("No issue with flow checker\n");
    if (!dup_checker(argv))
        {
            return (0);
        }
    ft_printf("No issue with dup checker\n");
    return (1);
}
