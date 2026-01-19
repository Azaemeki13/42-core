/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:14:37 by cauffret          #+#    #+#             */
/*   Updated: 2026/01/19 13:14:08 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


int main (int argc, char **argv)
{
    if (argc >= 2)
    {
        try 
        {
            Tester merge(argv);
            merge.compareMe();
        }
        catch (std::runtime_error &e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
            return(1);
        }
    }
    else
    {
        std::cerr << "Not enough arguments." << std::endl;
        return(1);
    }
    return(0);
}