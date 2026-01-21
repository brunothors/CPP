/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:12:18 by bnespoli          #+#    #+#             */
/*   Updated: 2026/01/21 18:08:33 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {
	std::cout << "Default Intern created" << std::endl;
}

Intern::Intern(const Intern &param) {
	*this = param;
	std::cout << "Intern copied" << std::endl;
}

Intern::~Intern() {
	std::cout << "Intern destroyed" << std::endl;
}

Intern &Intern::operator=(const Intern &param) {
	(void)param;
	return *this;
}

AForm	*Intern::makeForm(const std::string &formName, const std::string &target) {
    std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	for (int i = 0; i < 3; i++) {
        if (formName == forms[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            switch (i) {
                case 0:
                    return (new ShrubberyCreationForm(target));
                case 1:
                    return (new RobotomyRequestForm(target));
                case 2:
                    return (new PresidentialPardonForm(target));
            }
        }
    }
    std::cout << "Unknown form for interns." << std::endl;
	
	return 0;
}