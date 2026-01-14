/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 09:38:05 by cauffret          #+#    #+#             */
/*   Updated: 2026/01/14 14:53:17 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// ---------------------------- OCF-------------------------------------------------------------

Tester::Tester() : parseVector(), _vpairs(), _vwinners(), _vlosers(), _vleftover(0), _vhasLeftover(0), parseDeque(), _dpairs(), _dwinners(), _dlosers(), _dleftover(0), _dhasLeftover(0)
{
    std::cout << "Default constructor called." << std::endl;
}

Tester::Tester(char **argv) : parseVector(), _vpairs(), _vwinners(), _vlosers(), _vleftover(0), _vhasLeftover(0), parseDeque(), _dpairs(), _dwinners(), _dlosers(), _dleftover(0), _dhasLeftover(0)
{

    toParser(argv);
    std::cout << " Parameterised constructor called." << std::endl;

}

Tester::Tester(const Tester &other) : parseVector(other.parseVector), _vpairs(other._vpairs), _vwinners(other._vwinners), _vlosers(other._vlosers), _vleftover(other._vleftover), _vhasLeftover(other._vhasLeftover), parseDeque(other.parseDeque), _dpairs(other._dpairs), _dwinners(other._dwinners), _dlosers(other._dlosers), _dleftover(other._dleftover), _dhasLeftover(other._dhasLeftover)
{
    std::cout << "Copy constructor called." << std::endl;
}

Tester &Tester::operator =(const Tester &other)
{
    if (this != &other)
    {
        parseVector = other.parseVector;
        _vpairs = other._vpairs;
        _vwinners = other. _vwinners;
        _vlosers = other._vlosers;
        _vleftover = other._vleftover;
        _vhasLeftover = other._vhasLeftover;
        parseDeque = other.parseDeque;
        _dpairs = other._dpairs;
        _dwinners = other._dwinners;
        _dlosers = other._dlosers;
        _dleftover = other._dleftover;
        _dhasLeftover = other._dhasLeftover;
    }
    std::cout << "Assignement operator called." << std::endl;
    return (*this);
}

Tester::~Tester()
{
    std::cout << "Destructor called." << std::endl;
}

// getters

const std::vector<int>&  Tester::getVec() const
{
    return(this->parseVector);
}

const std::deque<int>&  Tester::getDeq() const
{
    return(this->parseDeque);
}

// Functions

void Tester::toParser(char **argv)
{
    for (int i = 1; argv[i]; ++i)
    {
        std::string str = argv[i];
        if (str.empty())
            throw std::runtime_error("String is empty !");
        for (size_t j = 0; j < str.length() ; ++j)
        {
            if (!std::isdigit(str[j]))
            {
                if (str[j] != '+')
                    throw std::runtime_error("String has forbidden characters");
                else if (j != 0 || str.length() == 1)
                    throw std::runtime_error("Wrong '+' position.");
            }
        }
        char *end;
        long value = std::strtol(argv[i], &end, 10);
        if (*end != '\0')
            throw std::runtime_error("Garbage at the end of argument.");
        if (value > INT_MAX || value < 0)
            throw std::runtime_error("Number is off limits.");
        parseVector.push_back(static_cast<int> (value));
        parseDeque.push_back(static_cast<int> (value));
    }
    if ((parseVector.size()) % 2 != 0)
    {
        _vhasLeftover = 1;
        _vleftover = parseVector.back();
        parseVector.pop_back();
    }
    if ((parseDeque.size()) % 2 != 0)
    {
        _dhasLeftover = 1;
        _dleftover = parseDeque.back();
        parseDeque.pop_back();
    }
}

void Tester::vToQueue()
{
    for (std::vector<int>::iterator it_vparser = parseVector.begin(); it_vparser != parseVector.end(); it_vparser += 2)
    {
        int first = *(it_vparser);
        int second = *(it_vparser + 1);
        if (first > second)
        {
            _vwinners.push_back(first);
            _vlosers.push_back(second);
            _vpairs.push_back(std::make_pair(first, second));
        }
        else
        {
            _vwinners.push_back(second);
            _vlosers.push_back(first);
            _vpairs.push_back(std::make_pair(second, first));
        }
    }
}

std::vector<std::pair<int, int > > Tester::vRecursive(std::vector<std::pair<int, int> > input)
{
    
    std::vector<std::pair<int, int> > result_w;
    std::vector<std::pair<int, int> > result_l;
    if (input.size() < 2)
        return(input);
    else
    {
        for(std::vector<std::pair<int, int> >::iterator it = input.begin(); it != input.end(); it += 2)
        {
            int first = it->first;
            int second = (it + 1)->first;
            if (first > second)
            {
                result_w.push_back(*it);
                result_l.push_back(*(it + 1));
            }
            else
            {
                result_w.push_back(*(it + 1));
                result_l.push_back(*it);
            }
        }
    }
    std::vector<std::pair<int, int> > main_sort = vRecursive(result_w);
    std::vector<int> just_chain;
    for (size_t i = 0; i < main_sort.size(); ++i)
        just_chain.push_back(main_sort[i].first);

    // my loser insertion logic here ! 
    
    return(main_sort);
}

void Tester::dToQueue()
{
    for (std::deque<int>::iterator it_dparser = parseDeque.begin(); it_dparser != parseDeque.end(); it_dparser += 2)
    {
        int first = *(it_dparser);
        int second = *(it_dparser + 1);
        if (first > second)
        {
            _dwinners.push_back(first);
            _dlosers.push_back(second);
            _dpairs.push_back(std::make_pair(first, second));
        }
        else
        {
            _dwinners.push_back(second);
            _dlosers.push_back(first);
            _dpairs.push_back(std::make_pair(second, first));
        }
    }
}
