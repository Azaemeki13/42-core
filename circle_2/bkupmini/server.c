/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:48:14 by root              #+#    #+#             */
/*   Updated: 2025/02/17 16:38:18 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mini_talk.h"

static void bit_handler(int signum, siginfo_t *info, void *context)
{
    static int bit_count = 0;
    static char current_char = 0;

    (void)context;

    // Process bit
    if (signum == SIGUSR2)
        current_char |= (1 << bit_count);
    bit_count++;

    // Send ACK for this bit immediately

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
    kill( info->si_pid, SIGUSR1);
}


int main(void)
{
    struct sigaction sa;
    
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = bit_handler;
    sigemptyset(&sa.sa_mask);
    // Block both SIGUSR1 and SIGUSR2 during execution of the handler
    sigaddset(&sa.sa_mask, SIGUSR1);
    sigaddset(&sa.sa_mask, SIGUSR2);
    
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    
    ft_printf("PID: %d\n", getpid());
    while (1)
        usleep(50);
    return (0);
}
