/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 20:19:31 by bnespoli          #+#    #+#             */
/*   Updated: 2025/06/16 18:51:42 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <iostream>

class Contact {
	private:
		std::string _firstName;
        std::string _lastName;
        std::string _nickname;
        std::string _phone;
        std::string _darkestSecret;
	
	public:
		Contact();
		Contact(std::string firstName, std::string lastName, std::string nickname, std::string phone, std::string darkestSecret);
		~Contact();

		void	showPreInfo();
		void	displayInfo();
};

#endif