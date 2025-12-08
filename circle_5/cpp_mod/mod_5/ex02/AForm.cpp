/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 12:00:54 by ituriel           #+#    #+#             */
/*   Updated: 2025/12/08 12:09:49 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// OCF ------------------------->

AForm::AForm() : name("Default Form"), isigned(0), g_sign(75), g_execute(75)
{
    std::cout << "Default constructor called for AForm!" << std::endl;
}

AForm::AForm(const std::string &name, unsigned int g_sign, unsigned int g_execute) : name(name), isigned(0), g_sign(g_sign), g_execute(g_execute)
{
    gradeChecker(g_sign);
    gradeChecker(g_execute);
    std::cout << "Parameter constructor called for AForm!" << std::endl;
}

AForm::AForm(const AForm &other) : name(other.name), isigned(other.isigned), g_sign(other.g_sign), g_execute(other.g_execute)
{
    gradeChecker(g_sign);
    gradeChecker(g_execute);
    std::cout << "Copy constructor called for AForm!" << std::endl;
}

AForm& AForm::operator = (const AForm &other)
{
    if (this != &other)
        isigned = other.isigned;
    std::cout << "Assignement operator called for AForm!" << std::endl;
    return (*this);
}

AForm::~AForm()
{
    std::cout << "Called destructor on AForm !" << std::endl;
}

// Getters & checkers ------------------------->


const std::string& AForm::getName() const
{
    return(this->name);
}

bool AForm::getIsSigned() const
{
    return(this->isigned);
}

unsigned int AForm::getSignL() const
{
    return(this->g_sign);
}

unsigned int AForm::getExecuteL() const
{
    return(this->g_execute);
}

void AForm::gradeChecker(const unsigned int grade) const
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
}
// actions

void AForm::beSigned(const Bureaucrat &b)
{
    if (isigned)
        throw AlreadySigned();
    if (b.getGrade() > g_sign)
        throw GradeTooLowException();
    else
        isigned = 1;
}
// Exceptions ------------------------->

const char * AForm::GradeTooHighException::what() const throw()
{
    return("Form grade too high !");
}

const char * AForm::GradeTooLowException::what() const throw()
{
    return("Form grade too low !");
}

const char * AForm::AlreadySigned::what() const throw()
{
    return("Form is already signed !");
}

const char * AForm::NotSigned::what() const throw()
{
    return("Form isn't signed !");
}

// ostream overload ------------------------->

std::ostream &operator <<(std::ostream &out, const AForm &f)
{
    out << f.getName() << " formed signed ? " << f.getIsSigned() << " sign requirements " << f.getSignL() << " execute requirements " << f.getExecuteL();
    return (out);
}