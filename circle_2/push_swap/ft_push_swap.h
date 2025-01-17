/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:09:27 by cauffret          #+#    #+#             */
/*   Updated: 2025/01/17 16:40:42 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

#include "./libft/libft.h"
#include "./libft/ft_printf/ft_printf.h"

typedef struct s_list
{
	long			data;
	struct s_list	*next;
	struct s_list	*prev;
	struct s_list	*target_node;
}					t_list;

void append_node(t_list **head, t_list *new_node);
int arg_checker (char **argv);
char **argv_to_arg(int argc, char **argv);
void  create_node (t_list **head, char *argv);
int dup_checker (char **argv);
int error_checker (char **argv);
t_list *find_highest_node(t_list *head);
void free_arguments(char **arguments);
void free_push(t_list *head);
void free_stack(t_list *head);
long	ft_atol(const char *nptr);
int is_sorted(t_list *head_a);
int limits_checker (const char *nptr);
int flow_checker (char **argv);
void print_error();
void push_a(t_list **head_a, t_list **head_b);
void push_b(t_list **head_a, t_list **head_b);
void reverse_rotate_a(t_list **head_a);
void reverse_rotate_b(t_list **head_b);
void rotate_a(t_list **head_a);
void rotate_b(t_list **head_b);
void sort_three(t_list **head_a);
void swap_a (t_list *head);
void swap_all (t_list *head_a, t_list *head_b);
void swap_b (t_list *head);


# endif