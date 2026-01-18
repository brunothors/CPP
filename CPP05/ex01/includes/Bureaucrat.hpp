#ifndef BEREAUCRAT_HPP
#define BEREAUCRAT_HPP

#include <string>
#include <exception>
#include <iostream>
#include <ostream>

class Form;

class Bureaucrat {
	private:
		const std::string	_name;
		int					_grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string &name, int const &grade);
		Bureaucrat(const Bureaucrat &param);
		~Bureaucrat();

		Bureaucrat &operator=(const Bureaucrat &param);

		const std::string	&getName(void) const;
		const int			&getGrade(void) const;
		void				setGrade(int const &grade);

		void incrementGrade();
		void decrementGrade();

		void				signForm(Form &param);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &oS, Bureaucrat const &param);

#endif