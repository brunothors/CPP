#include "Form.hpp"
#include <iostream>
#include <ostream>

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {
	std::cout << "Bureaucrat Default constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat Destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &name, int const &grade) :	_name(name), _grade(150) {
	std::cout << "Bureaucrat " << getName() << " constructor called" << std::endl;
	if (grade < 1) {
		throw Bureaucrat::GradeTooHighException();
	} else if (grade > 150) {
		throw Bureaucrat::GradeTooLowException();
	} else {
		_grade = grade;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &param) : _name(param.getName()), _grade(param.getGrade()) {
	std::cout << "Bureaucrat " << getName() << " copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &param) {
	if (this != &param) {
		const_cast<std::string&>(_name) = param.getName();
		_grade = param.getGrade();
	}
	return *this;
}

const std::string	&Bureaucrat::getName(void) const {
	return _name;
}

const int	&Bureaucrat::getGrade(void) const {
	return _grade;
}

void	Bureaucrat::setGrade(int const &grade) {
	if (grade < 1) {
		throw Bureaucrat::GradeTooHighException();
	} else if (grade > 150) {
		throw Bureaucrat::GradeTooLowException();
	} else {
		_grade = grade;
	}
}

void	Bureaucrat::incrementGrade() {
	if (_grade - 1 < 1) {
		throw Bureaucrat::GradeTooHighException();
	} else {
		_grade--;
	}
}

void	Bureaucrat::decrementGrade() {
	if (_grade + 1 > 150) {
		throw Bureaucrat::GradeTooLowException();
	} else {
		_grade++;
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Bureaucrat Exception: Grade Too High";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Bureaucrat Exception: Grade Too Low";
}

void	Bureaucrat::signForm(Form &param) {
	try {
		param.beSigned(*this);
		std::cout << getName() << " signed " << param.getName() << std::endl;
	} catch (Form::GradeTooLowException &e) {
		std::cout << getName() << " couldn't sign " << param.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &oS, const Bureaucrat &param) {
	oS << "Bureaucrat: " << param.getName() << ", Grade: " << param.getGrade() << std::endl;
	return oS;
}