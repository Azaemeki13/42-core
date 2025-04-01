#ifndef PHILO_H
#   define PHILO_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <pthread.h>
#include <string.h>
#include <time.h>
#include <limits.h>

//Basic structure 

typedef struct s_mutex
{
    pthread_mutex_t fork;
    pthread_mutex_t sleeping;
    pthread_mutex_t thinking;
    pthread_mutex_t priority;
    int fork_init;
    int sleeping_init;
    int thinking_init;
    int priority_init;
    unsigned int priority_n;
}   t_mutex;

typedef struct s_list
{
    struct s_list *next;
    struct s_list *prev;
    int index;
    int list_size;
    pthread_t philosopher;
    t_mutex *state;
    long long time_to_die;
    long long time_to_sleep;
    long long time_to_eat;
    unsigned int requirements;
}   t_list;

// requirements to create the list
char ** char_to_arg(char **argv);
char *format_arg(char **arguments);
void create_node(t_list **head);
int generate_list(t_list **head, char *argument);
void make_it_circular(t_list *head);
void facto_requirements(t_list *nav, unsigned int requirements);
int	ft_atoi(const char *nptr);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *src);
int populate_list (t_list **head, char **arguments);
int populate_requirements(t_list **head, char **arguments);
int populate_timers(t_list **head, char **arguments);
void clear_list(t_list **head);
char	**ft_split(char const *s, char c);
int lst_size(t_list *head);

// Threads & mutexes
void init_mutex(t_list *head);
void *routine(void *arg);
void create_philo(t_list **head);

// routines && time
void philo_miam(t_list *head);
void philo_cogito(t_list *head);
void philo_zzz(t_list *head);
t_list *target_prio(t_list *head);
int philo_controler(t_list *head);
int  fork_1_check(t_list *head);
int  fork_2_check(t_list *head);

#endif