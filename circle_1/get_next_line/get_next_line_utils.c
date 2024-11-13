/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:56:56 by ituriel           #+#    #+#             */
/*   Updated: 2024/11/13 12:06:20 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *big_storage(char *buffer, int *i)
{
    int d = 0;

    (*i)++;  // Move to the character after '\n'
    
    // Shift remaining characters in buffer to the beginning
    while (buffer[*i] != '\0') {
        buffer[d] = buffer[*i];
        d++;
        (*i)++;
    }
    buffer[d] = '\0';  // Null-terminate at the end of the shifted content
    
    // Reset *i to the length of the leftover data
    *i = d;
    return buffer;
}