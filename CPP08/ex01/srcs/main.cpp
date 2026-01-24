/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 14:38:17 by bnespoli          #+#    #+#             */
/*   Updated: 2026/01/24 14:38:18 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// int main() {
// 	Span sp = Span(5);

// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);

// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;

// 	return 0;
// }

int main() {
	try {
		Span largeSpan(10000);
		std::vector<int> vec(10000);

		srand(time(NULL));
		std::generate(vec.begin(), vec.end(), std::rand);
		largeSpan.addRange(vec.begin(), vec.end());

		std::cout << largeSpan.shortestSpan() << std::endl;
		std::cout << largeSpan.longestSpan() << std::endl;

	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;;
	}

	return 0;
}