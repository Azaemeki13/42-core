/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 11:06:47 by ituriel           #+#    #+#             */
/*   Updated: 2025/12/10 14:46:13 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int ScalarConverter::stringToInt(const std::string &s) 
{ 
    int i; 
    std::istringstream(s) >> i;
    return i;
}

char ScalarConverter::intToChar(int i)
{
    if (i >= 0 && i < 128)
    {
        if (std::isprint(i))
            return static_cast<char>(i);
        throw nonDisplayable();
    }
    throw isImpossible();
}

float ScalarConverter::stringToFloat(const std::string &s)
{
    std::string::size_type found = s.find('f');
    if (found != std::string::npos && found + 1 == s.size())
    {
        std::string toconv = s;
        if (s.size() != 1)
            toconv.erase(found, 1);
        float i;
        std::istringstream ss(toconv);
        ss >> i;
        if (!ss)
            throw isImpossible();
        if (!ss.eof())
            throw isImpossible();
        return(i);
    }
    float f;
    std::istringstream ss(s);
    ss >> f;
    if (!ss)
        throw isImpossible();
    if (!ss.eof())
        throw isImpossible();
    return(f);
}

double ScalarConverter::stringToDouble(const std::string &s)
{
    double f;
    std::istringstream(s) >> f;
    return(f);
}

std::string &ScalarConverter::trimmString(std::string &conv)
{
    std::string::size_type beg = 0;
    std::string::size_type end = conv.size();
    while (beg < end && std::isspace(static_cast<unsigned char>(conv[beg])))
        ++beg;
    while (end > beg && std::isspace(static_cast<unsigned char>(conv[end - 1])))
        --end;
    if (beg == 0 && end == conv.size())
        return(conv);
    conv = conv.substr(beg, end - beg);
    return conv;
}

bool ScalarConverter::isPLitteral(const std::string &conv)
{
    if (conv == "-inff" || conv == "-inf")
    {
        std::cout << "char: " << " impossible" << std::endl;
        std::cout << "int: " << " impossible" << std::endl;
        std::cout << "float: " << -std::numeric_limits<float>::infinity() << "f" << std::endl;
        std::cout << "double: " << -std::numeric_limits<double>::infinity() << std::endl;
        return(1);
    }
    else if (conv == "+inff" || conv == "+inf")
    {
        std::cout << "char: " << " impossible" << std::endl;
        std::cout << "int: " << " impossible" << std::endl;
        std::cout << "float: " << std::numeric_limits<float>::infinity() << "f" << std::endl;
        std::cout << "double: " << std::numeric_limits<double>::infinity() << std::endl;
        return(1);
    }
    else if (conv == "nan" || conv == "nanf")
    {
        std::cout << "char: " << " impossible" << std::endl;
        std::cout << "int: " << " impossible" << std::endl;
        std::cout << "float: " << "nanf" << std::endl;
        std::cout << "double: " << "nan" << std::endl;
        return(1);
    }
    return(0);
}

void ScalarConverter::printFloat(const float &f)
{
    if (f - std::floor(f) != 0)
        std::cout << "float: " << f << "f" << std::endl;
    else
        std::cout << "float: " << f << ".0f" << std::endl;
}
 
void ScalarConverter::printDouble(const double &d)
{
    if (d - std::floor(d) != 0)
        std::cout << "double: " << d << std::endl;
    else
        std::cout << "double: " << d << ".0" << std::endl;
}

void ScalarConverter::printImpossibles(void)
{
    std::cout << "char: " << " impossible" << std::endl;
    std::cout << "int: " << " impossible" << std::endl;
    std::cout << "float: " << " impossible" << std::endl;
    std::cout << "double: " << " impossible" << std::endl;
}

void ScalarConverter::convert(std::string &conv)
{
    trimmString(conv);
    std::string::size_type size = conv.size();
    if (size == 1 && !std::isdigit(conv[0]))
    {
        std::stringstream ss;
        ss << static_cast<int>(conv[0]);
        std::string type;
        ss >> type;
        std::cout << "char: '" << conv[0] << "'" << std::endl;
        std::cout << "int: " << stringToInt(type) << std::endl;
        printFloat(stringToFloat(type));
        printDouble(stringToDouble(type));
    }
    else if (!isPLitteral(conv))
    {
        try
        {
            stringToFloat(conv);
        }
        catch (const isImpossible &)
        {
            printImpossibles();
            return;
        }
        try
        {
            std::cout << "char: '" << intToChar(stringToInt(conv)) << "'"<< std::endl;
        }
        catch (const nonDisplayable &)
        {
            std::cout << "char: Non displayable" << std::endl;
        }
        catch (const isImpossible &)
        {
            std::cout << "char: impossible" << std::endl;
        }
        std::cout << "int: " << stringToInt(conv) << std::endl;
        printFloat(stringToFloat(conv));
        printDouble(stringToDouble(conv));
    }
    return;
}