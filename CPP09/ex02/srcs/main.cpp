/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 19:31:04 by bnespoli          #+#    #+#             */
/*   Updated: 2026/01/25 19:31:09 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cerr << "Error" << std::endl;
		return 1;
	}
	
	try {
		PmergeMe sorter;
		clock_t start = clock();
		sorter.processInput(argv);
		if (!sorter.validateInput()) {
			throw std::invalid_argument("Error");
		}
		clock_t end = clock();
		sorter.printContainers(end - start);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}