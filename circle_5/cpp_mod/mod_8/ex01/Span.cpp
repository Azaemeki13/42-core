/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:05:56 by ituriel           #+#    #+#             */
/*   Updated: 2025/12/17 12:09:44 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : capacity(100), a_index(0)
{
    myArray = new int[100];
    std::cout << "Called default constructor on Span." << std::endl;
}

Span::Span(unsigned int capacity) : capacity(capacity), a_index(0)
{
    myArray = new int[capacity];
    std::cout << "Called parameter constructor on Span." << std::endl;
}

Span::Span(const Span &other) : capacity(other.capacity), a_index(other.a_index)
{
    myArray = new int[capacity];
    for (unsigned int i = 0; i < a_index; i++)
        myArray[i] = other.myArray[i];
    std::cout << "Called copy constructor on Span." << std::endl;
}

Span& Span::operator =(const Span &other)
{
    if (this != &other)
    {
        delete [] myArray;
        capacity = other.capacity;
        a_index = other.a_index;
        myArray = new int[capacity];
        for(unsigned int i = 0; i < a_index; i++)
            myArray[i] = other.myArray[i];
    }
    std::cout << " Called assignement operator on Span." << std::endl;
    return(*this);
}

Span::~Span()
{
    delete [] myArray;
    myArray = NULL;
    std::cout << "Called destructor on Span." << std::endl;
}

void Span::addNumber(const int n)
{
    if (a_index >= capacity)
        throw fullArray();
    myArray[a_index++] = n;
}

unsigned int Span::shortestSpan()
{
    if (a_index < 2)
        throw spanNotFound();
    std::vector<int>sorted(myArray, myArray + a_index);
    std::sort(sorted.begin(), sorted.end());
    std::vector<int>::iterator it = sorted.begin();
    if (a_index == 2)
        return std::abs(*it - *(it + 1));
    int min_distance = -1;
    bool start = 0;
    std::vector<int>::iterator et = sorted.end();
    for(; it != et; it++)
    {
        if (!start && it + 1 != et)
        {
            min_distance = std::abs(*it - *(it + 1));
            start = !start;
        }
        if (it + 1 != et)
        {
            if (std::abs(*it - *(it +1)) < min_distance)
                min_distance = std::abs(*it - *(it +1));
        }
    }
    return static_cast<unsigned int>(min_distance);
}

unsigned int Span::longestSpan()
{
    if (a_index < 2)
        throw spanNotFound();
    std::vector<int>sorted(myArray, myArray +a_index);
    std::sort(sorted.begin(), sorted.end());
    std::vector<int>::iterator it = sorted.begin();
    std::vector<int>::iterator et = sorted.end();
    return (std::abs(*(et- 1) - *it));
}