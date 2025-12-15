/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 11:28:30 by ituriel           #+#    #+#             */
/*   Updated: 2025/12/15 11:47:28 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void)
{
    std::cout << "=== Default constructor ===" << std::endl;
    Array<int> a;
    std::cout << "a.size() = " << a.size() << std::endl;
    try
    {
        std::cout << "Trying a[0] on empty array..." << std::endl;
        std::cout << a[0] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Size constructor (5) ===" << std::endl;
    Array<int> b(5);
    std::cout << "b.size() = " << b.size() << std::endl;

    for (unsigned int i = 0; i < b.size(); ++i)
        b[i] = static_cast<int>(i * 10);

    std::cout << "b contents: ";
    for (unsigned int i = 0; i < b.size(); ++i)
        std::cout << b[i] << " ";
    std::cout << std::endl;

    std::cout << "\n=== Copy constructor ===" << std::endl;
    Array<int> c(b);
    std::cout << "c.size() = " << c.size() << std::endl;

    std::cout << "c contents (copied from b): ";
    for (unsigned int i = 0; i < c.size(); ++i)
        std::cout << c[i] << " ";
    std::cout << std::endl;

    // Modify c and check b is unchanged
    if (c.size() > 0)
        c[0] = 999;

    std::cout << "After modifying c[0] = 999:" << std::endl;
    std::cout << "b[0] = " << b[0] << " (should NOT be 999)" << std::endl;
    std::cout << "c[0] = " << c[0] << " (should be 999)" << std::endl;

    std::cout << "\n=== Assignment operator ===" << std::endl;
    Array<int> d;
    d = c;
    std::cout << "d.size() = " << d.size() << std::endl;

    std::cout << "d contents (copied from c): ";
    for (unsigned int i = 0; i < d.size(); ++i)
        std::cout << d[i] << " ";
    std::cout << std::endl;

    // Modify d and check c is unchanged
    if (d.size() > 1)
        d[1] = 555;

    std::cout << "After modifying d[1] = 555:" << std::endl;
    std::cout << "c[1] = " << c[1] << " (should NOT be 555)" << std::endl;
    std::cout << "d[1] = " << d[1] << " (should be 555)" << std::endl;

    std::cout << "\n=== Const Array + operator[] const ===" << std::endl;
    const Array<int> e(d);
    std::cout << "e.size() = " << e.size() << std::endl;
    std::cout << "e contents (const): ";
    for (unsigned int i = 0; i < e.size(); ++i)
        std::cout << e[i] << " ";
    std::cout << std::endl;

    std::cout << "\n=== Out of bounds access ===" << std::endl;
    try
    {
        std::cout << "Trying b[42]..." << std::endl;
        std::cout << b[42] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Array<std::string> test ===" << std::endl;
    Array<std::string> s(3);
    s[0] = "Hello";
    s[1] = "Array";
    s[2] = "Template";

    std::cout << "s.size() = " << s.size() << std::endl;
    std::cout << "s contents: ";
    for (unsigned int i = 0; i < s.size(); ++i)
        std::cout << s[i] << " ";
    std::cout << std::endl;

    return 0;
}
