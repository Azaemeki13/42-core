/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 12:00:35 by ituriel           #+#    #+#             */
/*   Updated: 2025/12/08 12:02:08 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
    #define FORM_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm 
{
    private:
        const std::string name;
        bool isigned;
        const unsigned int g_sign;
        const unsigned int g_execute;


    public:
        // OCF
        AForm();
        AForm(const std::string &name, unsigned int g_sign, unsigned int g_execute);
        AForm (const AForm &other);
        AForm &operator = (const AForm &other);
        virtual ~AForm();

        // getters + checker
        const std::string& getName() const;
        bool getIsSigned() const;
        unsigned int getSignL() const;
        unsigned int getExecuteL() const;
        void gradeChecker(const unsigned int grade) const;

        // Abstracter
        virtual void execute(Bureaucrat const &executor) const = 0;

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
        class NotSigned : public std::exception
        {
            virtual const char *what() const throw();
        };
};

// ostream overload
std::ostream &operator <<(std::ostream &out, const AForm &b);

#endif