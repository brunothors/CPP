/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 22:14:37 by bnespoli          #+#    #+#             */
/*   Updated: 2025/06/16 18:51:30 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(){}

Contact::Contact(std::string firstName, std::string lastName, std::string nickname, std::string phone, std::string darkestSecret) {
    _firstName = firstName;
    _lastName = lastName;
    _nickname = nickname;
    _phone = phone;
    _darkestSecret = darkestSecret;
    std::cout << "Contact created" << std::endl;
}

Contact::~Contact(){}

static void truncateInfo(std::string info) {
    int length = info.size();

    if (length > 10) {
        for (int i = 0; i < 10; i++) {
            if (i == 9) {
                std::cout << ".";
                return ;
            }
            std::cout << info[i];
        }
    } else {
        std::cout << std::right;
        for (int i = 0; i < 10 - length; i++)
            std::cout << " ";
        std::cout << info;
    }
}

void Contact::showPreInfo() {
    std::cout << "|";
    truncateInfo(_firstName);
    std::cout << "|";
    truncateInfo(_lastName);
    std::cout << "|";
    truncateInfo(_nickname);
    std::cout << "|" << std::endl;
}

void Contact::displayInfo() {
    std::cout << "First name: " << _firstName << std::endl;
    std::cout << "Last name: " << _lastName << std::endl;
    std::cout << "Nickname: " << _nickname << std::endl;
    std::cout << "Phone: " << _phone << std::endl;
    std::cout << "Darkest secret: " << _darkestSecret << std::endl;
}
