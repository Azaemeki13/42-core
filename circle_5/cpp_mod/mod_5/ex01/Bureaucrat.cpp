/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 11:15:09 by ituriel           #+#    #+#             */
/*   Updated: 2025/12/04 12:57:55 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default Name"), grade(75)
{
    std::cout << "Default constructor called for Bureaucrat!" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, const unsigned int grade) : name(name)
{

    if(grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    else
        this->grade = grade;
    std::cout << "Parameter constructor called for Bureaucrat!!" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat &other) : name(other.name)
{
    if (other.grade < 1)
        throw GradeTooHighException();
    else if (other.grade > 150)
        throw GradeTooLowException();
    else 
        this->grade = other.grade;
    std::cout << "Copy constructor called for Bureaucrat!!" << std::endl;
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
    std::cout << "Assignement operator called for Bureaucrat!!" << std::endl;
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

void Bureaucrat::signForm(Form &f) const
{
    try
    {
        f.beSigned(*this);
        std::cout << getName() << " signed " << f.getName() << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << getName() << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
    }
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
    return("Bureaucrat Grade too high!");
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
    return("Bureaucrat Grade too low!");
}

std::ostream &operator <<(std::ostream &out, const Bureaucrat &b)
{
    out << b.getName() << " bureaucrat grade " << b.getGrade();
    return (out);
}