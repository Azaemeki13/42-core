/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 11:23:58 by ituriel           #+#    #+#             */
/*   Updated: 2025/12/16 12:12:05 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
    #define EASYFIND_TPP

template <typename T> 
typename T::iterator easyfind(T &container, int value)
{
    if(container.size() == 0)
        throw sizeZero();
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw notFound();
    return it;
}
#endif