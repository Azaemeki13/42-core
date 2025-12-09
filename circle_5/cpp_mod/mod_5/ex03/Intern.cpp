/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:36:57 by ituriel           #+#    #+#             */
/*   Updated: 2025/12/09 12:05:27 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Default constructor called on Intern!" << std::endl;
}

Intern::Intern(std::string name)
{
    std:: cout << "If only we cared about " << name << std::endl;
}

Intern::Intern(Intern &other)
{
    (void)other;
    std::cout << "I mean it they all look the same, made on purpose to fill forms." << std::endl;
}

Intern& Intern::operator =(const Intern &other)
{
    (void)other;
    std::cout << " Please take intern 2 his seat and do it's job." << std::endl;
    return(*this);
}

Intern::~Intern()
{
    std::cout << "Internship ends, you gained much valuable company experience." << std::endl;
}

const char * Intern::noSuchName::what() const throw()
{
    return("Such form name doesn't exists, must make coffee.");
}

AForm * Intern::makeForm(const std::string &f_name,const std::string &target)
{
    std::string fetcher[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
    AForm *factorio[3] = { new PresidentialPardonForm(target),new RobotomyRequestForm(target), new ShrubberyCreationForm(target)};
    
    for(int i = 0; i < 3; i++)
    {
        if(fetcher[i] == f_name)
        {
            std::cout << "Intern creates " << f_name << std::endl;
            for (int j = 0; j < 3; j++)
            {
                if(j != i)
                    delete factorio[j];
            }
            return(factorio[i]);
        }
    }
    for (int i = 0; i < 3; i++)
        delete factorio[i];
    throw noSuchName();
}