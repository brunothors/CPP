/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 23:02:13 by bnespoli          #+#    #+#             */
/*   Updated: 2025/06/14 23:49:16 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void) {
    std::string prompt = "";
    PhoneBook phonebook = PhoneBook();

    while (true) {
        std::cout << "Enter command: ";
        std::cin >> prompt;
        std::cout << std::endl;
        if (prompt == "ADD")
            phonebook.addContact();
        else if (prompt == "SEARCH")
            phonebook.searchContact();
        else if (prompt == "EXIT")
            break;
        else
        std::cout << "Invalid command: " << prompt << std::endl;
    }
}