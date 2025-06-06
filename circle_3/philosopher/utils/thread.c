/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:36:31 by cauffret          #+#    #+#             */
/*   Updated: 2025/05/06 11:44:47 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	init_mutex(t_list *list)
{
	list->state->fork_init = pthread_mutex_init(&list->state->fork, NULL);
	list->state->sleeping_init = pthread_mutex_init(&list->state->sleeping,
			NULL);
	list->state->thinking_init = pthread_mutex_init(&list->state->thinking,
			NULL);
}

void	*routine(void *arg)
{
	t_list	*list;

	list = (t_list *)arg;
	list->last_eat = get_elapsed(list);
	wait_init();
	while (list->requirements > 1 && check_full_alive(list))
	{
		list->requirements--;
		philo_miam(list);
		philo_zzz(list);
		philo_cogito(list);
		if (!check_full_alive(list))
			return (NULL);
	}
	if (list->living_state)
	{
		philo_miam(list);
		philo_zzz(list);
		list->requirements--;
		if (!check_full_alive(list))
			return (NULL);
	}
	return (NULL);
}

void	print_message(t_list *list, const char *message)
{
	pthread_mutex_lock(&list->message->message);
	if (check_full_alive(list))
		printf("%lld Philosopher %d %s\n", get_elapsed(list), list->index,
			message);
	pthread_mutex_unlock(&list->message->message);
}

void	print_eat(t_list *list)
{
	pthread_mutex_lock(&list->message->message);
	if (check_full_alive(list))
	{
		printf("%lld Philosopher %d has taken a fork.\n", get_elapsed(list),
			list->index);
		printf("%lld Philosopher %d has taken a fork.\n", get_elapsed(list),
			list->index);
		printf("%lld Philosopher %d is eating.\n", get_elapsed(list),
			list->index);
	}
	pthread_mutex_unlock(&list->message->message);
}

void	create_philo(t_list **head, t_shared *message)
{
	t_list	*nav;
	int		list_size;
	int		i;

	i = 0;
	nav = (*head);
	list_size = lst_size(*head) + 1;
	while (i != list_size)
	{
		pthread_create(&nav->philosopher, NULL, routine, nav);
		if (i == 0)
			pthread_create(&nav->controler, NULL, contro_routine, nav);
		nav = nav->next;
		i++;
	}
	i = 0;
	nav = (*head);
	while (i != list_size)
	{
		pthread_join(nav->philosopher, NULL);
		nav = nav->next;
		i++;
	}
	pthread_join(nav->controler, NULL);
	clear_list(head, message);
}
