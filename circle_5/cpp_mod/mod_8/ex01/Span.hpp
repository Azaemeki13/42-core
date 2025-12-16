/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:06:00 by ituriel           #+#    #+#             */
/*   Updated: 2025/12/16 14:24:00 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
    #define SPAN_HPP

#include <iostream>
#include <string>
#include <exception>
#include <cstddef>
#include <iterator>
#include <algorithm>


class Span
{
    private: 
        unsigned int n;
        int *myArray;
    public:
        Span();
        Span(unsigned int n);
        Span(const Span &other);
        Span &operator =(const Span &other);
        ~Span();
        class emptyArray : public std::exception 
        {
            public :const char *what() const throw(){ return "Array is empty !";}
        };
        
};

#endif