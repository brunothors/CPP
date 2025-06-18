/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 20:22:27 by bnespoli          #+#    #+#             */
/*   Updated: 2025/06/17 21:03:15 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: ./replace <filename> <string_to_replace> <replacement_string>" << std::endl;
		return 1;
	}
	std::string s1(argv[2]);
	std::string s2(argv[3]);
	std::stringstream filename;
	filename << argv[1] << ".replace";
	std::ifstream inputFile(argv[1]);
	if (!inputFile.is_open())
	{
		std::cerr << "Error: Could not open file " << argv[1] << std::endl;
		return 1;
	}
	std::ofstream outputFile(filename.str().c_str());
	if (!outputFile.is_open())
	{
		std::cerr << "Error: Could not create file " << filename.str() << std::endl;
		return 1;
	}
	std::string line;
	while (std::getline(inputFile, line))
	{
		size_t pos = 0;
		size_t found = 0;
		while ((pos = line.find(s1, found)) != std::string::npos)
		{
			outputFile << line.substr(found, pos - found) << s2;
			found = pos + s1.length();
		}
		outputFile << line.substr(found) << std::endl;
	}
	inputFile.close();
	outputFile.close();
	return 0;
}