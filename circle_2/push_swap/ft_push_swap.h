/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:09:27 by cauffret          #+#    #+#             */
/*   Updated: 2024/12/30 19:00:21 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

#include "./libft/libft.h"
#include "./libft/ft_printf/ft_printf.h"

typedef struct s_list
{
	int			data;
    int         index;
	struct s_list	*next;
}					t_list;

void  create_node (t_list **head, char *argv);
void free_push(t_list *head);
void free_stack(t_list *head);
void index_refresher(t_list **head);
void push_a(t_list **head_a, t_list **head_b);
void push_b(t_list **head_a, t_list **head_b);
void swap_a (t_list *head);
void swap_b (t_list *head);


# endif