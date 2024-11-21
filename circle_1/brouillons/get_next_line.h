/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:37:17 by ituriel           #+#    #+#             */
/*   Updated: 2024/11/21 11:28:03 by ituriel          ###   ########.fr       */
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
#  define BUFFER_SIZE 7
# endif

typedef struct s_list
{
	char			*str_buf;
	struct s_list	*next;
}					t_list;
char				*get_next_line(int fd);
void				append_node(t_list **head, t_list *new);
t_list				*new_node(char *buffer, ssize_t size);
size_t				ft_strlen(const char *str);
size_t				length_to_nl(t_list **head);
char				*copy_line(t_list **head, size_t total_length);
char				*ft_strchr(const char *s, int c);
int					newline_found(t_list **head);
void				clean_up_list(t_list **head, size_t consumed_length);
void				*ft_memmove(void *dest, const void *src, size_t n);


#endif