/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:58:51 by ituriel           #+#    #+#             */
/*   Updated: 2025/12/03 13:12:02 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main ()
{
    // Default constructor
    Bureaucrat bobby;
    std::cout << bobby << std::endl;
    std::cout << "Now incrementing bobby, he advances in the corporate level !" << std::endl;
    ++bobby;
    std::cout << bobby << std::endl;

    // Let's try parameter 
    Bureaucrat mark("Mark", 1);
    std::cout << mark << std::endl;
    // error works
    try
    {
        mark++;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
        mark--;
        std::cout << "Mark got demoted.." << std::endl;
        std::cout << mark << std::endl;
    }
    Bureaucrat john = mark;
    std::cout << john << std::endl;
    std::cout << "Let's ruin John's career." << std::endl;
    while (john.getGrade() != 150)
        john--;
    try
    {
        john--;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
        std::cout << john << std::endl;
    }
    return(1);
}