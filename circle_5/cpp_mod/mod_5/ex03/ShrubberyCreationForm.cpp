/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 10:44:09 by ituriel           #+#    #+#             */
/*   Updated: 2025/12/08 11:45:59 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm",145, 137), target("Default")
{
    std::cout << "Shrubbery default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
    std::cout << "Shrubbery parameterised constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), target(other.target)
{
    std::cout << "Shrubbery copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator =(const ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->target = other.target;
    }
    std::cout << "Shrubbery assignement operator called!" << std::endl;
    return(*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "Shrubbery destructor called!" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if(!getIsSigned())
        throw NotSigned();
    if (executor.getGrade() > getExecuteL())
        throw GradeTooLowException();
    else
    {
        std::string name = target;
        name += "_shrubbery";
        std::ofstream NewFile (name.c_str());
        if (!NewFile)
            throw std::runtime_error("Failed to open shrubbery file");
        NewFile << "  /\\     /\\     /\\     /\\     /\\\n";
        NewFile << " /  \\   /  \\   /  \\   /  \\   /  \\\n";
        NewFile << "/____\\ /____\\ /____\\ /____\\ /____\\\n";
        NewFile << "  ||     ||     ||     ||     ||\n";
        NewFile.close();
    }
}