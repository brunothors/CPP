#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <exception>
#include <iostream>
#include <ostream>

class Form {
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_executeGrade;
	public:
		Form();
		Form(const std::string &name, const int &signGrade, const int &executeGrade);
		Form(const Form &param);
		~Form();

		Form &operator=(const Form &param);

		const std::string	&getName(void) const;
		bool				getIsSigned(void) const;
		const int			&getSignGrade(void) const;
		const int			&getExecuteGrade(void) const;

		void				beSigned(const Bureaucrat &param);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &oS, Form const &param);

#endif