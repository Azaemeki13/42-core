/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:05:56 by ituriel           #+#    #+#             */
/*   Updated: 2025/12/16 14:25:39 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : n(100)
{
    myArray = new int[100];
    std::cout << "Called default constructor on Span." << std::endl;
}

Span::Span(unsigned int n) : n(n)
{
    myArray = new int[n];
    std::cout << "Called parameter constructor on Span." << std::endl;
}

Span::Span(const Span &other) : n(other.n)
{
    if(n <= 0)
        throw emptyArray();
    for (unsigned int i = 0; i < other.myArray.size(); i++)
}

Span& Span::operator =(const Span &other)
{

}

Span::~Span()
{

}