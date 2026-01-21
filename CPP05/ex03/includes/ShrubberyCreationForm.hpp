/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:33:05 by bnespoli          #+#    #+#             */
/*   Updated: 2026/01/20 18:31:12 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

# include "AForm.hpp"
# include <fstream>

class	ShrubberyCreationForm : public AForm {

private:
	ShrubberyCreationForm(void);

	std::string	_target;

public:
	~ShrubberyCreationForm(void);
	ShrubberyCreationForm(std::string const &target);
	ShrubberyCreationForm(ShrubberyCreationForm const &param);

	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &param);

	void	execute(Bureaucrat const &executor) const;

	class FileWriteException : public std::exception {
    	public:
        	const char *what() const throw();
    };

    class FailedToOpenException : public std::exception {
	    public:
    	    const char *what() const throw();
	};
};

#endif