/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 12:20:18 by bnespoli          #+#    #+#             */
/*   Updated: 2026/01/21 18:17:16 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    Intern Raze;
	Bureaucrat John("John", 1);
    AForm* form1 = Raze.makeForm("shrubbery creation", "Skye");
	John.signForm(*form1);
	John.executeForm(*form1);
    AForm* form2 = Raze.makeForm("robotomy request", "Kayo");
	John.signForm(*form2);
	John.executeForm(*form2);
    AForm* form3 = Raze.makeForm("presidential pardon", "Omen");
	John.signForm(*form3);
	John.executeForm(*form3);
    AForm* form4 = Raze.makeForm("Unknown form", "Reyna");

    delete form1;
    delete form2;
    delete form3;
    delete form4;

    return (0);
}