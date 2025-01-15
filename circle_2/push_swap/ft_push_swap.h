/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:09:27 by cauffret          #+#    #+#             */
/*   Updated: 2025/01/15 11:12:17 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

#include "./libft/libft.h"
#include "./libft/ft_printf/ft_printf.h"

typedef struct s_list
{
	int			data;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

void append_node(t_list **head, t_list *new_node);
int arg_checker (char **argv);
char **argv_to_arg(int argc, char **argv);
void  create_node (t_list **head, char *argv);
int dup_checker (char **argv);
int error_checker (char **argv);
void free_push(t_list *head);
void free_stack(t_list *head);
long	ft_atol(const char *nptr);
int limits_checker (const char *nptr);
int flow_checker (char **argv);
void print_error();
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