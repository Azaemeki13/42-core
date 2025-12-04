/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 11:02:16 by ituriel           #+#    #+#             */
/*   Updated: 2025/12/04 13:04:34 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
    #define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
    private: 
        const std::string name;
        unsigned int grade;
    public:

        // OCF 
        Bureaucrat();
        Bureaucrat(const std::string &name, const unsigned int grade);
        Bureaucrat(Bureaucrat &other);
        Bureaucrat &operator = (const Bureaucrat &other);
        ~Bureaucrat();


        // Getters 
        const std::string &getName() const;
        const unsigned int &getGrade() const;

        // actions
        void signForm(Form &f) const;

        // Increment overloads
        Bureaucrat& operator ++();
        Bureaucrat operator ++(int);
        Bureaucrat& operator --();
        Bureaucrat operator --(int);

        // Exceptions 
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
    };

    // ostream overload
    std::ostream &operator <<(std::ostream &out, const Bureaucrat &b);

#endif