/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 17:55:15 by bnespoli          #+#    #+#             */
/*   Updated: 2026/01/23 17:55:41 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template<typename T>
void swap(T &a, T &b) {
	T aux = a;
	a = b;
	b = aux;
}

template<typename T>
T min(T a, T b) {
	if (a < b)
		return (a);
	return (b);
}

template<typename T>
T max(T a, T b) {
	if (a > b)
		return (a);
	return (b);
}

#endif