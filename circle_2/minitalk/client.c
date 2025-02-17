/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:48:11 by root              #+#    #+#             */
/*   Updated: 2025/02/17 16:42:49 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mini_talk.h"

void char_to_sig(char c, pid_t pid)
{
    int i;
    char uc;

    uc = (unsigned char)c;
    i = 0;
    while (i < 8)
    {
        if (uc & 1)
            kill(pid, SIGUSR2);
        else
            kill(pid, SIGUSR1);
        uc >>= 1;
        i++;
        usleep(50);
    }
}

void str_to_sig(char *str,  pid_t pid)
{
    signed int i;

    i = 0;
    while(*str)
    {
        char_to_sig(*str, pid);
        str++;
    }
    while (i < 8)
    {
        kill(pid, SIGUSR1);
        usleep(50);
        i++;
    }
}
int main (int argc, char **argv)
{
    pid_t pid;
    
    if (!error_checker(argc, argv))
        return (0);
    pid = (pid_t)ft_atol(argv[1]);
    str_to_sig(argv[2], pid);
    return(0);
}
