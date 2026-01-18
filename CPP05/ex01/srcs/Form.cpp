#include "Form.hpp"

Form::Form() : _name("Default"), _isSigned(false), _signGrade(150), _executeGrade(150) {
	std::cout << "Form Default constructor called" << std::endl;
}

Form::~Form() {
	std::cout << "Form Destructor called" << std::endl;
}

Form::Form(const std::string &name, const int &signGrade, const int &executeGrade)
	: _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade) {
	std::cout << "Form " << getName() << " constructor called" << std::endl;
	if (signGrade < 1 || executeGrade < 1) {
		throw Form::GradeTooHighException();
	} else if (signGrade > 150 || executeGrade > 150) {
		throw Form::GradeTooLowException();
	}
}

Form::Form(const Form &param)
	: _name(param.getName()), _isSigned(param.getIsSigned()),
	  _signGrade(param.getSignGrade()), _executeGrade(param.getExecuteGrade()) {
	std::cout << "Form " << getName() << " copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &param) {
	if (this != &param) {
		const_cast<std::string&>(_name) = param.getName();
		_isSigned = param.getIsSigned();
		const_cast<int&>(_signGrade) = param.getSignGrade();
		const_cast<int&>(_executeGrade) = param.getExecuteGrade();
	}
	return *this;
}

const std::string	&Form::getName(void) const {
	return _name;
}

bool	Form::getIsSigned(void) const {
	return _isSigned;
}

const int	&Form::getSignGrade(void) const {
	return _signGrade;
}

const int	&Form::getExecuteGrade(void) const {
	return _executeGrade;
}

void	Form::beSigned(const Bureaucrat &param) {
	if (param.getGrade() > getSignGrade()) {
		throw Form::GradeTooLowException();
	} else {
		_isSigned = true;
	}
}

const char *Form::GradeTooHighException::what() const throw() {
	return "Form Exception: Grade Too High";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Form Exception: Grade Too Low";
}

std::ostream &operator<<(std::ostream &oS, const Form &param) {
	oS << "Form: " << param.getName()
	   << ", Signed: " << (param.getIsSigned() ? "Yes" : "No")
	   << ", Sign Grade: " << param.getSignGrade()
	   << ", Execute Grade: " << param.getExecuteGrade() << std::endl;
	return oS;
}