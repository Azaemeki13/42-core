/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 13:26:06 by cauffret          #+#    #+#             */
/*   Updated: 2026/01/12 16:07:00 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main (int argc, char **argv)
{
    if (argc == 2)
        Database db(argv[1]);
    else 
        std::cout << "Please provide one and only file." << std::endl;
    return(1);
}