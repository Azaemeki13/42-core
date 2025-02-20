/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:48:11 by root              #+#    #+#             */
/*   Updated: 2025/02/20 15:31:04 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mini_talk.h"

volatile sig_atomic_t	g_ack = 0;

void	ack_handler(int signum)
{
	(void)signum;
	g_ack = 1;
}

void	char_to_sig(char c, pid_t pid)
{
	int	i;
	int	uc;

	uc = c;
	i = 0;
	while (i < 8)
	{
		if ((uc >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		i++;
		while (!g_ack)
			pause();
		g_ack = 0;
		usleep(20);
	}
}

void	str_to_sig(char *str, pid_t pid)
{
	signed int	i;

	i = 0;
	while (*str)
	{
		char_to_sig(*str, pid);
		str++;
	}
	while (i < 8)
	{
		kill(pid, SIGUSR1);
		while (!g_ack)
			pause();
		g_ack = 0;
		i++;
	}
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	struct sigaction	sa;

	sa.sa_flags = 0;
	sa.sa_handler = ack_handler;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	if (!error_checker(argc, argv))
		return (0);
	pid = (pid_t)ft_atol(argv[1]);
	str_to_sig(argv[2], pid);
	return (0);
}
