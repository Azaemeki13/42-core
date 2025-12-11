/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 10:08:35 by ituriel           #+#    #+#             */
/*   Updated: 2025/12/11 10:29:45 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
    #define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <stdint.h>

struct Data
{
    std::string name;
    unsigned int value;
};

class Serializer
{
    private:
    // ocf mdr
        Serializer();
        Serializer(std::string parameter);
        Serializer(const Serializer &other);
        Serializer &operator =(const Serializer &other);
        ~Serializer();
    public:
        static uintptr_t serialize(Data *ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif