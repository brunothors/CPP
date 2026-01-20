/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:14:11 by bnespoli          #+#    #+#             */
/*   Updated: 2026/01/20 17:14:28 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

# include "AForm.hpp"

class	PresidentialPardonForm : public AForm {

private:
	PresidentialPardonForm(void);

	std::string	_target;

public:
	~PresidentialPardonForm(void);
	PresidentialPardonForm(std::string const &target);
	PresidentialPardonForm(PresidentialPardonForm const &param);

	PresidentialPardonForm	&operator=(PresidentialPardonForm const &param);

	void	execute(Bureaucrat const &executor) const;
};

#endif