/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 09:39:52 by cauffret          #+#    #+#             */
/*   Updated: 2026/01/13 13:26:06 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// ------------------ OCF -----------------------

RPN::RPN() : stak()
{
    std::cout << "Called on basic constructor." << std::endl;
}

RPN::RPN(const std::string  &tokens) : stak()
{
    toStack(tokens);
    std::cout << "Called on parameterised constructor." << std::endl;
}

RPN::RPN(const RPN &other) : stak(other.stak)
{
    std::cout << "Called on copy constructor." << std::endl;
}

RPN &RPN::operator =(const RPN &other)
{
    if (this != &other)
        stak = other.stak;
    std::cout << "Called on assignement operator." << std::endl;
    return(*this);
}

RPN::~RPN()
{
    std::cout << "Successfully called the destructor on RPN." << std::endl;
}

// ------------------ Functions :D -----------------------

bool RPN::isValid(char c)
{
    if(c == '*' || c == '/' || c == '+' || c == '-')
        return(true);
    return(false);
}
int RPN::calculate(int x, int y, char c)
{
    switch(c)
    {
        case '+':
            return (x + y);
        case '-':
            return (x - y);
        case '*':
            return (x * y);
        case '/':
        {
            if (y == 0)
                throw impossibleDivision();
            return (x / y);
        }
        default:
            throw incorrectExpression(std::string (1, c));
    }
}

void RPN::toStack(const std::string &expression)
{
    size_t expl = expression.length();
    for (size_t i = 0; i < expl; ++i)
    {
        if (std::isspace(expression[i]))
            continue;
        if(std::isdigit(expression[i]))
            stak.push(expression[i] - '0');
        else if (isValid(expression[i]))
        {
            if (stak.size() < 2)
                throw notEnoughOperands("Stack has only 1 number in it !");
            else
            {
                int val_2 = stak.top();
                stak.pop();
                int val_1 = stak.top();
                stak.pop();
                stak.push(calculate(val_1, val_2, expression[i]));
            }
        }
        else
            throw incorrectExpression(expression);
    }
    if (stak.size() != 1)
        throw tooManyOperands("Stack has no specific result !");
}

int RPN::showResult()
{
    return(stak.top());
}

// ------------------ Throws -----------------------

RPN::tooManyOperands::tooManyOperands(const std::string &operand)
{
    std::stringstream ss;
    ss << "Incorect operands: " << operand << ". Too many operands.";
    _operand = ss.str();
}

const char*RPN::tooManyOperands::what() const throw()
{
    return _operand.c_str();
}

RPN::notEnoughOperands::notEnoughOperands(const std::string &operand)
{
    std::stringstream ss;
    ss << "Incorrect operands: " << operand << ". Not enough operands.";
    _operand = ss.str();
}

const char *RPN::notEnoughOperands::what() const throw()
{
    return _operand.c_str();
}

RPN::incorrectExpression::incorrectExpression(const std::string &operand)
{
    std::stringstream ss;
    ss << "Incorrect expression: " << operand << ". Expression is incorrect.";
    _operand = ss.str();
}

const char *RPN::incorrectExpression::what() const throw()
{
    return _operand.c_str();
}

const char *RPN::impossibleDivision::what() const throw()
{
    return("Impossible, division per 0.");
}