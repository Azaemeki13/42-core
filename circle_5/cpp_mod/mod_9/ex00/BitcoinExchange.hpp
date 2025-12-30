/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 12:46:36 by ituriel           #+#    #+#             */
/*   Updated: 2025/12/30 13:57:53 by ituriel          ###   ########.fr       */
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

class Database
{
    private:
        std::map<std::string, float> exchange_rate;
        std::map<std::string, float> input;

    public:
        // OCF 
        Database();
        Database(const std::string &path);
        Database(const Database &other);
        Database &operator =(const Database &other);
        ~Database();

        // errors
        class noFile : public std::exception { public : virtual const char *what() const throw(); };
        class incorrectParsing : public std::exception
        {
            private:
                std::string message;
            public:
                incorrectParsing(const std::string &line);
                virtual const char *what() const throw();
        };
        class incorrectDate : public std::exception
        {
            private:
                std::string date;
            public :
                incorrectDate(const std::string &line);
                virtual const char *what() const throw(); 
        };
        class negativeValue : public std::exception
        {
            private:
                std::string value;
            public :
                negativeValue(const std::string &line);
                virtual const char *what() const throw();
        };
        class tooHighValue : public std::exception
        {
            private:
                std::string value;
            public :
                tooHighValue(const std::string &line);
                virtual const char *what() const throw();
        };

};
