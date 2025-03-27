#ifndef PHILO_H
#   define PHILO_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <pthread.h>
#include <string.h>
#include <time.h>

//Basic structure 

typedef struct s_mutex
{
    pthread_mutex_t fork;
    pthread_mutex_t sleeping;
    pthread_mutex_t thinking;
    int fork_init;
    int sleeping_init;
    int thinking_init;
}   t_mutex;

typedef struct s_list
{
    struct s_list *next;
    struct s_list *prev;
    int index;
    int list_size;
    pthread_t philosopher;
    t_mutex *state;
    time_t time_to_die;
    time_t time_to_sleep;
    time_t time_to_eat;
    unsigned int requirements;
}   t_list;

// requirements to create the list
char ** char_to_arg(char **argv);
void create_node(t_list **head);
int generate_list(t_list **head, char *argument);
void make_it_circular(t_list *head);
void facto_requirements(t_list *nav, unsigned int requirements);
int	ft_atoi(const char *nptr);
int populate_list (t_list **head, char **arguments);
int populate_requirements(t_list **head, char **arguments);
int populate_timers(t_list **head, char **arguments);
void clear_list(t_list **head);
char	**ft_split(char const *s, char c);
int lst_size(t_list *head);

// Threads & mutexes
void init_mutex(t_list **head);
void *routine(void *arg);
void create_pĥilo(t_list **head);

#endif