/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 11:15:09 by ituriel           #+#    #+#             */
/*   Updated: 2025/12/02 12:27:18 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default Name"), grade(75)
{
    std::cout << "Default constructor called !" << std::endl;
}

Bureaucrat::Bureaucrat(std::string &name, unsigned int &grade) : name(name)
{
    try 
    {
        if(grade < 1)
            throw(GradeTooHighException);
        else if (grade > 150)
            throw(GradeTooLowException);
        else
            this->grade = grade;
    }
    catch(GradeTooHighException)
    {
        
    }
}

const std::string&  Bureaucrat::getName()
{
    return(this->name);
}

const unsigned int& Bureaucrat::getGrade()
{
    return(this->grade);
}

Bureaucrat &Bureaucrat::operator ++()
{
    if(this->grade < 1 || this->grade > 150)
        return(*this);
    else
    {
        --this->grade;
        return(*this);
    }
}

Bureaucrat Bureaucrat::operator ++(int)
{
    Bureaucrat temp = *this;
    if(this->grade < 1 || this->grade > 150)
        return(temp);
    else
    {
        --this->grade;
        return(temp);
    }
}

Bureaucrat &Bureaucrat::operator --()
{
    if(this->grade < 1 || this->grade > 150)
        return(*this);
    else
    {
        ++this->grade;
        return(*this);
    }
}

Bureaucrat Bureaucrat::operator --(int)
{
    Bureaucrat temp = *this;
    if(this->grade < 1 || this->grade > 150)
        return(temp);
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