/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 12:20:15 by bnespoli          #+#    #+#             */
/*   Updated: 2026/01/20 17:41:24 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Default"), _isSigned(false), _signGrade(150), _executeGrade(150) {
	std::cout << "Form Default constructor called" << std::endl;
}

AForm::~AForm() {
	std::cout << "Form Destructor called" << std::endl;
}

AForm::AForm(const std::string &name, const int &signGrade, const int &executeGrade)
	: _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade) {
	if (signGrade < 1 || executeGrade < 1) {
		throw AForm::GradeTooHighException();
	} else if (signGrade > 150 || executeGrade > 150) {
		throw AForm::GradeTooLowException();
	std::cout << "Form " << getName() << " constructor called" << std::endl;
	}
}

AForm::AForm(const AForm &param)
	: _name(param.getName()), _isSigned(param.getIsSigned()),
	  _signGrade(param.getSignGrade()), _executeGrade(param.getExecuteGrade()) {
	std::cout << "AForm " << getName() << " copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &param) {
	if (this != &param) {
		const_cast<std::string&>(_name) = param.getName();
		_isSigned = param.getIsSigned();
		const_cast<int&>(_signGrade) = param.getSignGrade();
		const_cast<int&>(_executeGrade) = param.getExecuteGrade();
	}
	return *this;
}

const std::string	&AForm::getName(void) const {
	return _name;
}

bool	AForm::getIsSigned(void) const {
	return _isSigned;
}

const int	&AForm::getSignGrade(void) const {
	return _signGrade;
}

const int	&AForm::getExecuteGrade(void) const {
	return _executeGrade;
}

void	AForm::beSigned(const Bureaucrat &param) {
	if (param.getGrade() > getSignGrade()) {
		throw AForm::GradeTooLowException();
	} else {
		_isSigned = true;
	}
}

const char *AForm::GradeTooHighException::what() const throw() {
	return "AForm Exception: Grade Too High";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "AForm Exception: Grade Too Low";
}

const char *AForm::FormNotSignedException::what() const throw() {
	return "AForm Exception: Form Not Signed";
}

std::ostream &operator<<(std::ostream &oS, const AForm &param) {
	oS << "Form: " << param.getName()
	   << ", Signed: " << (param.getIsSigned() ? "Yes" : "No")
	   << ", Sign Grade: " << param.getSignGrade()
	   << ", Execute Grade: " << param.getExecuteGrade() << std::endl;
	return oS;
}