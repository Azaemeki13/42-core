/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:46:50 by cauffret          #+#    #+#             */
/*   Updated: 2025/04/22 16:28:42 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char	**char_to_arg(char **argv)
{
	char	**result;

	result = ft_split(argv[1], ' ');
	return (result);
}

t_shared	*message_init(void)
{
	t_shared	*message;

	message = NULL;
	message = malloc(sizeof(t_shared));
	pthread_mutex_init(&message->message, NULL);
	return (message);
}

int	main(int argc, char **argv)
{
	t_list		*head;
	t_shared	*message;
	char		**ynk;

	head = NULL;
	message = NULL;
	if (argc == 2)
	{
		ynk = char_to_arg(argv);
		message = message_init();
		populate_list(&head, ynk, message);
	}
	else if (argc < 5 || argc > 6)
		return (1);
	else
	{
		argv++;
		message = message_init();
		populate_list(&head, argv, message);
	}
	if (!head)
		return (0);
	start_time(head);
	create_philo(&head, message);
}
