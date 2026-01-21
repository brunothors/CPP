/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 12:20:08 by bnespoli          #+#    #+#             */
/*   Updated: 2026/01/20 17:28:37 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <exception>
#include <iostream>
#include <ostream>

class AForm {
	private:
		AForm();
		
		const std::string	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_executeGrade;
	public:
		AForm(const std::string &name, const int &signGrade, const int &executeGrade);
		AForm(const AForm &param);
		virtual ~AForm();

		AForm &operator=(const AForm &param);

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

		class FormNotSignedException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		virtual void		execute(Bureaucrat const & executor) const = 0;
};

std::ostream &operator<<(std::ostream &oS, AForm const &param);

#endif