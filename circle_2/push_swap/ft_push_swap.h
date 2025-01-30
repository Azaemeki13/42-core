/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:09:27 by cauffret          #+#    #+#             */
/*   Updated: 2025/01/30 16:39:46 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "./libft/ft_printf/ft_printf.h"
# include "./libft/libft.h"

typedef struct s_list
{
	long			data;
	int				index;
	int				push_price;
	int				cheapest;
	int				above_median;
	struct s_list	*next;
	struct s_list	*prev;
	struct s_list	*target_node;
}					t_list;

void				append_node(t_list **head, t_list *new_node);
int					arg_checker(char **argv);
char				**argv_to_arg(int argc, char **argv);
int					case_checker(t_list **head_a, t_list *b_node);
void 				cheapest_show(t_list *to_show);
void				create_node(t_list **head, char *argv);
int					dup_checker(char **argv);
int					error_checker(char **argv);
void				final_rotate1(t_list **head_a, t_list **head_b, t_list *target_node);
void				final_rotate2(t_list **head_a, t_list **head_b,
						t_list *target_node);
t_list				*find_cheapest(t_list *head_b);
t_list				*find_min(t_list *head);
t_list				*find_target(t_list *head_a, t_list *b_node);
void				free_arguments(char **arguments);
void				free_push(t_list *head);
void				free_stack(t_list *head);
void				f_solving(t_list **head_a, t_list **head_b);
long				ft_atol(const char *nptr);
void				index_refresher(t_list *head);
int					is_sorted(t_list *head_a);
int					limits_checker(const char *nptr);
void				list_cheapest(t_list *head_b);
int					list_size(t_list *head);
t_list				*maxi_value(t_list *head_a, long max_value);
int					minimal_rotation_cost(int i, int len);
t_list				*mini_value(t_list *head_a, long min_value);
void				node_targeting(t_list **head_a, t_list **head_b);
void				overall_refresher(t_list *head_a, t_list *head_b);
int					flow_checker(char **argv);
void				presort(t_list **head_a, t_list **head_b, char **arguments);
int					presort_checker(char **arguments);
void				price_refresher(t_list *head_a, t_list *head_b);
void				print_error(void);
void				push_a(t_list **head_a, t_list **head_b);
void				push_b(t_list **head_a, t_list **head_b);
void 				push_two(t_list **head_a, t_list **head_b);
void				reverse_rotate_a(t_list **head_a);
void				reverse_rotate_all(t_list **head_a, t_list **head_b);
void				reverse_rotate_b(t_list **head_b);
void				rotate_a(t_list **head_a);
void				rotate_all(t_list **head_a, t_list **head_b);
void				rotate_b(t_list **head_b);
void				sort_three(t_list **head_a);
void				sort_two(t_list **head_a);
void				swap_a(t_list *head);
void				swap_all(t_list *head_a, t_list *head_b);
void				swap_b(t_list *head);
void				rotate_before1(t_list **head_a, t_list **head_b, t_list *target_node);
void				rotate_before2(t_list **head_a, t_list **head_b,
						t_list *target_node);
void				rotate_above1(t_list **head_a, t_list **head_b, t_list *target_node);

void				rotate_above2(t_list **head_a, t_list **head_b,
						t_list *target_node);
void 				rota_one(t_list **head_a, t_list **head_b);

void				value_filler(long *min_value, long *max_value,
						t_list *head_a);

// DEBUGING Fx 

void target_show(t_list *to_show);

#endif