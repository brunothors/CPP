/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:09:02 by bnespoli          #+#    #+#             */
/*   Updated: 2026/01/21 18:07:40 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"


class Intern {
	public:
		Intern();
		Intern(const Intern &param);
		~Intern();

		Intern &operator=(const Intern &param);

		AForm	*makeForm(const std::string &formName, const std::string &target);
};

#endif