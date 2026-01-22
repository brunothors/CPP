/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:15:02 by bnespoli          #+#    #+#             */
/*   Updated: 2026/01/22 18:16:21 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"

class Serializer {
    private:
        Serializer();
        Serializer(const Serializer& rhs);
        ~Serializer();
        Serializer& operator=(const Serializer& rhs);

    public:
        static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif