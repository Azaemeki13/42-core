/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 12:00:54 by ituriel           #+#    #+#             */
/*   Updated: 2026/01/15 10:26:14 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// OCF ------------------------->

Form::Form() : name("Default Form"), isigned(0), g_sign(75), g_execute(75)
{
    std::cout << "Default constructor called for Form!" << std::endl;
}

Form::Form(const std::string &name, unsigned int g_sign, unsigned int g_execute) : name(name), isigned(0), g_sign(g_sign), g_execute(g_execute)
{
    gradeChecker(g_sign);
    gradeChecker(g_execute);
    std::cout << "Parameter constructor called for Form!" << std::endl;
}

Form::Form(const Form &other) : name(other.name), isigned(other.isigned), g_sign(other.g_sign), g_execute(other.g_execute)
{
    gradeChecker(g_sign);
    gradeChecker(g_execute);
    std::cout << "Copy constructor called for Form!" << std::endl;
}

Form& Form::operator = (const Form &other)
{
    if (this != &other)
        isigned = other.isigned;
    std::cout << "Assignement operator called for Form!" << std::endl;
    return (*this);
}

Form::~Form()
{
    std::cout << "Called destructor on Form !" << std::endl;
}

// Getters & checkers ------------------------->


const std::string& Form::getName() const
{
    return(this->name);
}

bool Form::getIsSigned() const
{
    return(this->isigned);
}

unsigned int Form::getSignL() const
{
    return(this->g_sign);
}

unsigned int Form::getExecuteL() const
{
    return(this->g_execute);
}

void Form::gradeChecker(const unsigned int grade) const
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
}
// actions

void Form::beSigned(const Bureaucrat &b)
{
    if (isigned)
        throw AlreadySigned();
    if (b.getGrade() > g_sign)
        throw GradeTooLowException();
    else
        isigned = 1;
}
// Exceptions ------------------------->

const char * Form::GradeTooHighException::what() const throw()
{
    return("Form grade too high !");
}

const char * Form::GradeTooLowException::what() const throw()
{
    return("Form grade too low !");
}

const char * Form::AlreadySigned::what() const throw()
{
    return("Form is already signed !");
}

// ostream overload ------------------------->

std::ostream &operator <<(std::ostream &out, const Form &f)
{
    out << f.getName() << " formed signed ? " << f.getIsSigned() << " sign requirements " << f.getSignL() << " execute requirements " << f.getExecuteL();
    return (out);
}