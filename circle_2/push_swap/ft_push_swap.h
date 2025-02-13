/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:09:27 by cauffret          #+#    #+#             */
/*   Updated: 2025/02/13 13:14:44 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "./libft/ft_printf/ft_printf.h"
# include "./libft/libft.h"

typedef enum rotation
{
	ROT_RR,
	ROT_RRR,
	ROT_RA_RRB,
	ROT_RRA_RB
}					t_rot_mode;

typedef struct s_list
{
	long			data;
	int				index;
	int				push_price;
	t_rot_mode		rotation;
	int				cheapest;
	int				above_median;
	struct s_list	*next;
	struct s_list	*prev;
	struct s_list	*target_node;
}					t_list;

void				after_three(t_list **head_a, t_list **head_b);
void				all_done(t_list **head_a, t_list **head_b);
void				append_node(t_list **head, t_list *new_node);
int					arg_checker(char **argv);
char				**argv_to_arg(int argc, char **argv);
t_list				*arg_to_node(char **arguments, t_list *stack_a);
t_list				*bigger_smallest(t_list *from, t_list *to);
t_list				*smallest_bigger(t_list *from, t_list *to);
int					case_checker(t_list **head_a, t_list *b_node);
void				compute_loop(int *a, int *b, t_rot_mode *mode);
int					compute_rotation_cost(t_list *current_node, int len_a,
						int len_b, t_rot_mode *mode);
void				create_node(t_list **head, char *argv);
int					dup_checker(char **argv);
int					error_checker(char **argv);
t_list				*find_cheapest(t_list *head);
t_list				*find_min(t_list *head);
t_list				*find_target(t_list *to, t_list *from);
t_list				*find_target_2(t_list *to, t_list *from);
void				free_all(t_list **head_a, t_list **head_b,
						char **arguments);
void				free_arguments(char **arguments);
void				free_stack(t_list **head);
void				f_solving(t_list **head_a, t_list **head_b);
long				ft_atol(const char *nptr);
int					ft_max(int a, int b);
void				index_refresher(t_list *head);
int					is_sorted(t_list *head);
int					limits_checker(const char *nptr);
void				list_cheapest(t_list *head_b);
int					list_size(t_list *head);
t_list				*maxi_value(t_list *to, long max_value);
t_list				*mini_value(t_list *to, long min_value);
void				node_targeting(t_list **to, t_list **from);
void				node_targeting2(t_list **to, t_list **from);
void				overall_refresher(t_list *head_a, t_list *head_b);
int					flow_checker(char **argv);
void				perform_rot_rr(t_list **head_a, t_list **head_b,
						t_list *from);
void				perform_rot_rrr(t_list **head_a, t_list **head_b,
						t_list *from);
void				perform_rot_ra_rrb(t_list **head_a, t_list **head_b,
						t_list *from);
void				perform_rot_rra_rb(t_list **head_a, t_list **head_b,
						t_list *from);
void				perform_rot_rr2(t_list **head_a, t_list **head_b,
						t_list *from);
void				perform_rot_rrr2(t_list **head_a, t_list **head_b,
						t_list *from);
void				perform_rot_ra_rrb2(t_list **head_a, t_list **head_b,
						t_list *from);
void				perform_rot_rra_rb2(t_list **head_a, t_list **head_b,
						t_list *from);
void				presort(t_list **head_a, t_list **head_b, char **arguments);
int					presort_checker(char **arguments);
void				print_error(void);
void				print_free_error(char **arguments);
void				push_a(t_list **head_a, t_list **head_b);
void				push_b(t_list **head_a, t_list **head_b);
void				push_to_three(t_list **head_a, t_list **head_b);
void				push_two(t_list **head_a, t_list **head_b);
void				refresh_rota_cost(t_list *head_a, t_list *head_b,
						t_list *from);
void				reverse_rotate_a(t_list **head_a);
void				reverse_rotate_a_all(t_list **head_a);
void				reverse_rotate_b_all(t_list **head_b);
void				reverse_rotate_all(t_list **head_a, t_list **head_b);
void				reverse_rotate_b(t_list **head_b);
void				rotate_a(t_list **head_a);
void				rotate_a_to_b(t_list **head_a, t_list **head_b,
						t_list *current_node);
void				rotate_b_to_a(t_list **head_a, t_list **head_b,
						t_list *current_node);
void				rotate_a_all(t_list **head_a);
void				rotate_b_all(t_list **head_b);
void				rotate_all(t_list **head_a, t_list **head_b);
void				rotate_b(t_list **head_b);
void				rota_cost2(t_list *head_b);
void				set_nul(t_list **head, t_list *new_node);
void				sort_4(t_list **head_a, t_list **head_b);
void				sort_three(t_list **head_a);
void				sort_two(t_list **head_a);
void				swap_a(t_list **head);
void				swap_a_all(t_list **head);
void				swap_all(t_list **head_a, t_list **head_b);
void				swap_b(t_list **head);
void				swap_b_all(t_list **head);
void				value_filler(long *min_value, long *max_value, t_list *to);

#endif