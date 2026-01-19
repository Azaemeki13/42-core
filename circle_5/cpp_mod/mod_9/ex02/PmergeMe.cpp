/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 09:38:05 by cauffret          #+#    #+#             */
/*   Updated: 2026/01/19 13:23:28 by cauffret         ###   ########.fr       */
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

std::vector<std::pair<int, int > > Tester::vRecursive(std::vector<std::pair<int, int> > input)
{
    std::vector<std::pair<int, int> > result_w;
    std::vector<std::pair<int, int> > result_l;
    static const long long jacob_array[] = {0, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923};
    std::vector<long long> jacob_vec(jacob_array, jacob_array + sizeof(jacob_array) / sizeof(jacob_array[0]));
    std::pair<int, int> straggler;
    bool has_straggler = 0;
    if (input.size() % 2 != 0)
    {
        straggler = input.back();
        has_straggler = 1;
        input.pop_back();
    }
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
    if(!result_l.empty())
        just_chain.insert(just_chain.begin(), result_l[0].first);
    size_t last_j  = 1; // start at 1 because we previously did term 1, also sets min value of Jn we want to go at, from Jupper_boud to Jlower_bound
    for(size_t i = 2; i < jacob_vec.size(); ++i) // browsing jacobsthal
    {
        size_t curr_j = jacob_vec[i]; // current jacobsthal term J(n)
        size_t actual_end = std::min(curr_j, result_l.size()); // make sure that we have the min value to not go OOB
        for (size_t k = actual_end; k > last_j; --k)
        {
            int loser_value = result_l[k - 1].first; // need to find the loser 
            int winner_value = result_w[k - 1].first; // need to find the winner (same index be cause same time comparaison)
            std::vector<int>::iterator it_w = std::lower_bound(just_chain.begin(), just_chain.end(), winner_value); // lower bound IS binary search and returns the slot in just chain that is the winner's.
            std::vector<int>::iterator it_l = std::lower_bound(just_chain.begin(), it_w, loser_value); // EXACTLY WHERE TO INSERT THE LOSER
            just_chain.insert(it_l, loser_value);
        }
        last_j = actual_end;
        if(last_j  >= result_l.size())
            break;
    }
    if (has_straggler)
    {
        std::vector<int>::iterator stag_it = std::lower_bound(just_chain.begin(), just_chain.end(), straggler.first);
        just_chain.insert(stag_it, straggler.first);

    }
    std::vector<std::pair <int, int> > ret_final;
    for(size_t i = 0; i < just_chain.size(); ++i)
        ret_final.push_back(std::make_pair(just_chain[i], 0));
    return(ret_final);
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

std::deque<std::pair<int, int > > Tester::dRecursive(std::deque<std::pair<int, int> > input)
{
    std::deque<std::pair<int, int> > result_w;
    std::deque<std::pair<int, int> > result_l;
    static const long long jacob_array[] = {0, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923};
    std::deque<long long> jacob_deq(jacob_array, jacob_array + sizeof(jacob_array) / sizeof(jacob_array[0]));
    std::pair<int, int> straggler;
    bool has_straggler = 0;
    if (input.size() % 2 != 0)
    {
        straggler = input.back();
        has_straggler = 1;
        input.pop_back();
    }
    if (input.size() < 2)
        return(input);
    else
    {
        for(std::deque<std::pair<int, int> >::iterator it = input.begin(); it != input.end(); it += 2)
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
    std::deque<std::pair<int, int> > main_sort = dRecursive(result_w);
    std::deque<int> just_chain;
    for (size_t i = 0; i < main_sort.size(); ++i)
        just_chain.push_back(main_sort[i].first);
    if(!result_l.empty())
        just_chain.insert(just_chain.begin(), result_l[0].first);
    size_t last_j  = 1; // start at 1 because we previously did term 1, also sets min value of Jn we want to go at, from Jupper_boud to Jlower_bound
    for(size_t i = 2; i < jacob_deq.size(); ++i) // browsing jacobsthal
    {
        size_t curr_j = jacob_deq[i]; // current jacobsthal term J(n)
        size_t actual_end = std::min(curr_j, result_l.size()); // make sure that we have the min value to not go OOB
        for (size_t k = actual_end; k > last_j; --k)
        {
            int loser_value = result_l[k - 1].first; // need to find the loser 
            int winner_value = result_w[k - 1].first; // need to find the winner (same index be cause same time comparaison)
            std::deque<int>::iterator it_w = std::lower_bound(just_chain.begin(), just_chain.end(), winner_value); // lower bound IS binary search and returns the slot in just chain that is the winner's.
            std::deque<int>::iterator it_l = std::lower_bound(just_chain.begin(), it_w, loser_value); // EXACTLY WHERE TO INSERT THE LOSER
            just_chain.insert(it_l, loser_value);
        }
        last_j = actual_end;
        if(last_j  >= result_l.size())
            break;
    }
    if (has_straggler)
    {
        std::deque<int>::iterator stag_it = std::lower_bound(just_chain.begin(), just_chain.end(), straggler.first);
        just_chain.insert(stag_it, straggler.first);

    }
    std::deque<std::pair <int, int> > ret_final;
    for(size_t i = 0; i < just_chain.size(); ++i)
        ret_final.push_back(std::make_pair(just_chain[i], 0));
    return(ret_final);
}

void Tester::printMe(std::vector<std::pair <int, int> > vecty)
{
    std::cout << "Before: ";
    for (size_t i = 0; i < parseVector.size() && i < 5; ++i)
        std::cout << parseVector[i] << " ";
    std::cout << std::endl;
    std::cout << "After: ";
    for (size_t i = 0; i < vecty.size() && i < 5; ++i)
        std::cout << vecty[i].first << " ";
    std::cout << std::endl;
}

void Tester::compareMe()
{
    struct timeval startv, endv, startd, endd;
    gettimeofday(&startv, NULL);
    vToQueue();
    std::vector<std::pair<int, int> > vecty = vRecursive(_vpairs);
    gettimeofday(&endv, NULL);
    gettimeofday(&startd, NULL);
    dToQueue();
    std::deque<std::pair <int, int> > decty = dRecursive(_dpairs);
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