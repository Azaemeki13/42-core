/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:29:14 by cauffret          #+#    #+#             */
/*   Updated: 2025/04/22 16:58:50 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdatomic.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <time.h>
# include <unistd.h>

// Basic structure

typedef struct s_shared
{
	pthread_mutex_t	message;
}					t_shared;

typedef struct s_mutex
{
	pthread_mutex_t	fork;
	pthread_mutex_t	sleeping;
	pthread_mutex_t	thinking;
	int				fork_init;
	int				sleeping_init;
	int				thinking_init;
}					t_mutex;

typedef struct s_list
{
	struct s_list	*next;
	struct s_list	*prev;
	int				index;
	int				list_size;
	pthread_t		philosopher;
	pthread_t		controler;
	t_mutex			*state;
	t_shared		*message;
	long long		time_to_die;
	long long		time_to_sleep;
	long long		time_to_eat;
	long long		start_time;
	long long		last_eat;
	_Atomic int		living_state;
	unsigned int	requirements;
}					t_list;

// requirements to create the list && clear
char				**char_to_arg(char **argv);
char				*format_arg(char **arguments);
void				create_node(t_list **head, t_shared *message);
int					generate_list(t_list **head, char *argument,
						t_shared *message);
void				make_it_circular(t_list *head);
void				facto_requirements(t_list *nav, unsigned int requirements);
int					ft_atoi(const char *nptr);
void				*ft_memset(void *ptr, int value, size_t num);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *src);
int					populate_list(t_list **head, char **arguments,
						t_shared *message);
int					populate_requirements(t_list **head, char **arguments);
int					populate_timers(t_list **head, char **arguments);
void				clear_list(t_list **head, t_shared *message);
char				**ft_split(char const *s, char c);
int					lst_size(t_list *head);
void				short_clear(t_list *last);

// Threads & mutexes
void				init_mutex(t_list *head);
void				*routine(void *arg);
void				create_philo(t_list **head, t_shared *message);
void				print_message(t_list *list, const char *message);
void				print_eat(t_list *list);
void				wait_init(void);

// routines && time
void				philo_miam(t_list *head);
void				philo_cogito(t_list *head);
void				philo_zzz(t_list *head);
t_list				*target_prio(t_list *head);
long long			get_current_mili(void);
void				start_time(t_list *head);
long long			get_elapsed(t_list *head);
void				is_alive(t_list *head);
int					check_alive(t_list *head);
void				wait_forks(t_list *head);
void				*contro_routine(void *arg);
t_list				*find_last(t_list *list);
void				precise_usleep(long long micro);
int					check_full_alive(t_list *head);
int					contro_helper(t_list *arg);
int					contro_helper2(t_list *list);

#endif