/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 10:34:41 by ituriel           #+#    #+#             */
/*   Updated: 2025/12/15 11:46:09 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
    #define ARRAY_HPP

    #include <iostream>
    #include <string>
    #include <cstddef>
    #include <exception>

template <typename T> class Array
{
    private:
        T *array;
        unsigned int _size;
    public:
        // ocf 
        Array();
        Array(unsigned int n);
        Array(const Array<T> &other);
        Array &operator = (const Array<T> &other);
        ~Array();
        // accessors to the array
        T &operator [](unsigned int n);
        T const &operator [](unsigned int n)const;
        // exceptions
        class outOfBoundsException : public std::exception
        {
            public : 
                virtual const char *what () const throw();
        };
        // member function
        unsigned int size()const;

};
#include "Array.tpp"

#endif