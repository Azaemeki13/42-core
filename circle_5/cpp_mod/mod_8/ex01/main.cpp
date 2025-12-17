/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 09:57:38 by cauffret          #+#    #+#             */
/*   Updated: 2025/12/17 12:04:53 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

static void basicTest()
{
    std::cout << "=== Basic test ===" << std::endl;
    try
    {
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span:  " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;
}

static void tooFewNumbersTest()
{
    std::cout << "=== Too few numbers test ===" << std::endl;
    try
    {
        Span sp(3);
        sp.addNumber(42);

        std::cout << "Trying shortestSpan with only 1 number..." << std::endl;
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Caught exception (shortestSpan): " << e.what() << std::endl;
    }

    try
    {
        Span sp(3);
        sp.addNumber(10);

        std::cout << "Trying longestSpan with only 1 number..." << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Caught exception (longestSpan): " << e.what() << std::endl;
    }
    std::cout << std::endl;
}

static void addRangeVectorTest()
{
    std::cout << "=== addRange with std::vector<int> ===" << std::endl;

    std::vector<int> v;
    v.push_back(10);
    v.push_back(3);
    v.push_back(50);
    v.push_back(-4);
    v.push_back(7);

    try
    {
        Span sp(v.size());
        sp.addRange(v.begin(), v.end());

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span:  " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;
}

static void addRangeListTest()
{
    std::cout << "=== addRange with std::list<int> ===" << std::endl;

    std::list<int> lst;
    lst.push_back(100);
    lst.push_back(90);
    lst.push_back(95);
    lst.push_back(150);
    lst.push_back(120);

    try
    {
        Span sp(lst.size());
        sp.addRange(lst.begin(), lst.end());

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span:  " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;
}

static void bigTest()
{
    std::cout << "=== Big test with 10,000 numbers ===" << std::endl;

    const unsigned int N = 10000;

    // Build a vector with a known pattern
    // Example: even numbers 0, 2, 4, 6, ...
    std::vector<int> big;
    big.reserve(N);
    for (unsigned int i = 0; i < N; ++i)
        big.push_back(static_cast<int>(i * 2));

    try
    {
        Span sp(N);
        sp.addRange(big.begin(), big.end());

        unsigned int shortest = sp.shortestSpan();
        unsigned int longest  = sp.longestSpan();

        std::cout << "Shortest span (expected 2): " << shortest << std::endl;
        std::cout << "Longest span  (expected " 
                  << ( (N - 1) * 2 ) << "): " << longest << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception during bigTest: " << e.what() << std::endl;
    }
    std::cout << std::endl;
}

static void overflowTest()
{
    std::cout << "=== Overflow capacity test ===" << std::endl;

    try
    {
        Span sp(3);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);

        std::cout << "Trying to add a 4th number into capacity 3..." << std::endl;
        sp.addNumber(4); // should throw your "full" exception
    }
    catch (std::exception &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;
}

int main()
{
    basicTest();
    tooFewNumbersTest();
    addRangeVectorTest();
    addRangeListTest();
    bigTest();
    overflowTest();
    return 0;
}