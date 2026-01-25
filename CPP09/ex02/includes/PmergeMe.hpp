/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 19:30:09 by bnespoli          #+#    #+#             */
/*   Updated: 2026/01/25 19:30:17 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <exception>
#include <iterator>

class PmergeMe {
	private:
		std::vector<int> _intV;
		std::deque<int> _intD;
		int _straggler;

	public:
		bool has_straggler;

		PmergeMe();
		PmergeMe(const PmergeMe& rhs);
		PmergeMe& operator=(const PmergeMe& rhs);
		~PmergeMe();

		void processInput(char **argv);
		bool validateInput();
		void printContainers(clock_t dataManageTime);
		int catchVecStraggler(std::vector<int> &vec);
		int catchDeqStraggler(std::deque<int> &deq);
		std::vector<int> fordSortVec();
		std::deque<int> fordSortDeq();
	}
;

# endif