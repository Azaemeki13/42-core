/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:09:27 by cauffret          #+#    #+#             */
/*   Updated: 2025/01/06 13:12:49 by ituriel          ###   ########.fr       */
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
void reverse_rotate_a(t_list **head_a);
void reverse_rotate_b(t_list **head_b);
void rotate_a(t_list **head_a);
void rotate_b(t_list **head_b);
void swap_a (t_list *head);
void swap_all (t_list *head_a, t_list *head_b);
void swap_b (t_list *head);


# endif