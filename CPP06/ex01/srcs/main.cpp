/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:16:54 by bnespoli          #+#    #+#             */
/*   Updated: 2026/01/22 18:17:45 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {
	Data* data = new Data();
	data->setData(42);

    std::cout << "----------xx----------xx----------xx----------" << std::endl;

	uintptr_t dataSerial = Serializer::serialize(data);
	Data* deserial = Serializer::deserialize(dataSerial);
	uintptr_t deserialSerial = Serializer::serialize(deserial);

	std::cout << "Data:     " << data->getData() << std::endl;
	std::cout << "Deserial: " << deserial->getData() << std::endl;
	std::cout << "Data adress:     " << data << std::endl;
	std::cout << "Deserial adress: " << deserial << std::endl;


	std::cout << "Data serial:     " << dataSerial << std::endl;
	std::cout << "Deserial serial: " << deserialSerial << std::endl;

    std::cout << "----------xx----------xx----------xx----------" << std::endl;

	delete data;

	return (0);
}