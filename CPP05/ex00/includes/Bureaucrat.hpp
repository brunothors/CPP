/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 12:19:11 by bnespoli          #+#    #+#             */
/*   Updated: 2026/01/18 12:19:14 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BEREAUCRAT_HPP
#define BEREAUCRAT_HPP

#include <string>
#include <exception>
#include <iostream>
#include <ostream>

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