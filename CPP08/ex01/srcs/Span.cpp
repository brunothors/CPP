#include "Span.hpp"

Span::Span() : _size(0) {}

Span::Span(unsigned int n) : _size(n) {}

Span::Span(const Span& rhs) {
	*this = rhs;
}

Span::~Span() {}

Span& Span::operator=(const Span& rhs) {
	if (this != &rhs) {
		for (unsigned long i = 0; i < rhs._size; i++)
			this->_numbers[i] = rhs._numbers[i];
		this->_size = rhs._size;
	}
	return *this;
}

std::vector<int> Span::getNumber() {
	return this->_numbers;
}

void Span::addNumber(int n) {
	if (_numbers.size() >= _size)
		throw AddFail();
	_numbers.push_back(n);
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (_numbers.size() + std::distance(begin, end) > _size)
		throw AddFail();
	_numbers.insert(_numbers.end(), begin, end);
}

int Span::shortestSpan() {
	if (_numbers.size() < 2)
		throw ShortFail();

	std::vector<int> temp = _numbers;
	std::sort(temp.begin(), temp.end());

	int min_span = temp[1] - temp[0];
	for (size_t i = 1; i < temp.size() - 1; ++i)
		min_span = std::min(min_span, temp[i + 1] - temp[i]);

	return min_span;
}

int Span::longestSpan() {
	if (_numbers.size() < 2)
		throw LongFail();

	int max_span = *std::max_element(_numbers.begin(), _numbers.end()) - *std::min_element(_numbers.begin(), _numbers.end());
	return max_span;
}