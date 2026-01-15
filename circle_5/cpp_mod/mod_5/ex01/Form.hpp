/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 12:00:35 by ituriel           #+#    #+#             */
/*   Updated: 2026/01/15 10:29:06 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
    #define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form 
{
    private:
        const std::string name;
        bool isigned;
        const unsigned int g_sign;
        const unsigned int g_execute;


    public:
        // OCF
        Form();
        Form(const std::string &name, unsigned int g_sign, unsigned int g_execute);
        Form (const Form &other);
        Form &operator = (const Form &other);
        ~Form();

        // getters + checker
        const std::string& getName() const;
        bool getIsSigned() const;
        unsigned int getSignL() const;
        unsigned int getExecuteL() const;
        void gradeChecker(const unsigned int grade) const;

        // actions
        void beSigned(const Bureaucrat &b);

        // exceptions 
        class GradeTooHighException : public std::exception
        {
            virtual const char * what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            virtual const char * what() const throw();
        };
        class AlreadySigned : public std::exception
        {
            virtual const char *what() const throw();
        };
};

// ostream overload
std::ostream &operator <<(std::ostream &out, const Form &b);

#endif