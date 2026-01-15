/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 11:15:09 by ituriel           #+#    #+#             */
/*   Updated: 2026/01/15 10:04:02 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default Name"), grade(75)
{
    std::cout << "Default constructor called !" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, const unsigned int grade) : name(name)
{

    if(grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    else
        this->grade = grade;
    std::cout << "Parameter constructor called !" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat &other) : name(other.name)
{
    if (other.grade < 1)
        throw GradeTooHighException();
    else if (other.grade > 150)
        throw GradeTooLowException();
    else 
        this->grade = other.grade;
    std::cout << "Copy constructor called !" << std::endl;
}

Bureaucrat& Bureaucrat::operator = (const Bureaucrat &other)
{
    if (this != &other)
    {
        if (other.grade < 1)
            throw GradeTooHighException();
        else if (other.grade > 150)
            throw GradeTooLowException();
        else 
            grade = other.grade;
    }
    std::cout << "Assignement operator called !" << std::endl;
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Called destructor on Bureaucrat !" << std::endl;
}

const std::string&  Bureaucrat::getName() const
{
    return(this->name);
}

const unsigned int& Bureaucrat::getGrade() const
{
    return(this->grade);
}

Bureaucrat &Bureaucrat::operator ++()
{
    if (grade == 1)
        throw GradeTooHighException();
    else
    {
        --this->grade;
        return(*this);
    }
}

Bureaucrat Bureaucrat::operator ++(int)
{
    Bureaucrat temp = *this;
    if (grade == 1)
        throw GradeTooHighException();
    else
    {
        --this->grade;
        return(temp);
    }
}

Bureaucrat &Bureaucrat::operator --()
{
    if(grade == 150)
        throw GradeTooLowException();
    else
    {
        ++this->grade;
        return(*this);
    }
}

Bureaucrat Bureaucrat::operator --(int)
{
    Bureaucrat temp = *this;
    if(grade == 150)
        throw GradeTooLowException();
    else
    {
        ++this->grade;
        return(temp);
    }
}

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
    return("Grade too high!");
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
    return("Grade too low!");
}

std::ostream &operator <<(std::ostream &out, const Bureaucrat &b)
{
    out << b.getName() << " bureaucrat grade " << b.getGrade();
    return (out);
}