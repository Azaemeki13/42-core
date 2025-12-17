/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:06:00 by ituriel           #+#    #+#             */
/*   Updated: 2025/12/17 12:04:41 by cauffret         ###   ########.fr       */
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
#include <cmath>
#include <vector>
#include <list>


class Span
{
    private: 
        unsigned int capacity;
        size_t a_index;
        int *myArray;
    public:
    // ocf 
        Span();
        Span(unsigned int n);
        Span(const Span &other);
        Span &operator =(const Span &other);
        ~Span();
    // functions
        void addNumber(const int n);
    // thanks subject i cant have a tpp XD
        template<typename iterator>
        void addRange(iterator start, iterator end)
        {
            for (; start != end; start++)
                addNumber(*start);
        }
        unsigned int shortestSpan();
        unsigned int longestSpan();
    // exceptions
        class emptyArray : public std::exception 
        {
            public :const char *what() const throw(){ return "Array is empty !";}
        };
        class fullArray : public std::exception 
        {
            public :const char *what() const throw(){ return "Array is full !";}
        };
        class spanNotFound : public std::exception 
        {
            public :const char *what() const throw(){ return "Span not found !";}
        };
};

#endif