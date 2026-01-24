#include "easyfind.hpp"
#include <vector>
#include <list>

int main() {
	try {
		std::vector<int> vec;
		std::cout << "Creating vector: " << std::endl;
		for (int i = 0; i < 5; i++) {
			vec.push_back(i);
			std::cout << i;
			if (i != 4)
				std::cout << ", ";
			else
				std::cout << std::endl;
		}

		std::cout << "Searching for 3 in vector" << std::endl;
		std::cout << "Found: " << easyfind(vec, 3) << std::endl;

		std::cout << "........................." << std::endl;

		std::list<int> lst;
		std::cout << "Creating list: " << std::endl;
		for (int i = 0; i < 5; i++) {
			lst.push_back(i);
			std::cout << i;
			if (i != 4)
				std::cout << ", ";
			else
				std::cout << std::endl;
		}

		std::cout << "Searching for 0 in list" << std::endl;
		std::cout << "Found: " << easyfind(lst, 0) << std::endl;

		std::cout << "Searching for 5 in list" << std::endl;
		std::cout << easyfind(lst, 5) << std::endl;

	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}