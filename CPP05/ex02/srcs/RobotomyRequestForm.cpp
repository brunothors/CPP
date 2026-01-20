/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 18:09:53 by bnespoli          #+#    #+#             */
/*   Updated: 2026/01/20 18:26:39 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("Default") {
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)	: AForm("RobotomyRequestForm", 72, 45), _target(target) {
	std::cout << "RobotomyRequestForm parameterized constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& param)	: AForm("RobotomyRequestForm", 72, 45), _target(param._target) {
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	*this = param;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm& param) {
	if (this != &param) {
		AForm::operator=(param);
		_target = param._target;
	}
	return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	if (!getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > getExecuteGrade())
		throw AForm::GradeTooLowException();
	std::cout << "Brrrr... Brrrr... Brrrr..." << std::endl;
	std::srand(time(NULL));
	if (std::rand() % 2)
		std::cout << _target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "The robotomy failed on " << _target << "." << std::endl;
}