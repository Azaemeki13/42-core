/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 09:39:50 by cauffret          #+#    #+#             */
/*   Updated: 2026/01/13 13:28:32 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
    #define RPN_HPP

#include <iostream>
#include <string>
#include <iterator>
#include <exception>
#include <stack>
#include <cctype>
#include <sstream>

class RPN
{
    private:
        std::stack<int> stak;

    public:
    // ------------------ OFC -----------------------
        RPN();
        RPN(const std::string &expression);
        RPN(const RPN &other);
        RPN &operator =(const RPN &other);
        ~RPN();

    // ------------------ Functions :D -----------------------
        void toStack(const std::string &expression);
        bool isValid(char c);
        int calculate(int x, int y, char c);
        int showResult();

    // ------------------ Throws -----------------------
        class notEnoughOperands : public std::exception
        {
            private: 
                std::string _operand;
            public:
                notEnoughOperands(const std::string &operand);
                virtual const char *what() const throw();
                virtual ~notEnoughOperands() throw() {};    
        };
        class tooManyOperands : public std::exception
        {
            private: 
                std::string _operand;
            public:
                tooManyOperands(const std::string &operand);
                virtual const char *what() const throw();
                virtual ~tooManyOperands() throw() {};    
        };
        class incorrectExpression : public std::exception
        {
            private: 
                std::string _operand;
            public:
                incorrectExpression(const std::string &operand);
                virtual const char *what() const throw();
                virtual ~incorrectExpression() throw() {};    
        };
        class impossibleDivision : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

#endif