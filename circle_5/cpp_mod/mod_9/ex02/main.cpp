/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:14:37 by cauffret          #+#    #+#             */
/*   Updated: 2026/01/14 11:40:51 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


int main (int argc, char **argv)
{
    if (argc >= 2)
    {
        try 
        {
            Tester merge(argv) ;
            for (std::vector<int>::const_iterator it = merge.getVec().begin(); it != merge.getVec().end(); ++it)
                std::cout << " Vector value: " << *it << std::endl;
            for (std::deque<int>::const_iterator it = merge.getDeq().begin(); it != merge.getDeq().end(); ++it)
                std::cout << " Deque value: " << *it << std::endl;
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