/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:26:42 by ituriel           #+#    #+#             */
/*   Updated: 2024/11/06 11:45:32 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_s (va_list args)
{
    char *str;

    str = va_arg(args,char*);
    if (str == NULL)
        str ="(null)";
    ft_putstr_fd(str, 1);
    return(ft_strlen(str));
}