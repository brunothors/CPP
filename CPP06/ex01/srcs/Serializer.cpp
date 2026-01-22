/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:16:52 by bnespoli          #+#    #+#             */
/*   Updated: 2026/01/22 18:17:39 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {
    std::cout << "Serializer has been constructed." << std::endl;
}

Serializer::Serializer(const Serializer& rhs) {
    std::cout << "Serializer copied." << std::endl;
    *this = rhs;
}

Serializer::~Serializer() {
    std::cout << "Serializer destroyed." << std::endl;
}

Serializer& Serializer::operator=(const Serializer& rhs) {
    (void)rhs;
    return (*this);
}

uintptr_t Serializer::serialize(Data* ptr) {
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw) {
    return (reinterpret_cast<Data*>(raw));
}