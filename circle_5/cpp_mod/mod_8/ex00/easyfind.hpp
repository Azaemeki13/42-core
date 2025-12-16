/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 11:20:13 by ituriel           #+#    #+#             */
/*   Updated: 2025/12/16 12:13:06 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
    #define EASYFIND_HPP

#include <iostream>
#include <string>
#include <cstddef>
#include <exception>
#include <algorithm>
#include <iterator>
#include <vector>
#include <list>

template <typename T>
typename T::iterator easyfind( T& container, int value);

class notFound : public std::exception
{
    public : 
        virtual const char * what() const throw() {return "integer wasn't found.";}
};

class sizeZero : public std::exception
{
    public : 
        virtual const char * what() const throw() {return "Size is zero !";}
};

class wrongArray : public std::exception
{
    public : 
        virtual const char * what() const throw() {return "Wrong array type.";}
};

#include "easyfind.tpp"
#endif