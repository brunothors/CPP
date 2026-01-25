/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 19:30:32 by bnespoli          #+#    #+#             */
/*   Updated: 2026/01/25 19:30:55 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _intV(), _intD(), _straggler(0), has_straggler(false) {}

PmergeMe::PmergeMe(const PmergeMe& rhs) {
	*this = rhs;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs) {
	if (this != &rhs) {
		_intV = rhs._intV;
		_intD = rhs._intD;
		_straggler = rhs._straggler;
		has_straggler = rhs.has_straggler;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::processInput(char **argv) {
	for (int i = 1; argv[i]; i++) {
		std::istringstream iss(argv[i]);
		int num;
		if (!(iss >> num) || num < 0)
			throw std::invalid_argument("Error");
		_intV.push_back(num);
		_intD.push_back(num);
	}
}

bool PmergeMe::validateInput() {
	return !_intV.empty();
}

int PmergeMe::catchVecStraggler(std::vector<int> &vec) {
	if (vec.size() % 2 != 0) {
		int last = vec.back();
		vec.pop_back();
		has_straggler = true;
		return last;
	}
	return 0;
}

int PmergeMe::catchDeqStraggler(std::deque<int> &deq) {
	if (deq.size() % 2 != 0) {
		int last = deq.back();
		deq.pop_back();
		has_straggler = true;
		return last;
	}
	return 0;
}

std::vector<int> PmergeMe::fordSortVec() {
	std::vector<int> result = _intV;
	std::sort(result.begin(), result.end());
	if (has_straggler) result.push_back(_straggler);
	return result;
}

std::deque<int> PmergeMe::fordSortDeq() {
	std::deque<int> result = _intD;
	std::sort(result.begin(), result.end());
	if (has_straggler) result.push_back(_straggler);
	return result;
}

void PmergeMe::printContainers(clock_t dataManageTime) {
	clock_t start, end;

	std::cout << "Before: ";
	std::copy(_intV.begin(), _intV.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	start = clock();
	std::vector<int> sortedVec = fordSortVec();
	end = clock();
	std::cout << "After: ";
	std::copy(sortedVec.begin(), sortedVec.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	std::cout << "Time to process a range of " << sortedVec.size() << " elements with std::vector: " << ((end - start) + dataManageTime) << " us" << std::endl;

	start = clock();
	std::deque<int> sortedDeq = fordSortDeq();
	end = clock();
	std::cout << "Time to process a range of " << sortedDeq.size() << " elements with std::deque: " << ((end - start) + dataManageTime) << " us" << std::endl;
}