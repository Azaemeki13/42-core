/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 10:05:14 by ituriel           #+#    #+#             */
/*   Updated: 2025/12/15 10:32:28 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
    #define ITER_HPP

#include <iostream>
#include <string>
#include <cstddef>

template <typename T>
void iter(const T *array, const std::size_t length, void (*f)(T const &))
{
    for (std::size_t i = 0; i < length ; i++)
        f(array[i]);
}
template <typename T>
void iter(T *array, const std::size_t length, void (*f)(T &))
{
    for (std::size_t i = 0; i < length ; i++)
        f(array[i]);
}

// testing functions

template <typename T>
void printConst(T const &x)
{
    std::cout << x << " ";
}

template <typename T>
void increment(T &x)
{
    ++x;
}

#endif