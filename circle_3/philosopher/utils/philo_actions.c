/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:28:18 by ituriel           #+#    #+#             */
/*   Updated: 2025/04/22 16:47:28 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	philo_cogito(t_list *head)
{
	if (!check_full_alive(head))
		return ;
	pthread_mutex_lock(&head->state->thinking);
	print_message(head, "is thinking.");
	pthread_mutex_unlock(&head->state->thinking);
}

void	philo_miam(t_list *head)
{
	while ((check_full_alive(head) == 1))
	{
		is_alive(head);
		if (head->index % 2 == 0)
		{
			pthread_mutex_lock(&head->state->fork);
			pthread_mutex_lock(&head->next->state->fork);
		}
		else
		{
			pthread_mutex_lock(&head->next->state->fork);
			pthread_mutex_lock(&head->state->fork);
		}
		head->last_eat = get_elapsed(head);
		print_eat(head);
		precise_usleep((head->time_to_eat) * 1000);
		pthread_mutex_unlock(&head->state->fork);
		pthread_mutex_unlock(&head->next->state->fork);
		return ;
	}
	return ;
}

void	philo_zzz(t_list *head)
{
	while ((check_full_alive(head) == 1))
	{
		is_alive(head);
		pthread_mutex_lock(&head->state->sleeping);
		if (check_full_alive(head))
			print_message(head, "is sleeping.");
		is_alive(head);
		precise_usleep(head->time_to_sleep * 1000);
		is_alive(head);
		pthread_mutex_unlock(&head->state->sleeping);
		return ;
	}
}
