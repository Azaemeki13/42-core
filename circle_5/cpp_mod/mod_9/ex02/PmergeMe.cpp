/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 09:38:05 by cauffret          #+#    #+#             */
/*   Updated: 2026/01/19 14:25:03 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// ---------------------------- OCF-------------------------------------------------------------

Tester::Tester() : parseVector(), _vpairs(), _vwinners(), _vlosers(), parseDeque(), _dpairs(), _dwinners(), _dlosers()
{
    std::cout << "Default constructor called." << std::endl;
}

Tester::Tester(char **argv) : parseVector(), _vpairs(), _vwinners(), _vlosers(), parseDeque(), _dpairs(), _dwinners(), _dlosers()
{

    toParser(argv);
    std::cout << " Parameterised constructor called." << std::endl;

}

Tester::Tester(const Tester &other) : parseVector(other.parseVector), _vpairs(other._vpairs), _vwinners(other._vwinners), _vlosers(other._vlosers), parseDeque(other.parseDeque), _dpairs(other._dpairs), _dwinners(other._dwinners), _dlosers(other._dlosers)
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
        parseDeque = other.parseDeque;
        _dpairs = other._dpairs;
        _dwinners = other._dwinners;
        _dlosers = other._dlosers;
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
        for (std::vector<int>::iterator it = parseVector.begin(); it != parseVector.end(); ++it)
        {
            if (*it == static_cast<int>(value))
                throw std::runtime_error("Duplicate numbers not allowed.");
        }
        parseVector.push_back(static_cast<int> (value));
        parseDeque.push_back(static_cast<int> (value));
    }
}

void Tester::vToQueue()
{
    for (std::vector<int>::iterator it_vparser = parseVector.begin(); it_vparser != parseVector.end() && (it_vparser + 1) != parseVector.end(); it_vparser += 2)
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

std::vector<int> Tester::vRecursive(std::vector<int> input)
{
    static const long long jacob_array[] = {0, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923};
    std::vector<long long> jacob_vec(jacob_array, jacob_array + sizeof(jacob_array) / sizeof(jacob_array[0]));
    int straggler = -1;
    bool has_straggler = false;
    if (input.size() % 2 != 0)
    {
        straggler = input.back();
        has_straggler = true;
        input.pop_back();
    }
    if (input.size() < 2)
    {
        if (has_straggler)
        {
            if (input.empty())
                input.push_back(straggler);
            else if (straggler < input[0])
                input.insert(input.begin(), straggler);
            else
                input.push_back(straggler);
        }
        return(input);
    }
    std::vector<int> winners;
    std::vector<int> losers;
    for (size_t i = 0; i < input.size(); i += 2)
    {
        if (input[i] > input[i + 1])
        {
            winners.push_back(input[i]);
            losers.push_back(input[i + 1]);
        }
        else
        {
            winners.push_back(input[i + 1]);
            losers.push_back(input[i]);
        }
    }
    std::vector<std::pair<int, int> > winner_to_loser;
    for (size_t i = 0; i < winners.size(); ++i)
        winner_to_loser.push_back(std::make_pair(winners[i], losers[i]));
    std::vector<int> sorted_winners = vRecursive(winners);
    std::vector<int> reordered_losers;
    for (size_t i = 0; i < sorted_winners.size(); ++i)
    {
        for (size_t j = 0; j < winner_to_loser.size(); ++j)
        {
            if (winner_to_loser[j].first == sorted_winners[i])
            {
                reordered_losers.push_back(winner_to_loser[j].second);
                break;
            }
        }
    }
    std::vector<int> chain(sorted_winners);
    if (!reordered_losers.empty())
        chain.insert(chain.begin(), reordered_losers[0]);
    size_t last_j = 1;
    for (size_t i = 2; i < jacob_vec.size(); ++i)
    {
        size_t curr_j = jacob_vec[i];
        size_t actual_end = std::min(curr_j, reordered_losers.size());
        for (size_t k = actual_end; k > last_j; --k)
        {
            int loser_value = reordered_losers[k - 1];
            int winner_value = sorted_winners[k - 1];
            std::vector<int>::iterator it_w = std::lower_bound(chain.begin(), chain.end(), winner_value);
            std::vector<int>::iterator it_l = std::lower_bound(chain.begin(), it_w, loser_value);
            chain.insert(it_l, loser_value);
        }
        last_j = actual_end;
        if (last_j >= reordered_losers.size())
            break;
    }
    if (has_straggler)
    {
        std::vector<int>::iterator stag_it = std::lower_bound(chain.begin(), chain.end(), straggler);
        chain.insert(stag_it, straggler);
    }
    return(chain);
}

void Tester::dToQueue()
{
    for (std::deque<int>::iterator it_dparser = parseDeque.begin(); it_dparser != parseDeque.end() && (it_dparser + 1) != parseDeque.end() ; it_dparser += 2)
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

std::deque<int> Tester::dRecursive(std::deque<int> input)
{
    static const long long jacob_array[] = {0, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923};
    std::deque<long long> jacob_deq(jacob_array, jacob_array + sizeof(jacob_array) / sizeof(jacob_array[0]));
    int straggler = -1;
    bool has_straggler = false;
    if (input.size() % 2 != 0)
    {
        straggler = input.back();
        has_straggler = true;
        input.pop_back();
    }
    if (input.size() < 2)
    {
        if (has_straggler)
        {
            if (input.empty())
                input.push_back(straggler);
            else if (straggler < input[0])
                input.insert(input.begin(), straggler);
            else
                input.push_back(straggler);
        }
        return(input);
    }
    std::deque<int> winners;
    std::deque<int> losers;
    for (size_t i = 0; i < input.size(); i += 2)
    {
        if (input[i] > input[i + 1])
        {
            winners.push_back(input[i]);
            losers.push_back(input[i + 1]);
        }
        else
        {
            winners.push_back(input[i + 1]);
            losers.push_back(input[i]);
        }
    }
    std::deque<std::pair<int, int> > winner_to_loser;
    for (size_t i = 0; i < winners.size(); ++i)
        winner_to_loser.push_back(std::make_pair(winners[i], losers[i]));
    std::deque<int> sorted_winners = dRecursive(winners);
    std::deque<int> reordered_losers;
    for (size_t i = 0; i < sorted_winners.size(); ++i)
    {
        for (size_t j = 0; j < winner_to_loser.size(); ++j)
        {
            if (winner_to_loser[j].first == sorted_winners[i])
            {
                reordered_losers.push_back(winner_to_loser[j].second);
                break;
            }
        }
    }
    std::deque<int> chain(sorted_winners);
    if (!reordered_losers.empty())
        chain.insert(chain.begin(), reordered_losers[0]);
    size_t last_j = 1;
    for (size_t i = 2; i < jacob_deq.size(); ++i)
    {
        size_t curr_j = jacob_deq[i];
        size_t actual_end = std::min(curr_j, reordered_losers.size());
        for (size_t k = actual_end; k > last_j; --k)
        {
            int loser_value = reordered_losers[k - 1];
            int winner_value = sorted_winners[k - 1];
            std::deque<int>::iterator it_w = std::lower_bound(chain.begin(), chain.end(), winner_value);
            std::deque<int>::iterator it_l = std::lower_bound(chain.begin(), it_w, loser_value);
            chain.insert(it_l, loser_value);
        }
        last_j = actual_end;
        if (last_j >= reordered_losers.size())
            break;
    }
    if (has_straggler)
    {
        std::deque<int>::iterator stag_it = std::lower_bound(chain.begin(), chain.end(), straggler);
        chain.insert(stag_it, straggler);
    }
    return(chain);
}

void Tester::printMe(std::vector<int> vecty)
{
    std::cout << "Before: ";
    for (size_t i = 0; i < parseVector.size(); ++i)
        std::cout << parseVector[i] << " ";
    std::cout << std::endl;
    std::cout << "After: ";
    for (size_t i = 0; i < vecty.size(); ++i)
        std::cout << vecty[i] << " ";
    std::cout << std::endl;
}

void Tester::compareMe()
{
    struct timeval startv, endv, startd, endd;
    gettimeofday(&startv, NULL);
    std::vector<int> vecty = vRecursive(parseVector);
    gettimeofday(&endv, NULL);
    gettimeofday(&startd, NULL);
    std::deque<int> decty = dRecursive(parseDeque);
    gettimeofday(&endd, NULL);
    printMe(vecty);
    long vseconds = endv.tv_sec - startv.tv_sec;
    long vmicrosec = endv.tv_usec - startv.tv_usec;
    double vtotal_time = (vseconds * 1000000.0) + vmicrosec;
    long dseconds = endd.tv_sec - startd.tv_sec;
    long dmicrosec = endd.tv_usec - startd.tv_usec;
    double dtotal_time = (dseconds * 1000000.0) + dmicrosec;
    std::cout << "Time to process a range of " << parseVector.size() << " elements with std::vector: " << vtotal_time << "us." << std::endl;
    std::cout << "Time to process a range of " << parseDeque.size() << " elements with std::deque: " << dtotal_time << "us." << std::endl;
}
