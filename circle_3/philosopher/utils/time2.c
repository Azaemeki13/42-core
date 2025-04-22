/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:32:21 by cauffret          #+#    #+#             */
/*   Updated: 2025/04/22 16:59:08 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_alive(t_list *head)
{
	t_list	*temp;

	temp = head;
	if (!temp->living_state)
		return (0);
	else
		return (1);
}

int	check_full_alive(t_list *head)
{
	t_list	*temp;
	int		i;

	temp = head;
	i = 0;
	while (i != temp->list_size)
	{
		if (!temp->living_state)
			return (0);
		else
			temp = temp->next;
		i++;
	}
	return (1);
}

void	wait_init(void)
{
	usleep(100);
}
