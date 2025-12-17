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

template<typename T> 
class MutantStack : public std::stack<T>
{
    private:

    public:
        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator begin();
        iterator end();
};

#include "MutantStack.tpp"
#endif