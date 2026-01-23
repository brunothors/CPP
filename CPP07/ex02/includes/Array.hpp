/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 18:22:36 by bnespoli          #+#    #+#             */
/*   Updated: 2026/01/23 18:57:30 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <cstddef>
#include <iostream>
#include <cstdlib> 

template <typename T>
class Array {
private:
	T* _array;
	unsigned int _length;

public:
	Array();
	Array(unsigned int n);
	Array(const Array& other);
	Array& operator=(const Array& other);
	~Array();

	T& operator[](unsigned int index);
	const T& operator[](unsigned int index) const;
	unsigned int size() const;
};

#include "Array.tpp"

#endif