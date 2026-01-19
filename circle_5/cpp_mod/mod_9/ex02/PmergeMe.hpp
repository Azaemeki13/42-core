/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 09:38:07 by cauffret          #+#    #+#             */
/*   Updated: 2026/01/19 13:14:09 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
    #define PMERGEME_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <iterator>
#include <vector>
#include <deque>
#include <stdexcept>
#include <climits>
#include <cstdlib>
#include <sys/time.h>
#include <iomanip>

class Tester
{
    private:
    // vector
        std::vector<int> parseVector;
        std::vector <std::pair<int, int> > _vpairs;
        std::vector<int> _vwinners;
        std::vector<int> _vlosers;

    // deque
        std::deque<int> parseDeque;
        std::deque<std::pair<int, int> > _dpairs;
        std::deque<int> _dwinners;
        std::deque<int> _dlosers;

    public:
    // OCF
        Tester();
        Tester(char **args);
        Tester(const Tester &other);
        Tester &operator =(const Tester &other);
        ~Tester();
    // getters n setters 
        const std::vector<int>& getVec() const;
        const std::deque<int>& getDeq() const;
    // functions 
            void toParser(char **argv);
            void vToQueue();
            std::vector<std::pair<int, int > > vRecursive(std::vector<std::pair<int, int> > input);
            void dToQueue();
            std::deque<std::pair<int, int> > dRecursive(std::deque<std::pair<int, int> > input);
            unsigned int findJacob(unsigned int n);
            void compareMe();
            void printMe(std::vector<std::pair <int, int> > vecty);
};


#endif