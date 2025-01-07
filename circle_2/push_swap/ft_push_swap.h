/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:09:27 by cauffret          #+#    #+#             */
/*   Updated: 2025/01/07 14:21:00 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

#include "./libft/libft.h"
#include "./libft/ft_printf/ft_printf.h"

typedef struct s_list
{
	int			data;
    int         digit_count;
	struct s_list	*next;
}					t_list;

typedef struct s_rand_list
{
	int	number;
	struct s_rand_list	*next;
}					t_rand_list;

void  create_node (t_list **head, char *argv);
int comparer (t_list *head);
void free_push(t_list *head);
void free_stack(t_list *head);
void index_refresher(t_list **head);
void list_generator (t_rand_list **head, int max_number);
void list_sorter( t_list **head_a, t_list **head_b);
int numeric_convertor(unsigned long long n);
t_rand_list *rand_list(int number_a);
int pass_amount( t_list *head_a);
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