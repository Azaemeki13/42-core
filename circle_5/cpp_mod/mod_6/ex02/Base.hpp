/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 10:32:52 by ituriel           #+#    #+#             */
/*   Updated: 2025/12/11 11:05:03 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
    #define BASE_HPP

#include <iostream>
#include <stdint.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include <typeinfo>

class Base
{
    private:

    public:
        virtual ~Base();
        static Base *generate(void);
        static void identify(Base *p);
        static void identify(Base &p);

};

class Base_A : public Base{};
class Base_B : public Base{};
class Base_C : public Base{};

#endif