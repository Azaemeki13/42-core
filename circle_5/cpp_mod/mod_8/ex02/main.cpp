/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 13:12:54 by cauffret          #+#    #+#             */
/*   Updated: 2025/12/17 13:17:18 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

static void basicIntTest()
{
    std::cout << "=== Basic MutantStack<int> test ===" << std::endl;

    MutantStack<int> mstack;

    // Stack operations
    mstack.push(5);
    mstack.push(17);

    std::cout << "Top element (expected 17): " << mstack.top() << std::endl;

    mstack.pop();
    std::cout << "Size after pop (expected 1): " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "Size before iteration: " << mstack.size() << std::endl;

    // Iteration
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    std::cout << "Stack contents (from bottom to top): ";
    for (; it != ite; ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::cout << "Top element at the end (expected 0): " << mstack.top() << std::endl;
    std::cout << std::endl;
}

static void copyAndAssignTest()
{
    std::cout << "=== Copy & assignment test ===" << std::endl;

    MutantStack<int> original;
    original.push(1);
    original.push(2);
    original.push(3);

    // Copy constructor
    MutantStack<int> copy(original);

    std::cout << "Original contents: ";
    for (MutantStack<int>::iterator it = original.begin();
         it != original.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::cout << "Copy contents:     ";
    for (MutantStack<int>::iterator it = copy.begin();
         it != copy.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    // Modify copy, original should stay unchanged
    copy.pop();
    copy.push(42);

    std::cout << "After modifying copy:" << std::endl;

    std::cout << "Original contents: ";
    for (MutantStack<int>::iterator it = original.begin();
         it != original.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::cout << "Copy contents:     ";
    for (MutantStack<int>::iterator it = copy.begin();
         it != copy.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::cout << std::endl;
}

static void compatibilityWithStdStack()
{
    std::cout << "=== Compatibility with std::stack ===" << std::endl;

    MutantStack<int> mstack;
    mstack.push(10);
    mstack.push(20);
    mstack.push(30);

    std::stack<int> s(mstack); // std::stack can be constructed from MutantStack

    std::cout << "std::stack top (expected 30): " << s.top() << std::endl;
    s.pop();
    std::cout << "std::stack top after pop (expected 20): " << s.top() << std::endl;

    std::cout << std::endl;
}

int main()
{
    basicIntTest();
    copyAndAssignTest();
    compatibilityWithStdStack();
    return 0;
}