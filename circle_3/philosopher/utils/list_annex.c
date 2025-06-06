/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_annex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:36:31 by cauffret          #+#    #+#             */
/*   Updated: 2025/04/22 16:36:49 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	facto_requirements(t_list *nav, unsigned int requirements)
{
	t_list	*temp;

	temp = nav;
	while (temp)
	{
		temp->requirements = (unsigned int)requirements;
		init_mutex(temp);
		temp = temp->next;
	}
}

void	make_it_circular(t_list *head)
{
	t_list	*temp;

	temp = NULL;
	temp = head;
	while (temp->next)
		temp = temp->next;
	temp->next = head;
	head->prev = temp;
}

int	lst_size(t_list *head)
{
	t_list	*nav;
	int		i;

	nav = head;
	i = 0;
	while (nav != head->prev)
	{
		i++;
		nav = nav->next;
	}
	return (i);
}
