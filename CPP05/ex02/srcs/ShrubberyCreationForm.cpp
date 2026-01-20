/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 18:30:05 by bnespoli          #+#    #+#             */
/*   Updated: 2026/01/20 18:51:22 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137), _target("default") {
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& param) : AForm("ShrubberyCreationForm", 145, 137), _target(param._target) {
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	*this = param;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
	std::cout << "ShrubberyCreationForm parameterized constructor called" << std::endl;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& param) {
	if (this != &param) {
		AForm::operator=(param);
		_target = param._target;
	}
	return (*this);
}

const char*	ShrubberyCreationForm::FileWriteException::what() const throw() {
	return ("ShrubberyCreationForm: Failed to write to file");
}

const char*	ShrubberyCreationForm::FailedToOpenException::what() const throw() {
	return ("ShrubberyCreationForm: Failed to open file");
}

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	if (!getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > getExecuteGrade())
		throw AForm::GradeTooLowException();
	std::string	filename = _target + "_shrubbery";
	std::ofstream	outFile(filename.c_str());
	if (!outFile.is_open()) {
    	throw FailedToOpenException();
	}
	outFile << "       _-_" << std::endl;
	outFile << "    /~~   ~~\\" << std::endl;
	outFile << " /~~         ~~\\" << std::endl;
	outFile << "{               }" << std::endl;
	outFile << " \\  _-     -_  /" << std::endl;
	outFile << "   ~  \\\\ //  ~" << std::endl;
	outFile << "_- -   | | _- _" << std::endl;
	outFile << "  _ -  | |   -_" << std::endl;
	outFile << "      // \\\\" << std::endl;
	if (outFile.fail()) {
    	throw FileWriteException();
	}
	outFile.close();
}