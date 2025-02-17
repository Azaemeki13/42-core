#ifndef MINI_TALK_H
# define MINI_TALK_H

# include "./libft/ft_printf/ft_printf.h"
# include "./libft/libft.h"
# include <signal.h>
# include <sys/types.h>

// client side
void ack_handler(int signum);
void char_to_sig(char c, pid_t pid);
int error_checker(int argc, char **argv);
long	ft_atol(const char *nptr);
void str_to_sig(char *str, pid_t pid);

// server side


#endif