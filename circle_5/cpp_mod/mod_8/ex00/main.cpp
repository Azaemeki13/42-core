/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:12:30 by ituriel           #+#    #+#             */
/*   Updated: 2025/12/16 12:13:17 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

static void testVector()
{
    std::cout << "=== std::vector<int> ===" << std::endl;

    std::vector<int> v;
    for (int i = 0; i < 5; ++i)
        v.push_back(i * 10); // 0, 10, 20, 30, 40

    std::cout << "Vector contents: ";
    for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    // Value present
    try
    {
        std::vector<int>::iterator it = easyfind(v, 20);
        std::cout << "Found 20 in vector: *it = " << *it << std::endl;

        // Show we can modify through the iterator
        *it = 999;
        std::cout << "After *it = 999, vector: ";
        for (std::vector<int>::const_iterator cit = v.begin(); cit != v.end(); ++cit)
            std::cout << *cit << " ";
        std::cout << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception (vector, 20): " << e.what() << std::endl;
    }

    // Value absent
    try
    {
        std::vector<int>::iterator it = easyfind(v, 42);
        std::cout << "Found 42 in vector: *it = " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception (vector, 42): " << e.what() << std::endl;
    }

    std::cout << std::endl;
}

static void testList()
{
    std::cout << "=== std::list<int> ===" << std::endl;

    std::list<int> lst;
    lst.push_back(3);
    lst.push_back(6);
    lst.push_back(9);

    std::cout << "List contents: ";
    for (std::list<int>::const_iterator it = lst.begin(); it != lst.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    // Value present
    try
    {
        std::list<int>::iterator it = easyfind(lst, 6);
        std::cout << "Found 6 in list: *it = " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception (list, 6): " << e.what() << std::endl;
    }

    // Value absent
    try
    {
        std::list<int>::iterator it = easyfind(lst, 7);
        std::cout << "Found 7 in list: *it = " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception (list, 7): " << e.what() << std::endl;
    }

    std::cout << std::endl;
}

static void testEmpty()
{
    std::cout << "=== Empty std::vector<int> ===" << std::endl;

    std::vector<int> empty;

    try
    {
        easyfind(empty, 1);
        std::cout << "Found 1 in empty vector (this should not happen)" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception (empty): " << e.what() << std::endl;
    }

    std::cout << std::endl;
}

int main()
{
    testVector();
    testList();
    testEmpty();
    return 0;
}