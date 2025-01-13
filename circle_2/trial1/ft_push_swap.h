/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:31:46 by cauffret          #+#    #+#             */
/*   Updated: 2025/01/09 15:47:01 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_PUSH_SWAP_H 
# define FT_PUSH_SWAP_H

#include "./ft_printf/ft_printf.h"
#include "./ft_printf/libft/libft.h"

typedef struct s_list
{
int     data;
struct s_list *next;
struct s_list *prev;
}   t_list;

long	ft_atol(const char *nptr);
static int	ft_isspace(int c);
static void	ft_right_place(int *i, const char *nptr, int *f);


# endif