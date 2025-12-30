/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 13:17:31 by ituriel           #+#    #+#             */
/*   Updated: 2025/12/30 14:02:59 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// think of int negative errors
// think of bad YYYY-MM-DD 
// care with overflows or underflows 

Database::Database()
{

}

Database::Database(const std::string &path)
{

}

Database::Database(const Database &other)
{

}

Database &Database::operator =(const Database &other)
{

}

Database::~Database()
{
    
}

// -----------END OF OCF ---------------

// -----------THROWS ---------------
const char *Database::noFile::what() const throw()
{
    return ("Error: Couldn't open the file.");
}

Database::incorrectParsing::incorrectParsing(const std::string &line)
{
    std::stringstream ss;
    ss << "Error: incorrect parsing. " << line << " Should look like this: date | value.";
    message = ss.str();
}

const char *Database::incorrectParsing::what() const throw()
{
    return message.c_str();
}

Database::incorrectDate::incorrectDate(const std::string &line)
{
    std::stringstream ss;
    ss << "Error: bad input: " << line << " Please make sure that YYYY-12(max)-31(max).";
    date = ss.str();
}

const char *Database::incorrectDate::what() const throw()
{
    return date.c_str();
}

Database::negativeValue::negativeValue(const std::string &line)
{
    std::stringstream ss;
    ss << "Error: value is negative: " << line << " Should be 0 minimum.";
    value = ss.str();
}

const char *Database::negativeValue::what() const throw()
{
    return value.c_str();
}

Database::tooHighValue::tooHighValue(const std::string &line)
{
    std::stringstream ss;
    ss << "Error: value is too high: " << line << " Should be 1000 maximum.";
    value = ss.str();
}

const char *Database::tooHighValue::what() const throw()
{
    return value.c_str();
}
// -----------END OF THROWS ---------------
