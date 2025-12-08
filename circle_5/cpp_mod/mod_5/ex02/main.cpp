/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:58:51 by ituriel           #+#    #+#             */
/*   Updated: 2025/12/08 12:11:11 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::srand(std::time(NULL)); // for Robotomy randomness

    std::cout << "===== Creating Bureaucrats =====" << std::endl;
    Bureaucrat low("LowBob", 150);
    Bureaucrat mid("MidJoe", 50);
    Bureaucrat high("HighAlice", 1);

    std::cout << low << std::endl;
    std::cout << mid << std::endl;
    std::cout << high << std::endl;

    std::cout << "\n===== ShrubberyCreationForm tests =====" << std::endl;
    try
    {
        ShrubberyCreationForm shrub("home");
        std::cout << shrub << std::endl;

        std::cout << "\n-- LowBob tries to sign Shrubbery --" << std::endl;
        low.signForm(shrub); // should fail (needs 145 to sign)

        std::cout << "\n-- HighAlice signs Shrubbery --" << std::endl;
        high.signForm(shrub); // should succeed
        std::cout << shrub << std::endl;

        std::cout << "\n-- LowBob tries to execute Shrubbery --" << std::endl;
        try
        {
            shrub.execute(low); // should throw GradeTooLowException
        }
        catch (std::exception &e)
        {
            std::cout << "Execution by LowBob failed: " << e.what() << std::endl;
        }

        std::cout << "\n-- HighAlice executes Shrubbery --" << std::endl;
        shrub.execute(high); // should create home_shrubbery file
    }
    catch (std::exception &e)
    {
        std::cout << "Shrubbery test exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== RobotomyRequestForm tests =====" << std::endl;
    try
    {
        RobotomyRequestForm robo("Bender");
        std::cout << robo << std::endl;

        std::cout << "\n-- MidJoe tries to sign Robotomy --" << std::endl;
        mid.signForm(robo); // should succeed (needs 72 to sign, mid = 50)

        std::cout << "\n-- MidJoe executes Robotomy several times --" << std::endl;
        for (int i = 0; i < 5; ++i)
        {
            try
            {
                robo.execute(mid); // should sometimes succeed, sometimes fail
            }
            catch (std::exception &e)
            {
                std::cout << "Execution failed: " << e.what() << std::endl;
            }
        }
    }
    catch (std::exception &e)
    {
        std::cout << "Robotomy test exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== PresidentialPardonForm tests =====" << std::endl;
    try
    {
        PresidentialPardonForm pres("Arthur Dent");
        std::cout << pres << std::endl;

        std::cout << "\n-- MidJoe tries to sign Presidential --" << std::endl;
        mid.signForm(pres); // should fail (needs 25 to sign, mid = 50)

        std::cout << "\n-- HighAlice signs Presidential --" << std::endl;
        high.signForm(pres); // should succeed
        std::cout << pres << std::endl;

        std::cout << "\n-- MidJoe tries to execute Presidential --" << std::endl;
        try
        {
            pres.execute(mid); // should throw GradeTooLowException (needs 5 to exec)
        }
        catch (std::exception &e)
        {
            std::cout << "Execution by MidJoe failed: " << e.what() << std::endl;
        }

        std::cout << "\n-- HighAlice executes Presidential --" << std::endl;
        pres.execute(high); // should print Zaphod Beeblebrox message
    }
    catch (std::exception &e)
    {
        std::cout << "Presidential test exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== End of tests =====" << std::endl;
    return 0;
}