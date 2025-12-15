/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 10:46:35 by ituriel           #+#    #+#             */
/*   Updated: 2025/12/15 11:48:58 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
    #define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array() : array(NULL), _size(0)
{
    std::cout << "Called default constructor for Array." << std::endl;
}
template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
    std::cout << "Called parameterised constructor for Array." << std::endl;
    if (_size == 0)
        return;
    array = new T[_size]();
}

template <typename T>
Array<T>::Array(const Array<T>&other) : array(NULL), _size(other._size)
{
    std::cout << "Called copy constructor for Array." << std::endl;
    if (_size == 0)
        return;
    array = new T[_size];
    for (unsigned int n = 0; n < _size; n++)
        array[n] = other.array[n];
}

template <typename T>
Array<T>& Array<T>::operator =(const Array<T>&other)
{
    if (this != &other)
    {
        if (array != NULL)
        {
            delete[] array;
            array = NULL;
        }
        _size = other._size;
        if (_size == 0)
            array = NULL;
        else
        {
            array = new T[_size];
            for (unsigned int i = 0; i < _size; i++)
                array[i] = other.array[i];
        }
    }
    std::cout << "Called assignement operator on Array." << std::endl;
    return(*this);
}

template <typename T>
Array<T>::~Array()
{
    if (array != NULL)
        delete[] array;
    std::cout << "Called destructor on Array." << std::endl;
}

template <typename T>
const char *Array<T>::outOfBoundsException::what() const throw()
{
    return("Index is out of bounds !");
}

template <typename T>
T &Array<T>::operator[](unsigned int n)
{
    if (n >= _size)
        throw outOfBoundsException();
    return(array[n]);
}

template <typename T>
const T &Array<T>::operator[](unsigned int n) const
{
    if (n >= _size)
        throw outOfBoundsException();
    return(array[n]);
}

template <typename T>
unsigned int Array<T>::size()const
{
    return(_size);
}

#endif