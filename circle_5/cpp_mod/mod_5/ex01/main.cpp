/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:58:51 by ituriel           #+#    #+#             */
/*   Updated: 2025/12/04 12:58:36 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "---- Test 1: Successful signing ----" << std::endl;
    try
    {
        Bureaucrat john("John", 5);
        Form tax("TaxForm", false, 10, 20);

        std::cout << tax << std::endl;
        john.signForm(tax);
        std::cout << tax << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n---- Test 2: Grade too low to sign ----" << std::endl;
    try
    {
        Bureaucrat bob("Bob", 150);
        Form secret("SecretForm", false, 50, 50);

        std::cout << secret << std::endl;
        bob.signForm(secret);  // should fail
        std::cout << secret << std::endl; // still not signed
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n---- Test 3: Form constructor throws (invalid grade) ----" << std::endl;
    try
    {
        Form invalid("BrokenForm", false, 500, 10); // should throw
    }
    catch (std::exception &e)
    {
        std::cout << "Caught: " << e.what() << std::endl;
    }

    std::cout << "\n---- Test 4: Bureaucrat grade too high/low ----" << std::endl;
    try
    {
        Bureaucrat bad("BadOne", 0); // too high → exception
    }
    catch (std::exception &e)
    {
        std::cout << "Caught: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat bad2("BadTwo", 151); // too low → exception
    }
    catch (std::exception &e)
    {
        std::cout << "Caught: " << e.what() << std::endl;
    }

    return 0;
}