/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:58:51 by ituriel           #+#    #+#             */
/*   Updated: 2025/12/09 12:01:52 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::srand(std::time(NULL)); // for Robotomy 50% randomness

    std::cout << "===== Intern Form Factory Tests =====" << std::endl;

    Intern someRandomIntern;

    AForm *form1 = NULL;
    AForm *form2 = NULL;
    AForm *form3 = NULL;
    AForm *badForm = NULL;

    Bureaucrat high("HighBureau", 1);
    Bureaucrat mid("MidBureau", 40);
    Bureaucrat low("LowBureau", 150);

    std::cout << high << std::endl;
    std::cout << mid << std::endl;
    std::cout << low << std::endl;

    std::cout << "\n--- Creating Shrubbery Form ---" << std::endl;
    try
    {
        form1 = someRandomIntern.makeForm("ShrubberyCreationForm", "garden");
        std::cout << *form1 << std::endl;

        high.signForm(*form1);
        high.executeForm(*form1); // calls execute inside AForm then Shrubbery
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Creating Robotomy Form ---" << std::endl;
    try
    {
        form2 = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
        std::cout << *form2 << std::endl;

        mid.signForm(*form2);
        mid.executeForm(*form2);
        mid.executeForm(*form2);
        mid.executeForm(*form2); // test randomness a bit
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Creating Presidential Form ---" << std::endl;
    try
    {
        form3 = someRandomIntern.makeForm("PresidentialPardonForm", "Arthur");
        std::cout << *form3 << std::endl;

        mid.signForm(*form3);    // too low → fail
        high.signForm(*form3);   // succeed
        mid.executeForm(*form3); // too low → fail
        high.executeForm(*form3); // succeed → Zaphod Beeblebrox message
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Creating Unknown Form (error expected) ---" << std::endl;
    try
    {
        badForm = someRandomIntern.makeForm("BananaCakeForm", "kitchen");
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // Cleanup
    delete form1;
    delete form2;
    delete form3;
    delete badForm;

    std::cout << "\n===== End of Intern Tests =====" << std::endl;

    return 0;
}
