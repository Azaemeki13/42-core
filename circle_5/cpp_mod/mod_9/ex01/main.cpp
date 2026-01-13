/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 09:39:54 by cauffret          #+#    #+#             */
/*   Updated: 2026/01/13 13:05:53 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Please only input ONE expression." << std::endl;
        return(0);
    }
    else
    {
        try
        {
            RPN notation (argv[1]) ;
            std::cout << "The result is: " << notation.showResult() << std::endl;
        }
        catch (std::exception &e)
        {
            std::cerr << "Error:" << e.what() << std::endl;
            return(0);
        }
    }
    return(1);
}