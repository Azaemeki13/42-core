/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:09:27 by cauffret          #+#    #+#             */
/*   Updated: 2024/12/13 17:11:27 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H
typedef struct s_list
{
	int			*data;
    int         *index;
	struct s_list	*next;
}					t_list;

# endif