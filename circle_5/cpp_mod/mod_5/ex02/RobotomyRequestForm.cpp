/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 10:43:06 by ituriel           #+#    #+#             */
/*   Updated: 2025/12/08 11:54:45 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm",72, 45), target("Default")
{
    std::cout << "Robotomy default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
    std::cout << "Robotomy parameterised constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), target(other.target)
{
    std::cout << "Robotomy copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator =(const RobotomyRequestForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->target = other.target;
    }
    std::cout << "Robotomy assignement operator called!" << std::endl;
    return(*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "Robotomy destructor called!" << std::endl;
}

const std::string& RobotomyRequestForm::getTarget() const
{
    return(target);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if(!getIsSigned())
        throw NotSigned();
    if (executor.getGrade() > getExecuteL())
        throw GradeTooLowException();
    else
    {
        std::cout << "Intense drilling noise happening" << std::endl;
        int chances = rand() % 100 + 1;
        if (chances < 50)
            std::cout << getTarget() << " has been successfully robotomised!" << std::endl;
        else
            std::cout << getTarget() << " has been unsuccessfully robotomised!" << std::endl;
    }
}
