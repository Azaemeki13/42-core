/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:48:14 by root              #+#    #+#             */
/*   Updated: 2025/02/17 16:44:49 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mini_talk.h"

static void bit_handler(int signum)
{
    static int bit_count = 0;
    static char current_char = 0;

    if (signum == SIGUSR2)
        current_char |= (1 << bit_count);
    bit_count++;

    if (bit_count == 8)
    {
        if (current_char == '\0')
        {
            write(1, "\n", 1);
        }
        else
            write(1, &current_char, 1);
        
        current_char = 0;
        bit_count = 0;
    }
}


int main(void)
{
    struct sigaction sa;
    
    sa.sa_flags = 0;
    sa.sa_handler = bit_handler;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    
    ft_printf("PID: %d\n", getpid());
    while (1)
        usleep(50);
    return (0);
}
