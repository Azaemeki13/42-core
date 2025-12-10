/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 11:01:53 by ituriel           #+#    #+#             */
/*   Updated: 2025/12/10 14:41:54 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <sstream>
#include <cctype>
#include <limits>
#include <exception>
#include <cmath>

class ScalarConverter
{
    private:
    // ocf mdr
        ScalarConverter();
        ScalarConverter(const ScalarConverter &);
        ScalarConverter &operator=(const ScalarConverter &);
        ~ScalarConverter();
    // what a nice mess
        static char intToChar(int i);
        static int stringToInt(const std::string &s);
        static float stringToFloat(const std::string &s);
        static double stringToDouble(const std::string &s);
        static std::string &trimmString(std::string &conv);
        static bool isPLitteral(const std::string &conv);
        static void printImpossibles(void);
        static void printFloat(const float &f);
        static void printDouble(const double &d);
        class nonDisplayable : public std::exception{};
        class isImpossible : public std::exception{};
    public:
        static void convert(std::string &conv);
};