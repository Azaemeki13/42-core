/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 10:37:11 by ituriel           #+#    #+#             */
/*   Updated: 2025/12/11 11:05:08 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main(void)
{
    std::srand(std::time(NULL));
    for (int i = 0; i < 10; ++i)
    {
        Base *p = Base::generate();   // should randomly return new Base_A/B/C

        std::cout << "---- Test " << i + 1 << " ----" << std::endl;

        std::cout << "Identify(Base*):   ";
        Base::identify(p);            // pointer version

        std::cout << "Identify(Base&):   ";
        Base::identify(*p);           // reference version

        delete p;
        std::cout << std::endl;
    }
    return 0;
}