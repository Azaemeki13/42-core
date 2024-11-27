/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:44:24 by ituriel           #+#    #+#             */
/*   Updated: 2024/11/21 14:15:29 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_list
{
	char			*str_buf;
	struct s_list	*next;
}					t_list;

void				buffer_to_stash(t_list **head, int fd);
int					newline_found(t_list *head);
void				append_node(t_list **head, char *buffer);
char				*rl_creator(t_list *head);
size_t				length_to_nl(t_list *head);
void				stash_to_line(t_list *head, char *return_line);
void				refresh_list(t_list **list);
t_list				*head_pos(t_list *list);
void				cleanup_list(t_list **list, t_list *new_node, char *buffer);
char				*get_next_line(int fd);

#endif
