/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 12:20:18 by bnespoli          #+#    #+#             */
/*   Updated: 2026/01/20 18:56:36 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

int main() {
    ShrubberyCreationForm shrubberyForm("Skye");
    RobotomyRequestForm robotomyForm("Kayo");
    PresidentialPardonForm pardonForm("Omen");

    std::cout << "----------xx----------xx----------xx----------" << std::endl;

    Bureaucrat bureaucrat1("Killjoy", 1);
    Bureaucrat bureaucrat2("Viper", 150);

    std::cout << "----------xx----------xx----------xx----------" << std::endl;

    try {
        bureaucrat1.signForm(shrubberyForm);
        bureaucrat1.executeForm(shrubberyForm);

        std::cout << "----------xx----------xx----------xx----------" << std::endl;

        bureaucrat1.signForm(robotomyForm);
        bureaucrat1.executeForm(robotomyForm);

        std::cout << "----------xx----------xx----------xx----------" << std::endl;

        bureaucrat1.signForm(pardonForm);
        bureaucrat1.executeForm(pardonForm);

        std::cout << "----------xx----------xx----------xx----------" << std::endl;

        bureaucrat2.signForm(shrubberyForm);
        bureaucrat2.executeForm(shrubberyForm);
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "----------xx----------xx----------xx----------" << std::endl;

    return (0);
}