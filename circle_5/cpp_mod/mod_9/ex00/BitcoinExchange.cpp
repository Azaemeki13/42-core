/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 13:17:31 by ituriel           #+#    #+#             */
/*   Updated: 2026/01/12 16:13:13 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

Database::Database() : dataPath("./data.csv"), exchange_rate(), inputPath("./input.txt")
{   
    dataToExch();
    mcChecker(inputPath);
    std:: cout << "Default constructor called." << std::endl;
}

Database::Database(const std::string &path) : dataPath("./data.csv"), exchange_rate(), inputPath(path)
{   
    dataToExch();
    mcChecker(inputPath);
    std::cout << "Paramterised constructor called." << std::endl;
}

Database::Database(const Database &other) : dataPath(other.dataPath), exchange_rate(other.exchange_rate), inputPath(other.inputPath)
{
    std::cout << "Copy constructor called,." << std::endl;
}

Database &Database::operator =(const Database &other)
{
    if (this != &other)
    {
        dataPath = other.dataPath;
        exchange_rate = other.exchange_rate;
        inputPath = other.inputPath;
    }
    std::cout << "Asignement operator called." << std::endl;
    return(*this);
}

Database::~Database()
{
    std::cout << "Destructor called on database." << std::endl;
}

// -----------END OF OCF ---------------

// -----------verifications ---------------

void Database::mcChecker(const std::string &path)
{
    std::fstream file;
    std::string buffer;
    unsigned int start = 0;
        file.open(path.c_str(), std::ios::in);
    if (!file.is_open())
        throw noFile();
    int line = -1;
    while (std::getline(file, buffer))
    {
        line++;
        // ---- Checking Headers ----------
        if (!start)
        {
            try
            {
                if (!buffer.empty() && buffer[buffer.length() - 1] == '\r')
                    buffer.erase(buffer.length() - 1);
                if (buffer != "date | value")
                    throw incorrectHeader(buffer);
                start = !start;
            }
            catch (const incorrectHeader &e)
            {
                std::cerr << e.what() << std::endl;
                exit(1);
            }
        }
        else
        {
        // ---- Checking Data , first Date formating using get-time ----------    
            try
            {
                size_t b_pos = buffer.find('|');
                if (b_pos != std::string::npos)
                {
                    std::string d1 = buffer.substr(0, b_pos - 1);
                    std::string value = buffer.substr(b_pos + 1);
                    std::istringstream ss(d1);
                    int year, month, day;
                    char dash1, dash2;
                    ss >> year >> dash1 >> month >> dash2 >> day;
                    if (ss.fail() || dash1 != '-' || dash2 != '-')
                        throw incorrectDate(d1);
                    if (month < 1 || month > 12 || day < 1 || day > 31)
                        throw incorrectDate(d1);
                    std::tm tm = {};
                    tm.tm_year = year - 1900;
                    tm.tm_mon = month - 1;
                    tm.tm_mday = day;
                    std::tm copy = tm;
                    std::mktime(&copy);
                    if ((tm.tm_mday == copy.tm_mday  && tm.tm_mon == copy.tm_mon 
                        && tm.tm_year == copy.tm_year))
                    {
            // ---- Checking Data , secondly values (FIND A WAY TO USE THE THROW) ----------
                        float val;
                        std::istringstream ss2(value);
                        ss2 >> val;
                        if (val < 0)
                            throw negativeValue(value);
                        else if (val > 1000)
                            throw tooHighValue(value);
                        else 
                        {
                            float result = calc(d1, val);
                            std::cout << d1 << " => " << val << " = " << result << std::endl;
                        }
                    }
                    else
                        throw incorrectDate(d1);
                }
            }
            catch (const incorrectDate &e)
            {
                std::cerr << "On line " << line << ": " << e.what() << std::endl;
                continue;
            }
            catch (const negativeValue &e)
            {
                std::cerr << "On line " << line << ": " << e.what() << std::endl;
                continue;
            }
            catch (const tooHighValue &e)
            {
                std::cerr << "On line " << line << ": " << e.what() << std::endl;
                continue;
            }
        }
        // that's my line index for throws.
    }
}

// -----------data to structure ---------------

void Database::dataToExch()
{
    std::fstream path;
    unsigned int start = 0;
    std::string buffer;
    path.open(dataPath.c_str(), std::ios::in);
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
                exchange_rate[date] = std::strtod(content.c_str(), NULL);
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

Database::negativeValue::negativeValue(const std::string &line)
{
    std::stringstream ss;
    ss << "Error: value is negative:" << line << " Should be 0 minimum.";
    value = ss.str();
}

const char *Database::negativeValue::what() const throw()
{
    return value.c_str();
}

Database::tooHighValue::tooHighValue(const std::string &line)
{
    std::stringstream ss;
    ss << "Error: value is too high:" << line << " Should be 1000 maximum.";
    value = ss.str();
}

const char *Database::tooHighValue::what() const throw()
{
    return value.c_str();
}
// -----------END OF THROWS ---------------

// ----------- search ---------------

float Database::calc(const std::string &date, float amount)
{
    std::map<std::string, float>::iterator ex_it = exchange_rate.upper_bound(date);
    if (ex_it == exchange_rate.begin())
    {
        std::cerr << "Line below doesn't have correct result because date of input is older than database oldest date." << std::endl;
        return(0);
    }
    --ex_it;
    return(amount* ex_it->second);
}
