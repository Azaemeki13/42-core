/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:58:51 by ituriel           #+#    #+#             */
/*   Updated: 2025/12/09 12:00:42 by ituriel          ###   ########.fr       */
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
    std::srand(std::time(NULL)); // for randomness
    std::cout << "===== Creating Bureaucrats =====" << std::endl;
    Bureaucrat low("LowBob", 150);
    Bureaucrat mid("MidJoe", 50);
    Bureaucrat high("HighAlice", 1);
    std::cout << low << std::endl;
    std::cout << mid << std::endl;
    std::cout << high << std::endl;
    // ============================================================
    std::cout << "\n===== ShrubberyCreationForm tests =====" << std::endl;
    // ============================================================
    try
    {
        ShrubberyCreationForm shrub("home");
        std::cout << shrub << std::endl;
        std::cout << "\n-- LowBob tries to sign Shrubbery --" << std::endl;
        low.signForm(shrub);  // should fail
        std::cout << "\n-- HighAlice signs Shrubbery --" << std::endl;
        high.signForm(shrub); // should succeed
        std::cout << shrub << std::endl;
        std::cout << "\n-- LowBob tries to execute Shrubbery --" << std::endl;
        low.executeForm(shrub); // should fail
        std::cout << "\n-- HighAlice executes Shrubbery --" << std::endl;
        high.executeForm(shrub); // should create home_shrubbery file
    }
    catch (std::exception &e)
    {
        std::cout << "Shrubbery test exception: " << e.what() << std::endl;
    }
    // ============================================================
    std::cout << "\n===== RobotomyRequestForm tests =====" << std::endl;
    // ============================================================
    try
    {
        RobotomyRequestForm robo("Bender");
        std::cout << robo << std::endl;
        std::cout << "\n-- MidJoe tries to sign Robotomy --" << std::endl;
        mid.signForm(robo); // should succeed
        std::cout << "\n-- MidJoe executes Robotomy several times --" << std::endl;
        for (int i = 0; i < 5; ++i)
            mid.executeForm(robo);  // 50% success/fail
    }
    catch (std::exception &e)
    {
        std::cout << "Robotomy test exception: " << e.what() << std::endl;
    }
    // ============================================================
    std::cout << "\n===== PresidentialPardonForm tests =====" << std::endl;
    // ============================================================
    try
    {
        PresidentialPardonForm pres("Arthur Dent");
        std::cout << pres << std::endl;
        std::cout << "\n-- MidJoe tries to sign Presidential --" << std::endl;
        mid.signForm(pres); // should fail
        std::cout << "\n-- HighAlice signs Presidential --" << std::endl;
        high.signForm(pres); // should succeed
        std::cout << pres << std::endl;
        std::cout << "\n-- MidJoe tries to execute Presidential --" << std::endl;
        mid.executeForm(pres); // should fail
        std::cout << "\n-- HighAlice executes Presidential --" << std::endl;
        high.executeForm(pres); // should print Zaphod Beeblebrox message
    }
    catch (std::exception &e)
    {
        std::cout << "Presidential test exception: " << e.what() << std::endl;
    }
    std::cout << "\n===== End of tests =====" << std::endl;
    return 0;
}
