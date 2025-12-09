/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 10:41:48 by ituriel           #+#    #+#             */
/*   Updated: 2025/12/08 11:58:02 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm",25, 5), target("Default")
{
    std::cout << "Presidential default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5), target(target)
{
    std::cout << "Presidential parameterised constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other), target(other.target)
{
    std::cout << "Presidential copy constructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator =(const PresidentialPardonForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->target = other.target;
    }
    std::cout << "Presidential assignement operator called!" << std::endl;
    return(*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "Presidential destructor called!" << std::endl;
}

const std::string& PresidentialPardonForm::getTarget() const
{
    return(target);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if(!getIsSigned())
        throw NotSigned();
    if (executor.getGrade() > getExecuteL())
        throw GradeTooLowException();
    else
        std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}