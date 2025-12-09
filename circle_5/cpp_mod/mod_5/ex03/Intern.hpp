/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:36:50 by ituriel           #+#    #+#             */
/*   Updated: 2025/12/09 12:03:58 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
    public:
    // ocf
        Intern();
        Intern(std::string name);
        Intern(Intern &other);
        Intern& operator =(const Intern &other);
        ~Intern();
    // actions
        AForm * makeForm(const std::string &f_name, const std::string &target);
    //exceptions
        class noSuchName : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};