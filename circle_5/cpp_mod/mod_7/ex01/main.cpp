/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 10:29:17 by ituriel           #+#    #+#             */
/*   Updated: 2025/12/15 10:34:04 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void)
{
    std::cout << "=== int array (non-const) ===" << std::endl;
    int intArr[5] = {1, 2, 3, 4, 5};
    std::cout << "Original:  ";
    iter(intArr, 5, printConst<int>);
    std::cout << std::endl;
    std::cout << "Increment: ";
    iter(intArr, 5, increment<int>);
    iter(intArr, 5, printConst<int>);
    std::cout << std::endl << std::endl;
    std::cout << "=== const int array ===" << std::endl;
    const int constIntArr[3] = {10, 20, 30};
    std::cout << "Print (const ref): ";
    iter(constIntArr, 3, printConst<int>);
    std::cout << std::endl << std::endl;
    std::cout << "=== std::string array ===" << std::endl;
    std::string strArr[3] = {"Hello", "iter", "template"};
    std::cout << "Strings: ";
    iter(strArr, 3, printConst<std::string>);
    std::cout << std::endl;
    // if we uncomment, we try to modify a const array, see the compile bug :)
    // iter(constIntArr, 3, increment<int>);
    return 0;
}