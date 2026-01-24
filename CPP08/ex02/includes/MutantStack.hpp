#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <vector>

template <typename T>
class MutantStack: public std::stack<T> {
	public:
		MutantStack();
		MutantStack(const MutantStack& rhs);
		MutantStack& operator=(const MutantStack& rhs);
		~MutantStack();

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin();
		iterator end();
};

#include "MutantStack.tpp"

#endif