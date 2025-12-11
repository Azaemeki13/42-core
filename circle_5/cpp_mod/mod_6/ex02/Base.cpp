/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 10:37:01 by ituriel           #+#    #+#             */
/*   Updated: 2025/12/11 11:05:54 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base()
{
    std::cout << "Destructor called on base." << std::endl;
}

Base *Base::generate(void)
{
    int pick = rand() % 101;
    if (pick < 33)
        return new Base_A;
    else if (pick > 33 && pick < 66)
        return new Base_B;
    else
        return new Base_C;
}

void Base::identify(Base *p)
{
    Base_A *ba  = dynamic_cast <Base_A*>(p);
    if (ba != NULL)
        std::cout << "Type is Base A" << std::endl;
    Base_B *base_b = dynamic_cast <Base_B*>(p);
    if (base_b != NULL)
        std::cout << "Type is Base B" << std::endl;
    Base_C *base_c = dynamic_cast <Base_C*>(p);
    if (base_c != NULL)
        std::cout << "Type is Base C" << std::endl;
}

void Base::identify(Base &p)
{
    try
    {
        (void)dynamic_cast<Base_A&>(p);
        std::cout << "Type is Base A" << std::endl;
        return;
    }
    catch(std::bad_cast &) {}
    try
    {
        (void)dynamic_cast<Base_B&>(p);
        std::cout << "Type is Base B" << std::endl;
        return;
    }
    catch(std::bad_cast &) {}
    try
    {
        (void)dynamic_cast<Base_C&>(p);
        std::cout << "Type is Base C" << std::endl;
        return;
    }
    catch(std::bad_cast &) {}
}
