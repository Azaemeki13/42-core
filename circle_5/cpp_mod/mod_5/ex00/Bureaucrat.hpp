/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 11:02:16 by ituriel           #+#    #+#             */
/*   Updated: 2025/12/02 12:21:10 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>



class Bureaucrat
{
    private: 
        const std::string name;
        unsigned int grade;
    public:

        // OCF 

        Bureaucrat();
        Bureaucrat(std::string &name, unsigned int grade);
        // Getters 
        const std::string &getName();
        const unsigned int &getGrade();

        // Increment cause why not 
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
