/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 10:28:45 by ituriel           #+#    #+#             */
/*   Updated: 2025/12/11 10:31:27 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
    Data data;
    data.value = 42;
    data.name = "Hello serializer";
    // Original pointer
    Data *ptr = &data;
    std::cout << "Original Data address : " << ptr << std::endl;
    std::cout << "Original Data value   : " << ptr->value << std::endl;
    std::cout << "Original Data name    : " << ptr->name << std::endl;
    // Serialize pointer -> uintptr_t
    uintptr_t raw = Serializer::serialize(ptr);
    std::cout << "\nSerialized uintptr_t  : " << raw << std::endl;
    // Deserialize uintptr_t -> Data*
    Data *back = Serializer::deserialize(raw);
    std::cout << "\nDeserialized address  : " << back << std::endl;
    std::cout << "Deserialized value    : " << back->value << std::endl;
    std::cout << "Deserialized name     : " << back->name << std::endl;
    // Extra check: modify via back and see it reflected in original
    back->value = 1337;
    back->name = "Modified via back";
    std::cout << "\nAfter modification through deserialized pointer:" << std::endl;
    std::cout << "Original Data value   : " << data.value << std::endl;
    std::cout << "Original Data name    : " << data.name << std::endl;
    return 0;
}
