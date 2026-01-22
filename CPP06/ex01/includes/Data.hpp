/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:15:05 by bnespoli          #+#    #+#             */
/*   Updated: 2026/01/22 18:16:13 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DATA_HPP
#define DATA_HPP

#include <stdint.h>
#include <iostream>

class Data {
    private:
        uint32_t _data;

    public:
        Data();
		Data(const Data& rhs);
		~Data();
		Data& operator=(const Data& rhs);

        uint32_t getData() const;
		void setData(uint32_t data);
};

#endif