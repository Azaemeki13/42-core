/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 12:42:07 by cauffret          #+#    #+#             */
/*   Updated: 2025/12/17 13:14:07 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
    #define MUTANTSTACK_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <vector> 
#include <list>
#include <cstddef>
#include <cmath>
#include <stack>

template<typename T, typename Container = std::deque<T> > 
class MutantStack : public std::stack<T, Container>
{
    private:

    public:
        MutantStack() : std::stack<T, Container>() {}
        MutantStack(const MutantStack &other) : std::stack<T, Container>(other) {} // using here (other) to call constructor from udnerlying container
        MutantStack& operator =(const MutantStack &other)
        {
            if (this != &other)
                std::stack<T,Container>::operator=(other); // way to  catch the underlying operator on the stack
            return (*this);
        }
        virtual ~MutantStack(){}
        typedef typename std::stack<T, Container>::container_type::iterator iterator;
        iterator begin();
        iterator end();
};

#include "MutantStack.tpp"
#endif