/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:29:12 by bnespoli          #+#    #+#             */
/*   Updated: 2026/01/20 17:29:54 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

# include "AForm.hpp"

class	RobotomyRequestForm : public AForm {

private:
	RobotomyRequestForm(void);

	std::string	_target;

public:
	~RobotomyRequestForm(void);
	RobotomyRequestForm(std::string const &target);
	RobotomyRequestForm(RobotomyRequestForm const &param);

	RobotomyRequestForm	&operator=(RobotomyRequestForm const &param);

	void	execute(Bureaucrat const &executor) const;
};

#endif