/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 12:46:36 by ituriel           #+#    #+#             */
/*   Updated: 2026/01/12 16:19:43 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <map>
#include <exception>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

class Database
{
    private:
        std::string dataPath;
        std::map<std::string, float> exchange_rate;
        std::string inputPath;

    public:
        // OCF 
        Database();
        Database(const std::string &path);
        Database(const Database &other);
        Database &operator =(const Database &other);
        ~Database();

        //checker
        void mcChecker(const std::string &path);

        // file2struct
        void dataToExch();

        // errors
        class noFile : public std::exception { public : virtual const char *what() const throw(); };
        class incorrectParsing : public std::exception
        {
            private:
                std::string message;
            public:
                incorrectParsing(const std::string &line);
                virtual ~incorrectParsing() throw() {};
                virtual const char *what() const throw();
        };
        class incorrectHeader : public std::exception
        {
            private:
                std::string header;
            public:
                incorrectHeader(const std::string &line);
                virtual ~incorrectHeader() throw() {};
                virtual const char *what() const throw();
        };
        class incorrectDate : public std::exception
        {
            private:
                std::string date;
            public :
                incorrectDate(const std::string &line);
                virtual ~incorrectDate() throw() {};
                virtual const char *what() const throw(); 
        };
        class negativeValue : public std::exception
        {
            private:
                std::string value;
            public :
                negativeValue(const std::string &line);
                virtual ~negativeValue() throw() {};
                virtual const char *what() const throw();
        };
        class tooHighValue : public std::exception
        {
            private:
                std::string value;
            public :
                tooHighValue(const std::string &line);
                virtual ~tooHighValue() throw() {};
                virtual const char *what() const throw();
        };
        // display && function
        float calc(const std::string &date, float value);
};