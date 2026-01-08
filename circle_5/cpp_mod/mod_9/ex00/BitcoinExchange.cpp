/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 13:17:31 by ituriel           #+#    #+#             */
/*   Updated: 2026/01/08 15:19:31 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

Database::Database() : dataPath("./data.csv"), exchange_rate(dataToExch()), input({})
{
    std:: cout << "Default constructor called." << std::endl;
}

Database::Database(const std::string &path) : dataPath
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
// think of correct formatting (so correct header aswell)
// CARE WITH SPACES on DATE | VALUE (for actual stuff)

// -----------verifications ---------------

Database::mcChecker(const std::string &path)
{
    std::fstream file;
    std::string buffer;
    unsigned int start = 0;
    file.open(path, std::ios::in);
    if (!file.is_open())
        throw noFile();
    while (std::getline(file, buffer))
    {
        // ---- Checking Headers ----------
        if (!start)
        {
            if (!buffer.empty() && buffer.back() == '\r')
                buffer.pop_back();
            if (buffer != "date | value")
                throw incorrectHeader(buffer);
            start = !start;
        }
        else
        {
        // ---- Checking Data , first Date formating using get-time ----------
            size_t b_pos = buffer.find('|');
            if (b_pos != std::string::npos)
            {
                std::string d1 = buffer.substr(0, b_pos - 1);
                std::string value = buffer.substr(b_pos + 1);
                std::tm tm = {};
                std::istringstream ss(d1);
                ss >> std::get_time(&tm, "%Y-%m-%d");
                if (ss.fail())
                    throw incorrectDate(d1);
                std::tm copy = tm;
                std::time_t res = std::mktime(&copy);
                if ((tm.tm_mday == copy.tm_mday  && tm.tm_mon == copy.tm_mon 
                    && tm.tm_year == copy.tm_year))
                {
        // ---- Checking Data , secondly values (FIND A WAY TO USE THE THROW) ----------
                    float val;
                    std::istringstream ss2(value);
                    ss2 >> val;
                    if (val < 0)
                        throw negativeValue();
                    else if (val > 1000)
                        throw tooHighValue();
                    else 
                        input[d1] = val;
                }

                else
                    throw incorrectDate(d1);
            }
        }
    }
}

// -----------data to structure ---------------

Database::dataToExch()
{
    std::fstream path;
    unsigned int start = 0;
    std::string buffer;
    path.open(dataPath, std::ios::in);
    if (!path.is_open())
        throw noFile();
    while (std::getline(path, buffer))
    {
        if (start)
        {
            size_t cpos = buffer.find(',');
            if (cpos != std::string::npos)
            {
                std::string date = buffer.substr(0, cpos);
                std::string content = buffer.substr(cpos + 1);
                exchange_rate[date] = std::stof(content);
            }
        }
        else
            start  = !start;
    }
}

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

Database::incorrectHeader::incorrectHeader(const std::string &line)
{
    std::stringstream ss;
    ss << "Error: bad input: " << line << " Please make sure that the headers are a strict \"date | value\".";
    header = ss.str();
}

const char *Database::incorrectHeader::what() const throw()
{
    return header.c_str();
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

Database::duplicateDate::duplicateDate(const std::string &line)
{
    std::stringstream ss;
    ss << "Error: duplicate date: " << line << " Please make sure that there is only one date xd.";
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
